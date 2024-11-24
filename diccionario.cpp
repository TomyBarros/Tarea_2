#include "diccionario.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream> 

ArbolTrie::ArbolTrie() : FinPalabra(false), traducciones("") {
    for (int i = 0; i < letras; i++) {
        HijosNodo[i] = nullptr;
    }
}


Trie::Trie() {
    raiz = new ArbolTrie();
}


Trie::~Trie() {
    borrar_nodo(raiz);
}


void Trie::agregar_palabra(const std::string& palabra, const std::string& traduccion) {
    ArbolTrie* nodo = raiz;
    for (char c : palabra) {
        int index = c - 'a';
        if (!nodo->HijosNodo[index]) {
            nodo->HijosNodo[index] = new ArbolTrie();
        }
        nodo = nodo->HijosNodo[index];
    }
    nodo->FinPalabra= true;

    if (!nodo->traducciones.empty()) {
        nodo->traducciones += ",";
    }
    nodo->traducciones += traduccion;
    nodo->traducciones = ordenatelordeno(nodo->traducciones); //Aquí se llama a la funcion nueva
}


std::string Trie::buscar_palabra(const std::string& palabra) {
    ArbolTrie* nodo = raiz;
    for (char c : palabra) {
        int index = c - 'a';
        if (!nodo->HijosNodo[index]) {
            return "No se encontro traducción";
        }
        nodo = nodo->HijosNodo[index];
    }
    if (nodo != nullptr and nodo->FinPalabra) {
        return nodo->traducciones;
    }
    return "No se encontro traducción";
}


void Trie::borrar_nodo(struct ArbolTrie* nodo) {
    for (int i = 0; i < letras; i++) {
        if (nodo->HijosNodo[i]) {
            borrar_nodo(nodo->HijosNodo[i]);
        }
    }
    delete nodo;
}


std::string Trie::ordenatelordeno(const std::string& traducciones) {

    std::vector<std::string> vectorTraducciones;
    std::stringstream Traducciones(traducciones);
    std::string guardado;

    while (getline(Traducciones, guardado, ',')) {
        if (!guardado.empty()) {
            vectorTraducciones.push_back(guardado);
        }
    }
    std::sort(vectorTraducciones.begin(), vectorTraducciones.end());
    std::string traduccionesOrdenadas;
    for (int i = 0; i < vectorTraducciones.size(); ++i) {
        if (i > 0) traduccionesOrdenadas += ",";
        traduccionesOrdenadas += vectorTraducciones[i];
    }
    return traduccionesOrdenadas;
}

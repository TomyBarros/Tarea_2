//Copia
//diccionario.h (no sirve este)
#ifndef TRIE_H
#define TRIE_H
#include <string>

const int letras = 26;  // Asumiendo letras a-z

struct ArbolTrie {
    struct ArbolTrie* children[letras];
    bool FinPalabra;
    char* traducciones;  // Almacenar traducciones separadas por comas

    ArbolTrie();  // Constructor para inicializar el nodo
};

class Trie {
public:
    Trie();
    ~Trie();

    int agregar_palabra(const char* palabra, char* traduccion);
    char* buscar_palabra(const char* palabra);

private:
    ArbolTrie* raiz;
    void borrar_nodo(struct ArbolTrie* nodo);
};

#endif  // TRIE_H





//diccionario.cpp (tampoco sirve este)
#include "diccionario.h"
#include <iostream>
#include <cstring>
#include <cstddef>

ArbolTrie::ArbolTrie() : FinPalabra(false), traducciones("") {
    for (int i = 0; i < letras; i++) {
        children[i] = nullptr;
    }
}
Trie::Trie() {
    raiz = new ArbolTrie();
}

Trie::~Trie() {
    borrar_nodo(raiz);
}

int Trie::agregar_palabra(const char* palabra, char* traduccion) {
    ArbolTrie* nodo = raiz;
    for (int i = 0; palabra[i] != '\0'; ++i) {
        int index = palabra[i] - 'a';
        if (nodo->children[index] == nullptr) {
            nodo->children[index] = new ArbolTrie();
        }
        nodo = nodo->children[index];
    }
    nodo->FinPalabra = true;
    if (nodo->traducciones == nullptr) {
        nodo->traducciones = new char[strlen(traduccion) + 1];
        strcpy(nodo->traducciones, traduccion);
    } else {
        size_t currentLength = strlen(nodo->traducciones);
        size_t newLength = currentLength + strlen(traduccion) + 3;  // 2 for ", " and 1 for '\0'
        char* newTranslations = new char[newLength];
        strcpy(newTranslations, nodo->traducciones);
        strcat(newTranslations, ", ");
        strcat(newTranslations, traduccion);
        delete[] nodo->traducciones;
        nodo->traducciones = newTranslations;
    }
}

char* Trie::buscar_palabra(const char* palabra) {
    ArbolTrie* nodo = raiz;
    for (int i = 0; palabra[i] != '\0'; ++i) {  // Itera hasta el final de la cadena
        char c = palabra[i];  // Accede al carácter actual
        int index = c - 'a';  // Calcula el índice para el array de hijos
        if (!nodo->children[index]) {  // Verifica si el nodo hijo existe
            return "No tiene traducción";  // Retorna si no encuentra el nodo correspondiente
        }
        nodo = nodo->children[index];  // Avanza al siguiente nodo
    }

    if (nodo != nullptr && nodo->FinPalabra) {  // Verifica si es el final de una palabra
        return nodo->traducciones;  // Retorna las traducciones si es el final de la palabra
    }

    return "No tiene traducción";  // Retorna si no encuentra una palabra completa
}


void Trie::borrar_nodo(ArbolTrie* nodo) {
    for (int i = 0; i < letras; i++) {
        if (nodo->children[i]) {
            borrar_nodo(nodo->children[i]);
        }
    }
    delete nodo;
}
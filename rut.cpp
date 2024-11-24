#include "rut.h"
#include <iostream>


ArbolTrie::ArbolTrie() : FinRut(false), deudor(Deudor), name(""), dir(""), birthdate("") {
    for (int i = 0; i < num; i++) {
        HijosNodo[i] = nullptr;
    }
}
Trie::Trie() {
    raiz = new ArbolTrie();
}
Trie::~Trie() {
    borrar_nodo(raiz);
}

void Trie::agregar_rut(const std::string& rut, const std::string& name, const std::string& direccion, const std::string& birthdate) {
    ArbolTrie* nodo = raiz;
    for (char c : rut) {
        int index;
        if (c == 'k' or c == 'K') {
            index = 10;
        } else {
            index = c - '0';
        }

        if (!nodo->HijosNodo[index]) {
            nodo->HijosNodo[index] = new ArbolTrie();
        }
        nodo = nodo->HijosNodo[index];
    }

    nodo->FinRut= true;

    if (!nodo->name.empty()) {
        nodo->name = "";
    }
    nodo->name += name;
    if (!nodo->dir.empty()) {
        nodo->dir = "";
    }
    nodo->dir += direccion;
    if (!nodo->birthdate.empty()) {
        nodo->birthdate = "";
    }
    nodo->birthdate += birthdate;
}



std::string Trie::buscar_rut(const std::string& rut) {
    ArbolTrie* nodo = raiz;
    for (char c : rut) {
        int index;
        if (c == 'k' or c == 'K') {
            index = 10;
        } else {
            index = c - '0';
        }

        if (!nodo->HijosNodo[index]) {
            return "No se encontro usuario asociado al RUT";
        }
        nodo = nodo->HijosNodo[index];
    }
    if (nodo != nullptr and nodo->FinRut) {
        std::string info = "Nombre: " + nodo->name + "\n";
        info += "Dirección: " + nodo->dir + "\n";
        info += "Fecha de Nacimiento: " + nodo->birthdate + "\n";
        std::string deuda = (nodo->deudor == No_deudor) ? "No deudor" : "Deudor";
        info += "Estado de deuda: " + deuda + "\n";
        return info;
    }
    return "No se encontro usuario asociado al RUT";
}


void Trie::borrar_rut(const std::string& rut) {
    ArbolTrie* nodo = raiz;
    for (char c : rut) {
        int index;
        if (c == 'k' or c == 'K') {
            index = 10;
        } else {
            index = c - '0';
        }
        if (!nodo->HijosNodo[index]) {
            std::cout << "No se encontro usuario asociado al RUT";
            return;
        }
        nodo = nodo->HijosNodo[index];
    }

    if (nodo != nullptr and nodo->FinRut) {
        if (nodo_vacio(nodo) == true) {
            borrar_nodo(nodo);
            nodo->FinRut = false;
        } else {
            nodo->name="";
            nodo->dir="";
            nodo->birthdate="";
            nodo->FinRut = false;
        }
    } else {
        std::cout << "No se encontro usuario asociado al RUT";
        return;
    }
}


void Trie::numero_no_deudor(const std::string& rut)  {
    ArbolTrie* nodo = raiz;

    for (char c : rut) {
        int index;
        if (c == 'k' or c == 'K') {
            index = 10;
        } else {
            index = c - '0';
        }
        if (!nodo->HijosNodo[index]) {
            agregar_rut(rut, "", "", "");  // Agrega el RUT si no existe (no hay datos del usuario, asi que se agerga vacio)
            numero_no_deudor(rut);  // RUT agregado
            return;  // Sale del ciclo porque el trie ahora contiene el RUT completo
        }
        nodo = nodo->HijosNodo[index];
    }
    nodo->deudor=No_deudor;
}


void Trie::borrar_nodo(struct ArbolTrie* nodo) {
    for (int i = 0; i < num; i++) {
        if (nodo->HijosNodo[i]) {
            borrar_nodo(nodo->HijosNodo[i]);
        }
    }
    delete nodo;
}

bool Trie::nodo_vacio(struct ArbolTrie* nodo) {
    for (int i = 0; i < num; i++)
        if (nodo->HijosNodo[i])
            return false;
    return true;
}

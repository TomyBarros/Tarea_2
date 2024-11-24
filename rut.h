#ifndef Tarea2Tomy
#define Tarea2Tomy

#include <string>
const int num = 11;  // Rut tiene numeros del 0 al 9 y k => 11

enum Deudoroso {
    No_deudor,
    Deudor
};

struct ArbolTrie {
    struct ArbolTrie* HijosNodo[num]; // Puntero a los hijos (11 posibilidades)
    bool FinRut;// Indica si es el final del rut (verdadero) o no (falso)
    Deudoroso deudor; // Indica si es deudor o no
    std::string name; // Nombre del usuario
    std::string dir; // Direccion del usuario (la casa supongo)
    std::string birthdate; // Fecha de nacimiento

    ArbolTrie();  // Constructor para inicializar el nodo
};

class Trie {
public:
    Trie();
    ~Trie();

    void agregar_rut(const std::string& rut, const std::string& name, const std::string& direccion, const std::string& birthdate);
    std::string buscar_rut(const std::string& rut);
    void borrar_rut(const std::string& rut);
    void numero_no_deudor(const std::string& rut);

private:
    ArbolTrie* raiz;

    void borrar_nodo(struct ArbolTrie* nodo);
    bool nodo_vacio(struct ArbolTrie* nodo);
};

#endif 

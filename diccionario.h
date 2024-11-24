#ifndef Tarea2Tomy
#define Tarea2Tomy

#include <string>

#include <algorithm>
#include <vector>
#include <sstream>

const int letras = 26;  // Alfabeto ingles de 26 letras (a-z)

struct ArbolTrie {
    struct ArbolTrie* HijosNodo[letras]; // Puntero a los hijos
    bool FinPalabra; // Indica si es el final de una palabra (verdadero) o no (falso)
    std::string traducciones;  // Almacena traducciones

    ArbolTrie();  // Constructor para inicializar el nodo
};

class Trie {
public:
    Trie();
    ~Trie();

    void agregar_palabra(const std::string& palabra, const std::string& traduccion);
    std::string buscar_palabra(const std::string& palabra);

private:
    ArbolTrie* raiz;

    void borrar_nodo(struct ArbolTrie* nodo); // Libera memoria
    std::string ordenatelordeno(const std::string& traducciones);  // Funcion para ordenar
};

#endif 

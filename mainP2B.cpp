#include "diccionario.h"
#include <iostream>

int main() {
    Trie diccionario;

    // Insertar palabras y sus traducciones
    diccionario.agregar_palabra("like", "gustar");
    diccionario.agregar_palabra("like", "amar");
    diccionario.agregar_palabra("like", "como");

    // Probar las búsquedas
    std::cout << "Traducciones de 'like': " << diccionario.buscar_palabra("like") << std::endl;
    return 0;
}
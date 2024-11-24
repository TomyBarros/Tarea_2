#include "diccionario.h"
#include <iostream>
int main() {
    Trie diccionario;

    // Insertar palabras y sus traducciones
    diccionario.agregar_palabra("like", "amar");
    diccionario.agregar_palabra("like", "gustar");
    diccionario.agregar_palabra("egg", "huevo");
    diccionario.agregar_palabra("steak", "filete");
    diccionario.agregar_palabra("cheese", "queso");

    // Probar las búsquedas
    std::cout << "Traducción de 'like': " << diccionario.buscar_palabra("like") << std::endl;
    std::cout << "Traducción de 'egg': " << diccionario.buscar_palabra("egg") << std::endl;
    std::cout << "Traducción de 'steak': " << diccionario.buscar_palabra("steak") << std::endl;
    std::cout << "Traducción de 'cheese': " << diccionario.buscar_palabra("cheese") << std::endl;
    std::cout << "Traduccion de 'lion': " <<diccionario.buscar_palabra("lion") << std::endl;
    return 0;
}
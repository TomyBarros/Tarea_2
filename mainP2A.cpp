#include "rut.h"
#include <iostream>
int main() {
    Trie rut;

    // Insertar rut e info
    rut.agregar_rut("208168320", "Tomas Barros","Padre Hurtado","17/10/2001");
    rut.agregar_rut("20816832k", "Lionel Messi","Miami","24/06/1987");
    rut.agregar_rut("208168321", "Estoy odiando","C++","20/10/2024");

    // Probar las búsquedas
    std::cout << "Pruebas para agregar y buscar rut: \n"<< std::endl;
    std::cout << "RUT: 20.816.832-0: " << rut.buscar_rut("208168320") << std::endl;
    std::cout << "RUT: 20.816.832-k: " << rut.buscar_rut("20816832k") << std::endl;
    std::cout << "RUT: 20.816.832-1: " << rut.buscar_rut("208168321") << std::endl;
    std::cout << "RUT: 20.816.832-2 (no agregado):" << rut.buscar_rut("208168322") << std::endl;

    std::cout << " " << std::endl;
    std::cout << " " << std::endl;

    std::cout << "Pruebas para deuda y borrar (se usa un rut agregado yel rut no agregado:) \n"  << std::endl;
    rut.numero_no_deudor("208168320");
    rut.numero_no_deudor("208168322");
    rut.borrar_rut("208168321");
    std::cout << "Una vez usada la funcion, se llama a buscar rut nuevamente) \n" << std::endl;
    std::cout << "RUT: 20.816.832-0: " << rut.buscar_rut("208168320") << std::endl;
    std::cout << "RUT: 20.816.832-k: " << rut.buscar_rut("20816832k") << std::endl;
    std::cout << "RUT: 20.816.832-1 (usuario borrado): " << rut.buscar_rut("208168321") << std::endl;
    std::cout << "RUT: 20.816.832-2 (agregado con funcion numero_no_deudor):" << rut.buscar_rut("208168322") << std::endl;

    return 0;
}
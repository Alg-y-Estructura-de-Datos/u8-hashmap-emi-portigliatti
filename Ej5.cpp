/*
Biblioteca digital
 Objetivo: Gestionar una colección de libros usando un sistema de hash.
 ● Laclaveserá el ISBN del libro y el valor será el título del libro.
 ● Creafunciones para:
 ● Agregar nuevos libros a la biblioteca.
 ● Buscarunlibro por su ISBN.
 ● Eliminar libros del sistema.
 ● Imprimir todos los libros registrados.
 Desafíos:
 ● Implementar la resolución de colisiones.
 ● Verificar que no se repitan libros con el mismo ISBN
*/
#include <iostream>
#include <string>
#include "HashMap/HashMap.h"
using namespace std;

void menu()
{
    cout << "Menu" << endl;
    cout << "1) Agregar un nuevo libro" << endl;
    cout << "2) Buscar un libro por su ISBN" << endl;
    cout << "3) Eliminar un libro del sistema" << endl;
    cout << "4) Imprimir la lista completa de libros" << endl;
}

int main()
{

    HashMap<int, string> libros(10);
    int opc, isbn;
    string titulo;

    do
    {
        menu();
        cin >> opc;
        switch (opc)
        {
        case 1:
            cout << "Ingrese el titulo del nuevo libro: " << endl;
            cin >> titulo;
            cout << "Ingrese el ISBN del nuevo libro: " << endl;
            cin >> isbn;
            try
            {
                libros.put(isbn, titulo);
                cout << "Libro agregado correctamente" << endl;
            }
            catch (int e)
            {
                cout << "Error: el libro ya existe." << endl;
            }
            break;

        case 2:
            cout << "Ingrese el ISBN del libro a buscar: " << endl;
            cin >> isbn;
            try
            {
                cout << "Libro " << libros.get(isbn) << endl;
            }
            catch (int e)
            {
                cout << "Error: el libro no existe." << endl;
            }
            break;

        case 3:
            cout << "Ingrese el ISBN del libro a eliminar: " << endl;
            cin >> isbn;
            try
            {
                libros.remove(isbn);
                cout << "Libro eliminado correctamente" << endl;
            }
            catch (int e)
            {
                cout << "Error: el libro no existe." << endl;
            }
            break;

        case 4:
            cout << "Lista de libros:" << endl;
            libros.print();
            break;
        }
    } while (opc != 5);

    return 0;
}
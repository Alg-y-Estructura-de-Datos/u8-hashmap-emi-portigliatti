/*
Registro de productos en una tienda. Almacenar productos de una tienda usando un código
único como clave y el nombre del producto como valor. Usa el HashMap para almacenar los
productos. El código de producto es la clave y el nombre es el valor.
Implementa opciones para:
● Añadir productos.
● Buscar productos por su código.
● Actualizar el nombre de un producto existente.
● Eliminar productos.
● Imprimir todos los productos registrados.
● Desafío adicional: Implementa el manejo de colisiones, y lanza excepciones cuando se
intenten agregar productos con códigos ya existentes o buscar productos no
registrados.
*/

#include <iostream>
#include "HashMap/HashMap.h"
using namespace std;

void menu()
{

    cout << "Menu" << endl;
    cout << "1) Anadir productos" << endl;
    cout << "2) Buscar productos por su codigo" << endl;
    cout << "3) Actualizar el nombre de un producto existente" << endl;
    cout << "4) Eliminar productos" << endl;
    cout << "5) Imprimir todos los productos registrados" << endl;
    cout << "6) Salir" << endl;
}

int main()
{

    HashMap<int, string> productos(10);
    int opc, codigo;
    string nombre;

    do
    {
        menu();
        cin >> opc;
        switch (opc)
        {
        case 1:
            cout << "Codigo del producto nuevo: " << endl;
            cin >> codigo;
            cout << "Nombre del producto nuevo: " << endl;
            cin>> nombre;
            try
            {
                productos.put(codigo, nombre);
                cout << "Producto anadido correctamente" << endl;
            }
            catch (int e)
            {
                cout << "Error: el producto ya existe" << endl;
            }
            break;
        case 2:
            cout << "Codigo del producto a buscar: " << endl;
            cin >> codigo;
            try
            {
                cout << "Producto: " << productos.get(codigo) << endl;
            }
            catch (int e)
            {
                cout << "Error: producto no encontrado" << endl;
            }
            break;
        case 3:
            cout << "Codigo del producto a actualizar: " << endl;
            cin >> codigo;
            cout << "Nuevo nombre del producto: " << endl;
            nombre;
            try
            {
                productos.put(codigo, nombre);
                cout << "Producto actualizado correctamente" << endl;
            }
            catch (int e)
            {
                cout << "Error: producto no encontrado" << endl;
            }
            break;
        case 4:
            cout << "Codigo del producto a eliminar: " << endl;
            cin >> codigo;

            try
            {
                productos.remove(codigo);
                cout << "Codigo eliminado correctamente" << endl;
            }
            catch (int e)
            {
                cout << "Error: codigo no encontrado." << endl;
            }

            break;
        case 5:
            productos.print();
            break;
        case 6:
            cout << "Saliendo" << endl;
            break;
        default:
            cout << "Opcion invalida. Intentar de nuevo" << endl;
        }
    } while (opc != 6);
}
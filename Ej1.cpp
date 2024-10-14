/*
Simulación de un pequeño diccionario. Utilizaremos el HashMap para almacenar pares de
palabras (clave) y sus significados (valor).
El usuario podrá:
● Agregar nuevas palabras y sus significados.
● Buscar el significado de una palabra.
● Eliminar una palabra del diccionario.
● Ver todas las palabras en el diccionario.
*/
#include <iostream>
#include <string>
#include "HashMap/HashMap.h"
using namespace std;

void menu()
{
    cout << "Menu de opciones" << endl;
    cout << "1)Agregar nuevas palabras y sus significados" << endl;
    cout << "2)Buscar el significado de una palabra" << endl;
    cout << "3)Eliminar una palabra del diccionario" << endl;
    cout << "4)Ver todas las palabras del diccionario" << endl;
    cout << "5)Salir" << endl;
}

unsigned int hashString(string clave)
{
    unsigned int hash = 0;
    for (char c : clave)
    {
        hash += c;
    }
    return hash;
}

int main()
{

    unsigned int tamanoTabla = 10;
    HashMap<string, string> diccionario(tamanoTabla, hashString);

    int opc;
    string palabra, significado;

    do
    {
        menu();
        cin >> opc;
        switch (opc)
        {
        case 1:
            cout << "Ingrese la palabra: " << endl;
            cin >> palabra;
            cout << "Ingrese el significado: " << endl;
            cin.ignore();
            getline(cin, significado);
            diccionario.put(palabra, significado);
            cout << "Palabra agregada correctamente" << endl;
            break;
        case 2:
            cout << "Ingrese la palabra a buscar: " << endl;
            cin >> palabra;
            try
            {
                significado = diccionario.get(palabra);
                cout << "Significado de " << palabra << ": " << significado << endl;
            }
            catch (int e)
            {
                if (e == 404)
                {
                    cout << "La palabra no se encuentra en el diccionario" << endl;
                }
                else
                {
                    cout << "Error: Conflicto en la busquedad" << endl;
                }
            }
            break;

        case 3:
            cout << "Ingrese la palabra a eliminar: " << endl;
            cin >> palabra;
            diccionario.remove(palabra);
            cout << "Palabra eliminada correctamente (si existia)" << endl;
            break;

        case 4:
            cout << "Todas las palabras en el diccionario: " << endl;
            diccionario.print();
            break;
        case 5:
            cout << "Saliendo..." << endl;
            break;
        default:
            cout << "Opcion invalida. Intenta de nuevo." << endl;
        }
    } while (opc != 5);
}

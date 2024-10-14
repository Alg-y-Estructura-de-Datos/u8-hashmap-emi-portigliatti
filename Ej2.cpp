/*
Sistema de gestión de empleados. Usar HashMap para almacenar y gestionar empleados por
su número de identificación (ID).
● La clave será el número de identificación del empleado y el valor será su nombre.
● Implementa un menú con opciones para:
● Agregar un nuevo empleado.
● Buscar un empleado por su número de identificación.
● Eliminar un empleado del sistema.
● Imprimir la lista completa de empleados.
*/
#include <iostream>
#include <string>
#include "HashMap/HashMap.h"
using namespace std;

void menu()
{
    cout << "Menu" << endl;
    cout << "1) Agregar un nuevo empleado" << endl;
    cout << "2) Buscar un empleado por su numero de identificacion" << endl;
    cout << "3) Eliminar un empleado del sistema" << endl;
    cout << "4) Imprimir la lista completa de empleados" << endl;
}

int main()
{

    HashMap<int, string> empleados(10);
    int opc, id;
    string nombre;

    do
    {
        menu();
        cin >> opc;
        switch (opc)
        {
        case 1:
            cout << "Ingrese el nombre del nuevo empleado: " << endl;
            cin >> nombre;
            cout << "Ingrese el ID del nuevo empleado: " << endl;
            cin >> id;
            try
            {
                empleados.put(id, nombre);
                cout << "Empleado agregado correctamente" << endl;
            }
            catch (int e)
            {
                cout << "Error: el empleado ya existe." << endl;
            }
            break;

        case 2:
            cout << "Ingrese el ID del empleado a buscar: " << endl;
            cin >> id;
            try
            {
                cout << "Empleado " << empleados.get(id) << endl;
            }
            catch (int e)
            {
                cout << "Error: Empleado no encontrado" << endl;
            }
            break;

        case 3:
            cout << "Ingrese el ID del empleado que desea eliminar: " << endl;
            cin >> id;
            try
            {
                empleados.remove(id);
                cout << "El empleado con " << id << " eliminado correctamente." << endl;
            }
            catch (int e)
            {
                cout << "Error: empleado no encontrado." << endl;
            }
            break;
        case 4:
            empleados.print();
            break;
        case 5:
            cout << "Saliendo..." << endl;
            break;
        default:
            cout << "Opcion invalido. Intenta de nuevo." << endl;
        }
    } while (opc != 5);
}

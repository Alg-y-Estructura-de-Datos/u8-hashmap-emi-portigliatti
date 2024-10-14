/*
Sistema de votaciones
Objetivo: Crear un sistema de votaciones donde cada votante tiene un número de
identificación y vota por un candidato.
La clave será el número de identificación del votante y el valor será el nombre del candidato
por el que ha votado.
Implementa funciones para:
● Registrar un voto.
● Verificar por quién votó una persona (buscando por su ID).
● Eliminar un voto si fue incorrecto.
● Imprimir todos los votos registrados.
Puntos clave:
● Prevenir que un votante registre más de un voto.
● Mostrar un error si se intenta eliminar un voto no existente.
*/

#include <iostream>
#include <string>
#include "HashMap/HashMapList.h"
using namespace std;

void menu()
{
    cout << "Menu" << endl;
    cout << "1) Registrar un voto" << endl;
    cout << "2) Verificar por quien voto una persona" << endl;
    cout << "3) Eliminar un voto si fue incorrecto" << endl;
    cout << "4) Imprimir todos los votos registrados" << endl;
    cout << "5) Salir" << endl;
}

int main()
{
    HashMapList<int, string> votos(11);
    int opc, id;
    string candidato;

    do
    {
        menu();
        cin >> opc;
        switch (opc)
        {
        case 1:
            cout << "Ingrese Id del votante: " << endl;
            cin >> id;
            cout << "Ingrese nombre del candidato: " << endl;
            cin >> candidato;
            try
            {
                votos.put(id, candidato);
                cout << "Voto registrado correctamente." << endl;
            }
            catch (int e)
            {
                cout << "Error: colision al registrar el voto" << endl;
            }
            break;
        case 2:
            cout << "Ingrese ID del votante a buscar: " << endl;
            cin >> id;
            try
            {
                cout << "Voto: " << votos.get(id) << endl;
            }
            catch (int e)
            {
                cout << "Error: votante no encontrado" << endl;
            }
            break;
        case 3:
            cout << "Ingrese el ID del votante a eliminar: " << endl;
            cin >> id;
            try
            {
                votos.remove(id);
                cout << "Se elimino correctamente el ID del votante." << endl;
            }
            catch (int e)
            {
                cout << "Error: votante no encontrado." << endl;
            }
        case 4:
            votos.print();
            break;
        case 5:
            cout << "Saliendo" << endl;
            break;
        default:
            cout << "Opcion invalida. Intente de nuevo." << endl;
        }
    } while (opc != 5);
}
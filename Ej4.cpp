#include <iostream>
#include "HashMap/HashMapList.h"
using namespace std;

void menu()
{
    cout << "***Menu***" << endl;
    cout << "1.Agregar Voto" << endl;
    cout << "2.Buscar voto" << endl;
    cout << "3.Eliminar voto" << endl;
    cout << "4.Ver todos los votos" << endl;
    cout << "5.Salir" << endl;
}

unsigned int funcionDispersion(unsigned int clave)
{
    return clave;
}

int main()
{

    cout << "Ejercicio N° 4" << endl;

    string valor;
    unsigned int clave;
    unsigned int tamanioTabla = 10;
    HashMapList<unsigned int, string> votantes(tamanioTabla, funcionDispersion);

    int option;

    do
    {
        menu();
        cout << "Ingrese una opcion" << endl;
        cin >> option;

        switch (option)
        {
        case 1:
            cout << "Ingrese el numero de identificacion" << endl;
            cin.ignore();
            cin >> clave;
            cin.ignore();
            cout << "Ingrese el nombre del candidato" << endl;
            getline(cin, valor);

            if (votantes.esVacio())
            {
            votantes.put(clave, valor);
            cout << "Voto agregado correctamente" << endl;
            }
            else
            {
                try
                {
                    votantes.get(clave);
                    cout<<"El votante ya voto"<<endl;
                }
                catch(int e)
                {
                    votantes.put(clave,valor);
                    cout<<"agregado correctamente"<<endl;
                }
                
            }
            
            
        

        break;
    case 2:
        if (votantes.esVacio())
        {
            cout << "No hay votantes con ese numero en la base de datos" << endl;
        }
        else
        {
            cout << "Ingrese el numero del votante del que quiere saber el voto" << endl;
            cin.ignore();
            cin >> clave;
            cout << "El nombre del candidato es: " << votantes.get(clave) << endl;
            cout << "Listado en esa posicion" << endl;
            votantes.getList(clave);
        }

        break;
    case 3:
        if (votantes.esVacio())
        {
            cout << "No hay votantes en la base de datos" << endl;
        }
        else
        {
            cout << "Ingrese el voto que quiere eliminar" << endl;
            cin.ignore();
            cin >> clave;
            try
            {
                votantes.remove(clave);
                cout << "Voto eliminado" << endl;
            }
            catch (int e)
            {
                if (e == 404)
                {
                    cout << "El Votante no existe" << endl;
                }
            }
        }

        break;
    case 4:
        cout << "Hash" << endl;
        votantes.print();
        break;

    default:
        cout << "Opcion incorrecta" << endl;
        break;
    }
}
while (option != 5)
    ;

return 0;
}

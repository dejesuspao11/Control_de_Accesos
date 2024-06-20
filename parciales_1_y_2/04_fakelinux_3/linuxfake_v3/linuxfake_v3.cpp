#include <iostream> 
#include <list> 
#include <string> 

using namespace std; 

// definimos la estructura Users
struct Users {
    string User; // almacena el nombre de usuario
    list<string> Files; // almacena una lista de archivos asociados al usuario
};

int main()
{
    list<Users> users; // declara una lista de estructuras Users llamada users, que almacenará los usuarios y sus archivos
    Users user, * localUser; // declara una variable "user" de tipo Users y un puntero "localUser" a "Users"
    string username; // variable para almacenar el nombre de usuario ingresado
    int salir, menu; 
    string tmp; // variable temporal que almacena el nombre de archivo ingresado

    do
    {
        cout << "Ingresa username:"; // solicita al usuario ingresar un nombre de usuario
        cin >> username; // lee y guarda el nombre de usuario ingresado

        localUser = nullptr; // inicializa el puntero "localUser" en "nullptr"

        // recorre (itera) sobre la lista de usuarios para verificar si el usuario ya existe
        for (auto i : users)
        {
            // si el nombre de usuario ya existe...
            if (i.User == username)
            {
                localUser = &i; // guarda su dirección en localUser
                cout << "este usuario ya existe" << endl; // informa que el usuario ya existe
                break; // sale del bucle
            }
        }

        // si el usuario no existe, crea uno nuevo
        if (localUser == nullptr)
        {
            user.User = username; // asigna el nombre de usuario a "user"
            user.Files.clear(); // limpia la lista de archivos de "user"

            users.push_back(user); // agrega el nuevo usuario a la lista de usuarios
            localUser = &(users.back()); // asigna la dirección del nuevo usuario al apuntador "localUser"
        }

        do
        {
            // muestra el menú de opciones...
            cout << "Opciones:" << endl << "\t1) Listar" << endl << "\t2) Crear" << endl << "\t3) Salir" << endl << "Selecciona una opcion:";
            cin >> menu; // lee y guarda la opción seleccionada

            switch (menu)
            {
            case 1: // enlistar archivos
                cout << "01" << endl; // muestra un mensaje de depuración

                // recorre la lista de archivos del usuario y los muestra
                for (auto i : localUser->Files)
                {
                    cout << i << " - ";
                }
                cout << endl << endl; // salta a la siguiente línea y agrega otro salto de línea 
                break;

            case 2: // crear un nuevo archivo
                cout << "02" << endl; // muestra un mensaje...
                cout << "Ingresa archivo:"; // solicita al usuario ingresar el nombre del archivo
                cin >> tmp; // guarda el nombre del archivo ingresado
                localUser->Files.push_back(tmp); // agrega el archivo a la lista de archivos del usuario
                //salida del "menu"
                break;

            case 3: // salir del menú
                //si ninguna de las opciones diponibles fue seleccionada...
            default:
                cout << "03" << endl; 
                // sale del bucle
                break;
            }
        } while (menu != 3); // repite el menú hasta que el usuario elija salir

        cout << "Quieres salir? (0:yes 1:no) :"; // muestra una pregunta al usuario
        cin >> salir; // guarda la respuesta del usuario
        cout << endl; // salto de línea

    } while (salir == 1); // repite el blucle hasta que el usuario escoja la opcion de salida

    // muestra la lista de usuarios con sus archivos
    for (auto i : users)
    {
        //muestra el username
        cout << i.User << " - "; 

    }
    cout << endl << endl; // salta a la siguiente línea y agrega otro salto de linea

    return 0; // finaliza el porgrama
}
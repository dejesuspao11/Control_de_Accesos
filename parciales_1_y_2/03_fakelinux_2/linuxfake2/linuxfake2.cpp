#include <iostream>
#include <list>

using namespace std;

// define una estructura llamada "Users", que tiene dos miembros...
struct Users {
    // User que representa el nombre del usuario
    string User;
    // Files, que es una lista de cadenas de caracteres que representa los archivos asociados al usuario
    list<string> FIles;
};


int main() {
    // declara una lista llamada users que almacenará objetos del tipo Users...
    // ...lista se utiliza para almacenar múltiples usuarios
    list<Users> users;
    // Declara un objeto del tipo Users llamado "user"...
    // ...se utilizará para almacenar temporalmente la información de un usuario antes de agregarlo a la lista de usuarios
    Users user;

    // asigna el valor "hola (:" al miembro User del objeto user
    user.User = "hola (:";
    // agrega el objeto user al final de la lista "users"
    users.push_back(user);

    // cambia el valor del miembro User del objeto user a "adios :)"
    user.User = "adios :)";
    // agrega el objeto "user" modificado al final de la lista users 
    users.push_back(user);

    // itera sobre todos los elementos de la lista users
    // i toma el valor de cada elemento en cada iteración
    for (auto i : users) {
        // imprime los nombres de los usuarios
        cout << i.User << ' ';
    }

    // indica que el programa se ha ejecutado correctamente porque...
    // ...el sistema operativo espera un valor de retorno para determinar si el programa se ejecutó con éxito o no
    return 0;

} // fin 
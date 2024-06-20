#include <iostream>
#include <string>

using namespace std;

int main() {
    string access_key = "aguacate";
    string user_key;

    while (true) {
        cout << "estas atrapado xxxx" << "\n" << "ingresa la clave secreta para salir:";
        //cout << "ingresa la clave secreta para salir:";
        cin >> user_key;

        if (user_key == access_key) {
            cout << "eres libre! adios (:";
            return 5;
        }
        else {
            
            cout << "la clave es incorrecta..." << endl;
        }
    }

    return 0;
}
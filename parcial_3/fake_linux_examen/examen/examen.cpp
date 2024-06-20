#include <string>
#include <iostream>
#include <list>
#include <fstream>
using namespace std;

enum Perm { r, w, x }; // r=0 , w=1, x=2

struct Files {
    string Name;
    Perm perm;
};

struct Users {
    string User;
    list<Files> files;
};

int main() {
    list<Users> users;
    Users user;
    int salir, menu, optUser;
    string username, tmp, user_root, file_line;
    ofstream fUser, ofRoot;
    ifstream ifRoot("root");
    Files tmpFile;

    string biosPass;
    cout << "Ingresar master password_: ";
    cin >> biosPass;
    if (biosPass != "input") {
        return 2;
    }

    if (ifRoot.is_open()) { // existe
        // Cargar usuarios
        while (getline(ifRoot, user_root)) {
            cout << "Loading user: " << user_root << '\n';
            user.User = user_root;
            user.files.clear();

            ifstream ifUser(user_root + ".usr");
            while (getline(ifUser, file_line)) {
                size_t delimiterPos = file_line.find('|');
                if (delimiterPos != string::npos) {
                    string file_user = file_line.substr(0, delimiterPos);
                    string file_perm = file_line.substr(delimiterPos + 1);

                    cout << file_user << " - " << file_perm << " | ";

                    tmpFile.Name = file_user;
                    tmpFile.perm = static_cast<Perm>(stoi(file_perm));
                    user.files.push_back(tmpFile);
                }
            }
            cout << endl;
            users.push_back(user);
        }
        ifRoot.close();
    }
    else { // No existe
        // Crear archivo
        ofRoot.open("root");
        ofRoot.close();
    }

    do {
        cout << "MENU" << endl << "1) Listar users" << endl << "2) Login" << endl;
        cin >> optUser;

        Users* localUser = nullptr;  // Mover la declaración aquí

        switch (optUser) {
        case 1:
            for (const auto& i : users) {
                cout << "user_: " << i.User << endl;
            }
            break;

        case 2:
            cout << "Ingresa username: ";
            cin >> username;

            for (auto& i : users) {
                if (i.User == username) {
                    localUser = &i;
                    cout << "User exists" << endl;
                    break;
                }
            }

            if (localUser == nullptr) {
                user.User = username;
                user.files.clear();
                users.push_back(user);
                localUser = &users.back();
            }

            do {
                cout << "Opciones:" << endl << "\t1) Listar" << endl << "\t2) Crear" << endl << "\t3) Salir" << endl << "Selecciona una opcion:";
                cin >> menu;

                switch (menu) {
                case 1: // listar archivos
                    for (const auto& i : localUser->files) {
                        cout << i.Name << " - " << i.perm << " | ";
                    }
                    cout << endl << endl;
                    break;

                case 2: // crear archivo
                    cout << "Ingresa archivo: ";
                    cin >> tmp;
                    tmpFile.Name = tmp;
                    tmpFile.perm = x;
                    localUser->files.push_back(tmpFile);
                    break;

                case 3: // salir
                    break;

                default:
                    cout << "Opcion no valida" << endl;
                    break;
                }
            } while (menu != 3);
            break;

        default:
            cout << "Opcion no valida" << endl;
            break;
        }

        cout << "Quieres salir? (0:yes 1:no) : ";
        cin >> salir;
        cout << endl;

    } while (salir == 1);

    // save files
    ofRoot.open("root");
    for (const auto& i : users) {
        cout << "user_: " << i.User << endl;
        ofRoot << i.User << endl;
        fUser.open(i.User + ".usr"); // Crea Archivo
        cout << "Created : " << i.User + ".usr" << endl;

        for (const auto& j : i.files) {
            cout << "\t" << j.Name << " - " << j.perm << endl;
            fUser << j.Name << "|" << j.perm << endl; // Guarda el nombre del archivo y el permiso en el archivo
        }

        cout << endl;
        fUser.close(); // Cierra archivo
    }
    ofRoot.close();
    cout << endl << endl;

    return 0;
}
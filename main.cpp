#include <iostream>
#include <fstream>

using namespace std;

void mostrarMenu() {
    cout << "\n===== MENU PRINCIPAL =====" << endl;
    cout << "1. Guardar usuario" << endl;
    cout << "2. Mostrar usuarios" << endl;
    cout << "3. Salir" << endl;
    cout << "Seleccione una opcion: ";
}

void guardarUsuario() {
    ofstream archivo("usuarios.txt", ios::app);

    string nombre, posicion;
    int edad;

    cin.ignore();

    cout << "Ingrese el nombre completo: ";
    getline(cin, nombre);

    cout << "Ingrese la posicion en la empresa: ";
    getline(cin, posicion);

    cout << "Ingrese la edad: ";
    cin >> edad;

    archivo << nombre << "," << posicion << "," << edad << endl;

    archivo.close();

    cout << "Usuario guardado correctamente.\n";
}


void mostrarUsuarios() {
    ifstream archivo("usuarios.txt");

    string linea;

    if (!archivo) {
        cout << "No existe informacion guardada.\n";
        return;
    }

    cout << "\n===== LISTA DE USUARIOS =====" << endl;

    while (getline(archivo, linea)) {
        cout << linea << endl;
    }

    archivo.close();
}

int main() {
    int opcion;

    do {
        mostrarMenu();
        cin >> opcion;

        switch(opcion) {
            case 1:
                guardarUsuario();
                break;
            case 2:
                mostrarUsuarios();
                break;
            case 3:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo.\n";
        }

    } while(opcion != 3);

    return 0;
}
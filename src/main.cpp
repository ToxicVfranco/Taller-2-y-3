#include "../include/Biblioteca.h"
#include <iostream>
#include <string>

using namespace std;

void mostrarMenu() {
    cout << "\nSISTEMA DE GESTION DE BIBLIOTECA" << endl;
    cout << "1. Mostrar materiales disponibles" << endl;
    cout << "2. Registrar prestamo" << endl;
    cout << "3. Registrar devolucion" << endl;
    cout << "4. Salir" << endl;
    cout << "Seleccione una opcion: ";
}

int main() {

    Biblioteca biblioteca;

    // Cargar datos iniciales
    biblioteca.cargarDatosIniciales();

    // Crear algunos usuarios y asistentes de prueba
    biblioteca.agregarUsuario(new Usuario("Juan Perez", "USR001"));
    biblioteca.agregarUsuario(new Usuario("Maria Gomez", "USR002"));
    biblioteca.agregarAsistente(new Asistente("Carlos Ruiz", "AST001"));
    biblioteca.agregarAsistente(new Asistente("Ana Torres", "AST002"));

    int opcion;
    do {
        mostrarMenu();
        cin >> opcion;
        cin.ignore(); // Limpiar el buffer

        switch (opcion) {
            case 1: {  // Mostrar materiales disponibles
                int opcionFiltro;
                cout << "\n=== FILTRAR MATERIALES ===" << endl;
                cout << "1. Libros" << endl;
                cout << "2. DVDs" << endl;
                cout << "3. Revistas" << endl;
                cout << "4. Todos" << endl;
                cout << "Seleccione el tipo: ";
                cin >> opcionFiltro;
                cin.ignore();

                switch (opcionFiltro) {
                    case 1: biblioteca.mostrarMaterialesPorTipo("Libro"); break;
                    case 2: biblioteca.mostrarMaterialesPorTipo("DVD"); break;
                    case 3: biblioteca.mostrarMaterialesPorTipo("Revista"); break;
                    case 4: biblioteca.mostrarMateriales(); break;  // Mostrar todos
                    default: cout << "Opción no válida" << endl;
                }
                break;
            }
            case 2: {
                string idMaterial, idUsuario, idAsistente;
                cout << "Ingrese ID del material: ";
                getline(cin, idMaterial);
                cout << "Ingrese ID del usuario: ";
                getline(cin, idUsuario);
                cout << "Ingrese ID del asistente: ";
                getline(cin, idAsistente);
                biblioteca.prestarMaterial(idMaterial, idUsuario, idAsistente);
                break;
            }
            case 3: {
                string idMaterial, idUsuario, idAsistente;
                cout << "Ingrese ID del material: ";
                getline(cin, idMaterial);
                cout << "Ingrese ID del usuario: ";
                getline(cin, idUsuario);
                cout << "Ingrese ID del asistente: ";
                getline(cin, idAsistente);
                biblioteca.devolverMaterial(idMaterial, idUsuario, idAsistente);
                break;
            }
            case 4: {
                cout << "Saliendo del sistema..." << endl;
                break;
            }
            default: {
                cout << "Opcion no valida" << endl;
            }
        }
    } while (opcion != 4);

    return 0;
}

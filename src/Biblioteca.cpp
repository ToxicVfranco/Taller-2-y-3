#include "Biblioteca.h"
#include "Libro.h"
#include "DVD.h"
#include "Revista.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Biblioteca::~Biblioteca() {
    for (auto material : materiales) delete material;
    for (auto usuario : usuarios) delete usuario;
    for (auto asistente : asistentes) delete asistente;
}

void Biblioteca::registrarOperacion(string tipo, string idMaterial, string idPersona) {
    ofstream archivo("registro.txt", ios::app);
    time_t ahora = time(0);
    char* fechaHora = ctime(&ahora);

    if (archivo.is_open()) {
        archivo << "[" << fechaHora << "] " << tipo << " - Material: "
               << idMaterial << " - Persona: " << idPersona << endl;
        archivo.close();
    }
}

void Biblioteca::agregarMaterial(Material* material) {
    materiales.push_back(material);
}

void Biblioteca::agregarUsuario(Usuario* usuario) {
    usuarios.push_back(usuario);
}

void Biblioteca::agregarAsistente(Asistente* asistente) {
    asistentes.push_back(asistente);
}

Material* Biblioteca::buscarMaterial(string id) {
    for (auto material : materiales) {
        if (material->getId() == id) {
            return material;
        }
    }
    return nullptr;
}

Usuario* Biblioteca::buscarUsuario(string id) {
    for (auto usuario : usuarios) {
        if (usuario->getId() == id) {
            return usuario;
        }
    }
    return nullptr;
}

Asistente* Biblioteca::buscarAsistente(string id) {
    for (auto asistente : asistentes) {
        if (asistente->getId() == id) {
            return asistente;
        }
    }
    return nullptr;
}

void Biblioteca::prestarMaterial(string idMaterial, string idUsuario, string idAsistente) {
    Material* material = buscarMaterial(idMaterial);
    Usuario* usuario = buscarUsuario(idUsuario);
    Asistente* asistente = buscarAsistente(idAsistente);

    if (material && usuario && asistente) {
        if (material->estaDisponible()) {
            if (usuario->puedePrestar()) {
                usuario->prestarMaterial(material);
                registrarOperacion("PRESTAMO", idMaterial, idUsuario);
                cout << "Prestamo realizado con exito" << endl;
            } else {
                cout << "El usuario ha alcanzado el limite de prestamos" << endl;
            }
        } else {
            cout << "El material no esta disponible" << endl;
        }
    } else {
        cout << "No se encontraron los datos necesarios" << endl;
    }
}

void Biblioteca::devolverMaterial(string idMaterial, string idUsuario, string idAsistente) {
    Material* material = buscarMaterial(idMaterial);
    Usuario* usuario = buscarUsuario(idUsuario);
    Asistente* asistente = buscarAsistente(idAsistente);

    if (material && usuario && asistente) {
        usuario->devolverMaterial(material);
        registrarOperacion("DEVOLUCION", idMaterial, idUsuario);
        cout << "Devolucion realizada con exito" << endl;
    } else {
        cout << "No se encontraron los datos necesarios" << endl;
    }
}

void Biblioteca::mostrarMateriales() {
    cout << "\nMATERIALES DISPONIBLES:" << endl;
    for (auto material : materiales) {
        material->mostrarInfo();
        cout << "-----------------" << endl;
    }
}

void Biblioteca::cargarDatosIniciales() {
    // Cargar libros desde archivo
    ifstream archivoLibros("libros.txt");
    if (archivoLibros.is_open()) {
        string linea;
        while (getline(archivoLibros, linea)) {
            size_t pos1 = linea.find(" - ");
            size_t pos2 = linea.find(" - ", pos1 + 3);
            size_t pos3 = linea.find(" - ", pos2 + 3);
            size_t pos4 = linea.find(" - ", pos3 + 3);

            string isbn = linea.substr(0, pos1);
            string titulo = linea.substr(pos1 + 3, pos2 - pos1 - 3);
            string autor = linea.substr(pos2 + 3, pos3 - pos2 - 3);
            string genero = linea.substr(pos3 + 3, pos4 - pos3 - 3);
            int paginas = stoi(linea.substr(pos4 + 3));

            agregarMaterial(new Libro(isbn, titulo, autor, genero, paginas));
        }
        archivoLibros.close();
    }

    // Cargar DVDs desde archivo
    ifstream archivoDVDs("DVDs.txt");
    if (archivoDVDs.is_open()) {
        string linea;
        while (getline(archivoDVDs, linea)) {
            size_t pos1 = linea.find(" - ");
            size_t pos2 = linea.find(" - ", pos1 + 3);
            size_t pos3 = linea.find(" - ", pos2 + 3);
            size_t pos4 = linea.find(" - ", pos3 + 3);

            string id = linea.substr(0, pos1);
            string titulo = linea.substr(pos1 + 3, pos2 - pos1 - 3);
            string genero = linea.substr(pos2 + 3, pos3 - pos2 - 3);
            string director = linea.substr(pos3 + 3, pos4 - pos3 - 3);
            int duracion = stoi(linea.substr(pos4 + 3));

            agregarMaterial(new DVD(id, titulo, director, genero, duracion));
        }
        archivoDVDs.close();
    }

    // Cargar revistas desde archivo
    ifstream archivoRevistas("Revistas.txt");
    if (archivoRevistas.is_open()) {
        string linea;
        while (getline(archivoRevistas, linea)) {
            size_t pos1 = linea.find(" - ");
            size_t pos2 = linea.find(" - ", pos1 + 3);
            size_t pos3 = linea.find(" - ", pos2 + 3);

            string id = linea.substr(0, pos1);
            string nombre = linea.substr(pos1 + 3, pos2 - pos1 - 3);
            string tematica = linea.substr(pos2 + 3, pos3 - pos2 - 3);
            string edicion = linea.substr(pos3 + 3);

            agregarMaterial(new Revista(id, nombre, tematica, edicion));
        }
        archivoRevistas.close();
    }
}

#include "Libro.h"
#include <iostream>

using namespace std;

Libro::Libro(string isbn, string titulo, string autor, string genero, int paginas)
    : Material(isbn, titulo, genero), isbn(isbn), autor(autor), paginas(paginas) {}

void Libro::mostrarInfo() {
    cout << "LIBRO - ISBN: " << id << "\nTitulo: " << titulo
         << "\nAutor: " << autor << "\nGenero: " << genero
         << "\nPaginas: " << paginas
         << "\nDisponible: " << (disponible ? "Si" : "No") << endl;
}

string Libro::getTipo() {
     return "Libro";
}

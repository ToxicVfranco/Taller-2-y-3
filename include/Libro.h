#ifndef LIBRO_H
#define LIBRO_H

#include "Material.h"

using namespace std;

class Libro : public Material {
private:
    string isbn;
    string autor;
    int paginas;

public:
    Libro(string isbn, string titulo, string autor, string genero, int paginas);
    void mostrarInfo() override;
    string getTipo() override;
};

#endif // LIBRO_H

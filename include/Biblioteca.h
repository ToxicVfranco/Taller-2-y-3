#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <vector>
#include <string>
#include <fstream>
#include <ctime>
#include "Material.h"
#include "Usuario.h"
#include "Asistente.h"

using namespace std;

class Biblioteca {
private:
    vector<Material*> materiales;
    vector<Usuario*> usuarios;
    vector<Asistente*> asistentes;

    void registrarOperacion(string tipo, string idMaterial, string idPersona);

public:
    ~Biblioteca();

    void agregarMaterial(Material* material);
    void agregarUsuario(Usuario* usuario);
    void agregarAsistente(Asistente* asistente);

    Material* buscarMaterial(string id);
    Usuario* buscarUsuario(string id);
    Asistente* buscarAsistente(string id);

    void prestarMaterial(string idMaterial, string idUsuario, string idAsistente);
    void devolverMaterial(string idMaterial, string idUsuario, string idAsistente);

    void mostrarMateriales();
    void cargarDatosIniciales();
};

#endif // BIBLIOTECA_H

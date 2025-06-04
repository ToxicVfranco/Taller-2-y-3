#ifndef USUARIO_H
#define USUARIO_H

#include "Persona.h"

using namespace std;

class Usuario : public Persona {
public:
    Usuario(string nombre, string id);
};

#endif // USUARIO_H

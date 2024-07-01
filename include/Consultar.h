#ifndef CONSULTAR_H
#define CONSULTAR_H

#include "Persona.h"
#include "Libro.h"
#include "Prestamo.h"

class Consultar {
public:
    Persona BuscarPersona(int codigo);
    Libro BuscarLibro(char nombre[50]);
    Prestamo BuscarPrestamo(int codigo);
};

#endif

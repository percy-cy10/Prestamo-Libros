#ifndef PRESTAMO_H
#define PRESTAMO_H

#include "Persona.h"
#include "Libro.h"
#include "Hora.h"
#include "Fecha.h"

class Prestamo {
private:
    Persona p;
    Libro l;
    Hora h;
    Fecha f;
    int codigo;
public:
    Prestamo();
    void PrestarLibro(Persona, Libro, Hora, Fecha);
    void SetCodigo(int);
    int GetCodigo() const;
    void Mostrar() const;
};

#endif


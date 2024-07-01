#ifndef GUARDAR_H
#define GUARDAR_H

#include "Persona.h"
#include "Libro.h"
#include "Prestamo.h"  // Aseg�rate de incluir la declaraci�n de la clase Prestamo

class Guardar {
public:
    void GuardarPersona(Persona per);
    void GuardarLibro(Libro lib);
    void GuardarPrestamo(Prestamo pres);  // Aseg�rate de que la declaraci�n es correcta
};

#endif

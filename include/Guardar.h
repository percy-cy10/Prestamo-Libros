#ifndef GUARDAR_H
#define GUARDAR_H

#include "Persona.h"
#include "Libro.h"
#include "Prestamo.h"  // Asegúrate de incluir la declaración de la clase Prestamo

class Guardar {
public:
    void GuardarPersona(Persona per);
    void GuardarLibro(Libro lib);
    void GuardarPrestamo(Prestamo pres);  // Asegúrate de que la declaración es correcta
};

#endif

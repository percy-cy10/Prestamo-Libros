#ifndef MENU_H
#define MENU_H

#include "Persona.h"
#include "Libro.h"
#include "Prestamo.h"
#include "Fecha.h"
#include "Hora.h"

class Menu {
private:
    int opcion;
    void Linea();
    char I();
    void Limpiar();
    Persona IngresarDatos();
    Libro IngresarLibro();
    Fecha ObtenerFechaActual();  // Declarar función para obtener la fecha actual
    Hora ObtenerHoraActual();  // Declarar función para obtener la hora actual
    int GenerarCodigoPersona();
    int GenerarCodigoPrestamo();
    void Administrador();
    void Lector();
    void LoginAdmin();
    void NuevoLibro();
    void NuevoPrestamo();
    void NuevaPersona();
    void MostrarLibros();
    void MostrarPersonas();
    void MostrarPrestamos();
public:
    Menu();
    void Inicio();
};

#endif

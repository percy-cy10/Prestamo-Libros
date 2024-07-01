#include "../include/Guardar.h"
#include <stdio.h>

void Guardar::GuardarPersona(Persona per) {
    FILE* archivo;
    archivo = fopen("personas.bin", "a");
    fwrite(&per, sizeof(Persona), 1, archivo);
    fclose(archivo);
}

void Guardar::GuardarLibro(Libro lib) {
    FILE* archivo;
    archivo = fopen("libros.bin", "a");
    fwrite(&lib, sizeof(Libro), 1, archivo);
    fclose(archivo);
}

void Guardar::GuardarPrestamo(Prestamo pres) {
    FILE* archivo;
    archivo = fopen("prestamos.bin", "a");
    fwrite(&pres, sizeof(Prestamo), 1, archivo);
    fclose(archivo);
}

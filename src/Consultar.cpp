#include "../include/Consultar.h"
#include <stdio.h>
#include <string.h>

Persona Consultar::BuscarPersona(int codigo) {
    Persona per;
    FILE* archivo;
    archivo = fopen("personas.bin", "r");
    while (fread(&per, sizeof(Persona), 1, archivo)) {
        if (per.GetCodigo() == codigo) {
            fclose(archivo);
            return per;
        }
    }
    fclose(archivo);
    return per;
}

Libro Consultar::BuscarLibro(char nombre[50]) {
    Libro lib;
    FILE* archivo;
    archivo = fopen("libros.bin", "r");
    while (fread(&lib, sizeof(Libro), 1, archivo)) {
        if (strcmp(lib.GetNombre(), nombre) == 0) {
            fclose(archivo);
            return lib;
        }
    }
    fclose(archivo);
    return lib;
}

Prestamo Consultar::BuscarPrestamo(int codigo) {
    Prestamo pres;
    FILE* archivo;
    archivo = fopen("prestamos.bin", "r");
    while (fread(&pres, sizeof(Prestamo), 1, archivo)) {
        if (pres.GetCodigo() == codigo) {
            fclose(archivo);
            return pres;
        }
    }
    fclose(archivo);
    return pres;
}


#include "../include/Libro.h"
#include <string.h>
#include <iostream>
using namespace std;

Libro::Libro() {
    SetNombre("");
    SetAutor("");
    SetPaginas(0);
    SetEdicion(0);
    SetIdioma("");
}

Libro::Libro(char n[50], char a[50], int p, int e, char i[50]) {
    SetNombre(n);
    SetAutor(a);
    SetPaginas(p);
    SetEdicion(e);
    SetIdioma(i);
}

void Libro::SetLibro(const Libro& l) {
    *this = l;
}

void Libro::SetNombre(char n[50]) {
    strcpy(nombre, Validar(n));
}

void Libro::SetAutor(char a[50]) {
    strcpy(autor, Validar(a));
}

void Libro::SetPaginas(int p) {
    paginas = Validar(p);
}

void Libro::SetEdicion(int e) {
    edicion = Validar(e);
}

void Libro::SetIdioma(char i[50]) {
    strcpy(idioma, Validar(i));
}

const char* Libro::GetNombre() const {
    return nombre;
}

const char* Libro::GetAutor() const {
    return autor;
}

int Libro::GetPaginas() const {
    return paginas;
}

int Libro::GetEdicion() const {
    return edicion;
}

const char* Libro::GetIdioma() const {
    return idioma;
}

char* Libro::Validar(char cad[50]) {
    int i;
    char* tmp = new char[50];
    for (i = 0; cad[i] != '\0'; i++) {
        if (isalpha(cad[i])) {
            tmp[i] = cad[i];
        } else {
            tmp[i] = '\0';
            return tmp;
        }
    }
    tmp[i] = '\0';
    return tmp;
}

int Libro::Validar(int num) {
    if (num > 0) return num;
    return -num;
}

void Libro::Mostrar() const {
    cout << "Titulo del Libro: " << nombre << endl;
    cout << "Autor: " << autor << endl;
    cout << "Paginas: " << paginas << endl;
    cout << "Edicion: " << edicion << endl;
    cout << "Idioma: " << idioma << endl << endl;
}

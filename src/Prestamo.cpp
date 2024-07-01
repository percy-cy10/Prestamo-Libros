#include "../include/Prestamo.h"
#include <iostream>
using namespace std;

Prestamo::Prestamo() : codigo(0) {}

void Prestamo::PrestarLibro(Persona P, Libro L, Hora H, Fecha F) {
    p.SetPersona(P);
    l.SetLibro(L);
    h.SetHora(H);
    f.SetFecha(F);
}

void Prestamo::SetCodigo(int cod) {
    codigo = cod;
}

int Prestamo::GetCodigo() const {
    return codigo;
}

void Prestamo::Mostrar() const {
    cout << "El señor: " << endl;
    p.Mostrar();
    cout << "Se presto el Libro: " << endl;
    l.Mostrar();
    cout << "En la Fecha: ";
    f.Mostrar();
    cout << "A horas: ";
    h.Mostrar();
    cout << "Codigo del prestamo: " << codigo << endl;
}

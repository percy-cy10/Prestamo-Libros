#include "../include/Fecha.h"
#include <iostream>
using namespace std;

Fecha::Fecha() : dia(0), mes(0), anio(0) {}

Fecha::Fecha(int dd, int mm, int aa) : dia(dd), mes(mm), anio(aa) {}

void Fecha::SetFecha(int dd, int mm, int aa) {
    dia = dd;
    mes = mm;
    anio = aa;
}

void Fecha::SetFecha(const Fecha& F) {
    *this = F;
}

void Fecha::SetDia(int dd) {
    dia = dd;
}

void Fecha::SetMes(int mm) {
    mes = mm;
}

void Fecha::SetAnio(int aa) {
    anio = aa;
}

int Fecha::GetDia() const {
    return dia;
}

int Fecha::GetMes() const {
    return mes;
}

int Fecha::GetAnio() const {
    return anio;
}

void Fecha::Mostrar() const {
    cout << dia << " de ";
    switch (mes) {
        case 1: cout << "Enero"; break;
        case 2: cout << "Febrero"; break;
        case 3: cout << "Marzo"; break;
        case 4: cout << "Abril"; break;
        case 5: cout << "Mayo"; break;
        case 6: cout << "Junio"; break;
        case 7: cout << "Julio"; break;
        case 8: cout << "Agosto"; break;
        case 9: cout << "Setiembre"; break;
        case 10: cout << "Octubre"; break;
        case 11: cout << "Noviembre"; break;
        case 12: cout << "Diciembre"; break;
        default: cout << "Error"; break;
    }
    cout << " del " << anio << endl;
}

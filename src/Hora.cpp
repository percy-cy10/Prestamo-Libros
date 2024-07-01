#include "../include/Hora.h"
#include <iostream>
using namespace std;

Hora::Hora() : hora(0), min(0), seg(0) {}

Hora::Hora(int h, int m, int s) : hora(h), min(m), seg(s) {}

void Hora::SetHora(int h, int m, int s) {
    hora = h;
    min = m;
    seg = s;
}

void Hora::SetHora(const Hora& h) {
    *this = h;
}

int Hora::GetHora() const {
    return hora;
}

int Hora::GetMin() const {
    return min;
}

int Hora::GetSeg() const {
    return seg;
}

void Hora::Mostrar() const {
    cout << hora << ":" << min << ":" << seg << endl;
}

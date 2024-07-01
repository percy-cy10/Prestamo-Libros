#ifndef HORA_H
#define HORA_H

class Hora {
private:
    int hora, min, seg;
public:
    Hora();
    Hora(int, int, int);
    void SetHora(int, int, int);
    void SetHora(const Hora&);
    int GetHora() const;
    int GetMin() const;
    int GetSeg() const;
    void Mostrar() const;
};

#endif

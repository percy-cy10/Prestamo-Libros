#ifndef FECHA_H
#define FECHA_H

class Fecha {
private:
    int dia, mes, anio;
public:
    Fecha();
    Fecha(int, int, int);
    void SetFecha(int, int, int);
    void SetFecha(const Fecha&);
    void SetDia(int);
    void SetMes(int);
    void SetAnio(int);
    int GetDia() const;
    int GetMes() const;
    int GetAnio() const;
    void Mostrar() const;
};

#endif

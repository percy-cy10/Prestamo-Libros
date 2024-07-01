#ifndef PERSONA_H
#define PERSONA_H

class Persona {
private:
    char nombres[30];
    char ap_pat[20];
    char ap_mat[20];
    int edad;
    char sexo;
    int codigo;
    char* Validar(char*);
    int Validar(int);
    char Validar(char);
public:
    Persona();
    Persona(char[30], char[20], char[20], int, char);
    void SetPersona(const Persona&);
    void SetNombres(char[30]);
    void SetApPaterno(char[20]);
    void SetApMaterno(char[20]);
    void SetEdad(int);
    void SetSexo(char);
    void SetCodigo(int);
    int GetCodigo() const;
    const char* GetNombres() const;
    const char* GetApPaterno() const;
    const char* GetApMaterno() const;
    int GetEdad() const;
    char GetSexo() const;
    void CumplirAnios();
    void MostrarSexo() const;
    void Mostrar() const;
};

#endif

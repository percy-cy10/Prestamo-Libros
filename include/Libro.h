#ifndef LIBRO_H
#define LIBRO_H

class Libro {
private:
    char nombre[50];
    char autor[50];
    int paginas;
    int edicion;
    char idioma[50];
    char* Validar(char*);
    int Validar(int);
public:
    Libro();
    Libro(char[50], char[50], int, int, char[50]);
    void SetLibro(const Libro&);
    void SetNombre(char[50]);
    void SetAutor(char[50]);
    void SetPaginas(int);
    void SetEdicion(int);
    void SetIdioma(char[50]);
    const char* GetNombre() const;
    const char* GetAutor() const;
    int GetPaginas() const;
    int GetEdicion() const;
    const char* GetIdioma() const;
    void Mostrar() const;
};

#endif

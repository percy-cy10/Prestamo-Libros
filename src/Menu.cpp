#include "../include/Menu.h"
#include "../include/Guardar.h"
#include "../include/Consultar.h"
#include "../include/Prestamo.h"
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <chrono>  // Incluir para obtener la fecha y hora
#include <ctime>   // Incluir para trabajar con time_t y tm
using namespace std;

Menu::Menu() {
    opcion = 0;
}

void Menu::Linea() {
    cout << "+--------------------+" << endl;
}

char Menu::I() {
    return '|';
}

void Menu::Limpiar() {
#ifdef _WIN32
    system("CLS");
#else
    system("clear");
#endif
}

Persona Menu::IngresarDatos() {
    char nombre[30];
    char apPat[20];
    char apMat[20];
    int edad;
    char sexo;

    cout << "INGRESE NOMBRE: ";
    cin >> nombre;
    cout << "INGRESE APELLIDO PATERNO: ";
    cin >> apPat;
    cout << "INGRESE APELLIDO MATERNO: ";
    cin >> apMat;
    cout << "INGRESE SEXO [M o F]: ";
    cin >> sexo;
    cout << "INGRESE EDAD: ";
    cin >> edad;

    return Persona(nombre, apPat, apMat, edad, sexo);
}

Libro Menu::IngresarLibro() {
    char nombre[50];
    char autor[50];
    int paginas;
    int edicion;
    char idioma[50];

    cout << "INGRESE NOMBRE DEL LIBRO: ";
    cin >> nombre;
    cout << "INGRESE AUTOR: ";
    cin >> autor;
    cout << "INGRESE NUMERO DE PAGINAS: ";
    cin >> paginas;
    cout << "INGRESE EDICION: ";
    cin >> edicion;
    cout << "INGRESE IDIOMA: ";
    cin >> idioma;

    return Libro(nombre, autor, paginas, edicion, idioma);
}

// Función para obtener la fecha actual
Fecha Menu::ObtenerFechaActual() {
    auto now = chrono::system_clock::now();
    time_t now_time = chrono::system_clock::to_time_t(now);
    tm local_time = *localtime(&now_time);

    return Fecha(local_time.tm_mday, local_time.tm_mon + 1, local_time.tm_year + 1900);
}

// Función para obtener la hora actual
Hora Menu::ObtenerHoraActual() {
    auto now = chrono::system_clock::now();
    time_t now_time = chrono::system_clock::to_time_t(now);
    tm local_time = *localtime(&now_time);

    return Hora(local_time.tm_hour, local_time.tm_min, local_time.tm_sec);
}

int Menu::GenerarCodigoPersona() {
    FILE* archivo;
    archivo = fopen("personas.bin", "r");
    if (archivo == NULL) return 1;
    Persona per;
    int codigo = 0;
    while (fread(&per, sizeof(Persona), 1, archivo)) {
        codigo = per.GetCodigo();
    }
    fclose(archivo);
    return codigo + 1;
}

int Menu::GenerarCodigoPrestamo() {
    FILE* archivo;
    archivo = fopen("prestamos.bin", "r");
    if (archivo == NULL) return 1;
    Prestamo pres;
    int codigo = 0;
    while (fread(&pres, sizeof(Prestamo), 1, archivo)) {
        codigo = pres.GetCodigo();
    }
    fclose(archivo);
    return codigo + 1;
}

void Menu::Inicio() {
    Limpiar();
    Linea();
    cout << I() << "  SISTEMA DE PRESTAMOS  " << I() << endl;
    cout << I() << "      DE LIBROS         " << I() << endl;
    Linea();
    cout << I() << " [1] ADMINISTRADOR      " << I() << endl;
    cout << I() << " [2] LECTOR             " << I() << endl;
    cout << I() << " [3] SALIR              " << I() << endl;
    Linea();
    cout << "Opcion >> ";
    cin >> opcion;

    switch (opcion) {
        case 1:
            LoginAdmin();
            break;
        case 2:
            Lector();
            break;
        case 3:
            exit(0);
            break;
        default:
            cout << "Elija Una Opcion Valida" << endl;
            system("PAUSE");
            Inicio();
            break;
    }
}

void Menu::LoginAdmin() {
    string usuario, clave;
    cout << "USUARIO: ";
    cin >> usuario;
    cout << "CLAVE: ";
    cin >> clave;

    if (usuario == "user" && clave == "clave") {
        Administrador();
    } else {
        cout << "Credenciales incorrectas. Intente nuevamente." << endl;
        system("PAUSE");
        Inicio();
    }
}

void Menu::Administrador() {
    Limpiar();
    Linea();
    cout << I() << "[1] NUEVO LIBRO        " << I() << endl;
    cout << I() << "[2] NUEVO PRESTAMO     " << I() << endl;
    cout << I() << "[3] NUEVA PERSONA      " << I() << endl;
    cout << I() << "[4] MOSTRAR LIBROS     " << I() << endl;
    cout << I() << "[5] MOSTRAR PERSONAS   " << I() << endl;
    cout << I() << "[6] MOSTRAR PRESTAMOS  " << I() << endl;
    cout << I() << "[7] SALIR              " << I() << endl;
    Linea();
    cout << "Opcion >> ";
    cin >> opcion;

    switch (opcion) {
        case 1:
            NuevoLibro();
            Administrador();
            break;
        case 2:
            NuevoPrestamo();
            Administrador();
            break;
        case 3:
            NuevaPersona();
            Administrador();
            break;
        case 4:
            MostrarLibros();
            system("PAUSE");
            Administrador();
            break;
        case 5:
            MostrarPersonas();
            system("PAUSE");
            Administrador();
            break;
        case 6:
            MostrarPrestamos();
            system("PAUSE");
            Administrador();
            break;
        case 7:
            Inicio();
            break;
        default:
            cout << "Elija Una Opcion Valida" << endl;
            system("PAUSE");
            Administrador();
            break;
    }
}

void Menu::Lector() {
    Limpiar();
    Linea();
    cout << I() << "[1] NUEVO PRESTAMO     " << I() << endl;
    cout << I() << "[2] MOSTRAR LIBROS     " << I() << endl;
    cout << I() << "[3] SALIR              " << I() << endl;
    Linea();
    cout << "Opcion >> ";
    cin >> opcion;

    switch (opcion) {
        case 1:
            NuevoPrestamo();
            Lector();
            break;
        case 2:
            MostrarLibros();
            system("PAUSE");
            Lector();
            break;
        case 3:
            Inicio();
            break;
        default:
            cout << "Elija Una Opcion Valida" << endl;
            system("PAUSE");
            Lector();
            break;
    }
}

void Menu::NuevoLibro() {
    Limpiar();
    Guardar g;
    Libro l = IngresarLibro();
    g.GuardarLibro(l);
    Linea();
    cout << "Libro Registrado Satisfactoriamente" << endl;
    system("PAUSE");
}

void Menu::NuevoPrestamo() {
    Limpiar();
    Guardar g;
    Persona p = IngresarDatos();
    Libro l = IngresarLibro();
    Fecha f = ObtenerFechaActual();  // Usar la función para obtener la fecha actual
    Hora h = ObtenerHoraActual();  // Usar la función para obtener la hora actual
    Prestamo pres;
    pres.PrestarLibro(p, l, h, f);
    pres.SetCodigo(GenerarCodigoPrestamo());
    g.GuardarPrestamo(pres);
    Linea();
    cout << "Prestamo Registrado Satisfactoriamente" << endl;
    system("PAUSE");
}

void Menu::NuevaPersona() {
    Limpiar();
    Guardar g;
    Persona p = IngresarDatos();
    p.SetCodigo(GenerarCodigoPersona());
    g.GuardarPersona(p);
    Linea();
    cout << "Persona Registrada Satisfactoriamente" << endl;
    system("PAUSE");
}

void Menu::MostrarLibros() {
    Limpiar();
    FILE* archivo;
    archivo = fopen("libros.bin", "rb");
    if (archivo == NULL) {
        cout << "No hay libros registrados." << endl;
        return;
    }
    Libro lib;
    while (fread(&lib, sizeof(Libro), 1, archivo)) {
        lib.Mostrar();
    }
    fclose(archivo);
}

void Menu::MostrarPersonas() {
    Limpiar();
    FILE* archivo;
    archivo = fopen("personas.bin", "rb");
    if (archivo == NULL) {
        cout << "No hay personas registradas." << endl;
        return;
    }
    Persona per;
    while (fread(&per, sizeof(Persona), 1, archivo)) {
        per.Mostrar();
    }
    fclose(archivo);
}

void Menu::MostrarPrestamos() {
    Limpiar();
    FILE* archivo;
    archivo = fopen("prestamos.bin", "rb");
    if (archivo == NULL) {
        cout << "No hay préstamos registrados." << endl;
        return;
    }
    Prestamo pres;
    while (fread(&pres, sizeof(Prestamo), 1, archivo)) {
        pres.Mostrar();
    }
    fclose(archivo);
}

#include "Biblioteca.h"
#include "Libro.h"
#include <cstring>
#include <iostream>

using namespace std;

Biblioteca::Biblioteca(): libros(), cantidad(0){
    for (int i=0;i<MAX_LIBROS;i++){
        libros[i].setCodigo(0);
        libros[i].setPrestado(false);
        libros[i].setTitulo("");
    }
};

Biblioteca::Biblioteca(int codigos[], char *titulos[], int n):  cantidad(n){
    // Manual
    // for (int i=0;i<n;i++){
    //     int codigo;
    //     char titulo[50];
    //     cout << "Titulo del libro "<<i<<":";
    //     cin >> titulo;
    //     cout << "Codigo del libro "<<i<<":";
    //     cin >> codigo;
    //     libros[i].setTitulo(titulo);
    //     libros[i].setCodigo(codigo);
    //     libros[i].setPrestado(false);
    // }
    for (int i=0;i<n;i++){
        libros[i].setTitulo(titulos[i]);
        libros[i].setCodigo(codigos[i]);
        libros[i].setPrestado(false);
    }
};
Biblioteca::~Biblioteca() {};
void Biblioteca::mostrarLibros(){
    for (int i=0; i<cantidad;i++){
        libros[i].mostrarInfo();
    }
};

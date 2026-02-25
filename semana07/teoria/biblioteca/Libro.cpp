#include "Libro.h"
#include <cstring>
#include <iostream>

using namespace std;

Libro::Libro() : codigo(0), titulo(""), prestado(false) {};
Libro::Libro(int c, const char *t) : codigo(c), titulo(""), prestado(false) {
  if (c < 0) {
    cerr << "Codigo invalido, programa terminado\n";
    exit(1);
  }
  codigo = c;
  strcpy(titulo, t);
};
Libro::~Libro() {};

// accesores (getters)
int Libro::getCodigo() const { return codigo; };
const char *Libro::getTitulo() const { return titulo; };
bool Libro::getPrestado() const { return prestado; };

// Modificadores (setters)
void Libro::setCodigo(int c){
    codigo = c;
};
void Libro::setTitulo(char t[50]){
    strcpy(titulo, t);
};
void Libro::setPrestado(bool p){
    prestado = p;
};

void Libro::mostrarInfo() const {
  cout << "Titutlo: " << titulo << " | Codigo: " << codigo << " | "
       << (prestado ? "Prestado" : "Disponible") << endl;
}

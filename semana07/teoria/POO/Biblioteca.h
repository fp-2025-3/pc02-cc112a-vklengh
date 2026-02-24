// GUARDIAS: EVITAR QUE SE REDEFINA LAS CLASES IMPLEMENTADAS
#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include "Libro.h"
#include <string>

// using namespace std; // EVITAR SU USO EN ARCHIVOS .H PARA BUENA PRACTICA
// solo usar las librerias necesarias

const int MAX_LIBROS = 100;
class Biblioteca {
private:
  Libro libros[MAX_LIBROS];

public:
  // constructores
  Biblioteca();
  Biblioteca(const std::string &t, const std::string &a, int p);

  // destructor
  ~Biblioteca();

  // accesores (getters)
  std::string getLibros() const;

  // Modificadores (setters)
  void setLibros(Libro lib[], int n);

  void registrarLibro(Libro lib[], int &n);

  int buscarLibro(Libro lib[], int n, int codigo);

  void prestarLibro(Libro lib[], int n, int codigo);

  void devolverLibro(Libro lib[], int n, int codigo);

  void guardarEnArchivo(Libro lib[], int n);

  void cargarDesdeArchivo(Libro lib[], int n);

  void mostrarLibros(Libro lib[], int n);
};
#endif

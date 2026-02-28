#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include "Libro.h"
#include <string>

const int MAX_LIBROS = 100;

class Biblioteca {
private:
  Libro libros[MAX_LIBROS];
  int cantidad;

public:
  Biblioteca();
  Biblioteca(int codigos[], char *titulos[], int n);
  ~Biblioteca();
  void registrarLibro();
  int buscarLibro(int codigo);
  void prestarLibro(int codigo);
  void devolverLibro(int codigo);
  void guardarEnArchivo(const std::string direccion);
  void cargarDesdeArchivo(const std::string direccion);
  void mostrarLibros();
};

#endif

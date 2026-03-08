// GUARDIAS: EVITAR QUE SE REDEFINA LAS CLASES IMPLEMENTADAS
#ifndef LIBRO_H
#define LIBRO_H
#include <string>

// using namespace std; // EVITAR SU USO EN ARCHIVOS .H PARA BUENA PRACTICA
// solo usar las librerias necesarias

class Libro {
private:
  int codigo;
  char titulo[50];
  bool prestado;

public:
  // constructores
  Libro();
  Libro(int c, const char *t);

  // destructor
  ~Libro();

  // accesores (getters)
  int getCodigo() const;
  const char* getTitulo() const;
  bool getPrestado() const;


  // Modificadores (setters)
  void setCodigo(int c);
  void setTitulo(char t[50]);
  void setPrestado(bool p);

  
  void mostrarInfo() const;

};
#endif

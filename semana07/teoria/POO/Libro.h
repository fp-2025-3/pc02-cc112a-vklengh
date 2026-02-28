// GUARDIAS: EVITAR QUE SE REDEFINA LAS CLASES IMPLEMENTADAS
#ifndef LIBRO_H
#define LIBRO_H
#include <string>

// using namespace std; // EVITAR SU USO EN ARCHIVOS .H PARA BUENA PRACTICA
// solo usar las librerias necesarias 

class Libro {
private:
  std::string titulo;
  std::string autor;
  int paginas;

public:
  // constructores
  Libro();
  Libro(const std::string &t, const std::string &a, int p);

  // destructor
  ~Libro();

  // accesores (getters)
  std::string getTitulo() const;
  std::string getAutor() const;
  int getPaginas() const;

  // Modificadores (setters)
  void setTitulo(std::string &t);
  void setAutor(std::string &a);
  void setPaginas(int p);

  void mostrarInfo() const;
};
#endif

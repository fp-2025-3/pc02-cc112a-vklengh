#ifndef RECTANGULO_H 
#define RECTANGULO_H 
#include "figura.h"
#include <string>

class Rectangulo: public Figura {
private:
  double base;
  double altura;

public:
  // Constructores
  Rectangulo();
  // constructor de parametros
  Rectangulo(std::string nom, double r, double g, double b, double bas, double alt);
  // constructor de copia profunda (deep copy) vs shallow copy (el sistema lo
  // crea)
  Rectangulo(const Rectangulo &otro);
  // Redefinir el operador de asignacion
  // puntero oculto this
  Rectangulo &operator=(const Rectangulo &otro);
  ~Rectangulo();
  // Metodos virtuales puros
  Figura *copiar() const override;
  double area() const override ;
  double perimetro() const override ;
  void imprimir() const override;
};

#endif

#ifndef CIRCULO_H
#define CIRCULO_H
#include "figura.h"
#include <string>

class Circulo : public Figura {
private:
  double radio;

public:
  // Constructores
  Circulo();
  // constructor de parametros
  Circulo(std::string nom, double r, double g, double b, double rad);
  // constructor de copia profunda (deep copy) vs shallow copy (el sistema lo
  // crea)
  Circulo(const Circulo &otro);
  // Redefinir el operador de asignacion
  // puntero oculto this
  Circulo &operator=(const Circulo &otro);
  ~Circulo();
  // Metodos virtuales puros
  Figura *copiar() const override;
  double area() const override;
  double perimetro() const override;
  void imprimir() const override;
};

#endif

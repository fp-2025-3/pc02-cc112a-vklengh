#include "rectangulo.h"
#include "figura.h"
#include <cmath>
#include <iostream>

const double PI = acos(-1);
Rectangulo::Rectangulo() : Figura(), base(0.), altura(0.) {};

Rectangulo::Rectangulo(std::string nom, double r, double g, double b,
                       double bas, double alt)
    : Figura(nom, r, g, b), base(bas), altura(alt) {};

Rectangulo::Rectangulo(const Rectangulo &otro) : Figura(otro){
  base = otro.base;
  altura = otro.altura;
}
Rectangulo &Rectangulo::operator=(const Rectangulo &otro) {

  if (this != &otro) {
    Figura::operator=(otro); // copia parte de Figura
    base = otro.base;
    altura = otro.altura;
  }

  return *this;
}

Rectangulo::~Rectangulo() {};

Figura *Rectangulo::copiar() const { return new Rectangulo(*this); };
double Rectangulo::area() const { return base * altura; };

double Rectangulo::perimetro() const { return 2 * (base + altura); };

void Rectangulo::imprimir() const {
  Figura::imprimir();
  std::cout << "Base del rectangulo: " << base << std::endl;
  std::cout << "Altura del rectangulo: " << altura << std::endl;
  std::cout << "Area del rectangulo: " << Rectangulo::area() << std::endl;
  std::cout << "Perimetro del rectangulo: " << Rectangulo::perimetro()
            << std::endl;
};

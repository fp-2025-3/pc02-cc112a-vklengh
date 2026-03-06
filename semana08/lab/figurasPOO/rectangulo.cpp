#include "rectangulo.h"
#include "figura.h"
#include <cmath>
#include <iostream>

const double PI = acos(-1);
Rectangulo::Rectangulo() : Figura(), base(0.), altura(0.) {};

Rectangulo::Rectangulo(std::string nom, double r, double g, double b,
                       double bas, double alt)
    : Figura(nom, r, g, b), base(bas), altura(alt) {};

Rectangulo::Rectangulo(const Rectangulo &otro) : Figura(otro) {
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
std::string Rectangulo::getNombre() const { return nombre; };
double *Rectangulo::getColor() const { return colorRGB; };
SalidaInfo Rectangulo::getInfo() const {
  SalidaInfo info = Figura::getInfo();
  std::string texto = "Rectangulo:\n";
  texto.append(info.info);
  texto.append("Base: ");
  std::string temp = std::to_string(base);
  texto.append(temp.substr(0, temp.find(".") + 3));
  texto.append("\n");

  texto.append("Altura: ");
  temp = std::to_string(altura);
  texto.append(temp.substr(0, temp.find(".") + 3));

  texto.append("\n");

  texto.append("Area: ");
  double area = Rectangulo::area();
  temp = std::to_string(area);
  texto.append(temp.substr(0, temp.find(".") + 3));
  texto.append("\n");

  texto.append("Perimetro: ");
  double perimetro = Rectangulo::perimetro();
  temp = std::to_string(perimetro);
  texto.append(temp.substr(0, temp.find(".") + 3));

  texto.append("\n\n");
  info.info = texto;
  info.area = area;
  info.perimetro = perimetro;

  return info;
};

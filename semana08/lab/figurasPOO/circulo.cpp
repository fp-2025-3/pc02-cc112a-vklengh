#include "circulo.h"
#include "figura.h"
#include <cmath>
#include <iostream>

const double PI = acos(-1);
Circulo::Circulo() : Figura(), radio(0.) {};

Circulo::Circulo(std::string nom, double r, double g, double b, double rad)
    : Figura(nom, r, g, b), radio(rad) {};

Circulo::Circulo(const Circulo &otro) : Figura(otro) { radio = otro.radio; }
Circulo &Circulo::operator=(const Circulo &otro) {

  if (this != &otro) {
    Figura::operator=(otro); // copia parte de Figura
    radio = otro.radio;
  }

  return *this;
}

Circulo::~Circulo() {};

Figura *Circulo::copiar() const { return new Circulo(*this); };

double Circulo::area() const { return PI * pow(radio, 2); };

double Circulo::perimetro() const { return PI * radio * 2; };

void Circulo::imprimir() const {
  Figura::imprimir();
  std::cout << "Radio del circulo: " << radio << std::endl;
  std::cout << "Area del circulo: " << Circulo::area() << std::endl;
  std::cout << "Perimetro del circulo: " << Circulo::perimetro() << std::endl;
};

std::string Circulo::getNombre() const { return nombre; };
double *Circulo::getColor() const { return colorRGB; };
std::string Circulo::getInfo() const {
  std::string texto = "Circulo:\n";
  texto.append(Figura::getInfo());

  texto.append("Radio: ");
  std::string temp = std::to_string(radio);
  texto.append(temp.substr(0, temp.find(".") + 3));
  texto.append("\n");

  texto.append("Area: ");
  temp = std::to_string(Circulo::area());
  texto.append(temp.substr(0, temp.find(".") + 3));
  texto.append("\n");

  texto.append("Perimetro: ");
  temp = std::to_string(Circulo::perimetro());
  texto.append(temp.substr(0, temp.find(".") + 3));

  texto.append("\n\n");
  return texto;
};

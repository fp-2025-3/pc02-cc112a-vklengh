#include "sensorCircular.h"
#include <cmath>
#include <iostream>

const double PI = acos(-1);

SensorCircular::SensorCircular() : Sensor(), radio(0) {};

SensorCircular::SensorCircular(std::string i, double x, double y, double rad)
    :Sensor(i,x,y), radio(rad) {
};

SensorCircular::SensorCircular(const SensorCircular &otro):Sensor(otro),radio(otro.radio) {
}

SensorCircular &SensorCircular::operator=(const SensorCircular &otro) {
  if (this != &otro) {
    Sensor::operator=(otro); // copia parte de Figura
    radio= otro.radio;
  }

  return *this;
};

SensorCircular::~SensorCircular() { 
    delete[] posicion;
}

double SensorCircular::areaCobertura() const { return PI * pow(radio, 2); };
bool SensorCircular::detecta(double x, double y) const {
  double x0 = posicion[0];
  double y0 = posicion[1];
  if (pow((x - x0), 2) + pow((y - y0), 2) <= pow(radio, 2)) {
    return true;
  } else {
    return false;
  }
};

SalidaInfo SensorCircular::getInfo(double x,double y) const {
  SalidaInfo info = Sensor::getInfo(x, y);
  std::string texto = "Sensor Circular:\n";
  texto.append(info.info);

  texto.append("Radio: ");
  std::string temp = std::to_string(radio);
  texto.append(temp.substr(0, temp.find(".") + 3));
  texto.append("\n");

  texto.append("Area cobertura: ");
  double area = SensorCircular::areaCobertura();
  temp = std::to_string(area);
  texto.append(temp.substr(0, temp.find(".") + 3));
  texto.append("\n");

  texto.append("Cobertura: ");
  bool cobertura= SensorCircular::detecta(x,y);
  texto.append(cobertura?"Si":"No");
  texto.append("\n\n");
  info.info = texto;
  info.area= area;
  info.detecta = cobertura;

  return info;
};

void SensorCircular::imprimir() const {
  Sensor::imprimir();
  std::cout << "Radio: " << radio << std::endl;
};
Sensor *SensorCircular::copiar() const { return new SensorCircular(*this); };

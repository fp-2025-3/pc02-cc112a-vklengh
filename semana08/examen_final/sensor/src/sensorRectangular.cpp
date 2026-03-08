#include "sensorRectangular.h"
#include <iostream>

SensorRectangular::SensorRectangular() : Sensor(), alto(0), ancho(0) {};

SensorRectangular::SensorRectangular(std::string i, double x, double y,
                                     double anch, double alt)
    : Sensor(i, x, y), ancho(anch), alto(alt) {};

SensorRectangular::SensorRectangular(const SensorRectangular &otro): Sensor(otro),alto(otro.alto),ancho(otro.ancho) {}

SensorRectangular &SensorRectangular::operator=(const SensorRectangular &otro) {
  if (this != &otro) {
    Sensor::operator=(otro); // copia parte de Figura
    alto = otro.alto;
    ancho = otro.ancho;
  }

  return *this;
};

SensorRectangular::~SensorRectangular() { delete[] posicion; }

double SensorRectangular::areaCobertura() const { return alto * ancho; };
bool SensorRectangular::detecta(double x, double y) const {
  double x0 = posicion[0];
  double y0 = posicion[1];
  if (x >= x0 - ancho / 2 and x <= x0 + ancho / 2 and y >= y0 - alto / 2 and
      y <= y0 + alto / 2) {
    return true;
  } else {
    return false;
  }
};

void SensorRectangular::imprimir() const {
  Sensor::imprimir();
  std::cout << "Alto: " << alto << std::endl;
  std::cout << "Ancho: " << ancho << std::endl;
};
Sensor *SensorRectangular::copiar() const {
  return new SensorRectangular(*this);
};

SalidaInfo SensorRectangular::getInfo(double x,double y) const {
  SalidaInfo info = Sensor::getInfo(x, y);
  std::string texto = "Sensor Rectangular:\n";
  texto.append(info.info);

  texto.append("Alto: ");
  std::string temp = std::to_string(alto);
  texto.append(temp.substr(0, temp.find(".") + 3));
  texto.append("\n");

  texto.append("Ancho: ");
  temp = std::to_string(ancho);
  texto.append(temp.substr(0, temp.find(".") + 3));
  texto.append("\n");

  texto.append("Area cobertura: ");
  double area = SensorRectangular::areaCobertura();
  temp = std::to_string(area);
  texto.append(temp.substr(0, temp.find(".") + 3));
  texto.append("\n");

  texto.append("Cobertura: ");
  bool cobertura= SensorRectangular::detecta(x,y);
  texto.append(cobertura?"Si":"No");
  texto.append("\n\n");
  info.info = texto;
  info.area= area;
  info.detecta = cobertura;

  return info;
};

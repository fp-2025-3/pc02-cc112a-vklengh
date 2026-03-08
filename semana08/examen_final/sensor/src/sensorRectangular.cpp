#include "sensorRectangular.h"
#include <cmath>
#include <iostream>

SensorRectangular::SensorRectangular() {
  id = "";
  posicion = new double[2];
};

SensorRectangular::SensorRectangular(std::string i, double x, double y,
                                     double *pos, double anch, double alt)
    : Sensor(i, x, y, pos), ancho(anch), alto(alt) {};

SensorRectangular::SensorRectangular(const SensorRectangular &otro) {
  id = otro.id;

  if (otro.posicion) {
    posicion = new double[2];
    for (int i = 0; i < 2; i++)
      posicion[i] = otro.posicion[i];
  } else {
    posicion = nullptr;
  }
}

SensorRectangular &SensorRectangular::operator=(const SensorRectangular &otro) {
  if (this != &otro) {
    id = otro.id;
    delete[] posicion;

    if (otro.posicion) {
      posicion = new double[2];
      for (int i = 0; i < 3; i++)
        posicion[i] = otro.posicion[i];
    } else {
      posicion = nullptr;
    }
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
  std::cout << "Alto: " << alto;
  std::cout << "Ancho: " << ancho;
};
Sensor *SensorRectangular::copiar() const {
  return new SensorRectangular(*this);
};

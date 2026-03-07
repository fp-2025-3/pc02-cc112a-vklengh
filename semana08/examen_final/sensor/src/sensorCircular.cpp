#include "sensorCircular.h"
#include <cmath>
#include <iostream>

const double PI = acos(-1);

SensorCircular::SensorCircular() {
  id = "";
  posicion = new double[2];
};

SensorCircular::SensorCircular(std::string i, double x, double y, double *pos,
                               double rad)
    : Sensor(i, x, y, pos), radio(rad) {};

SensorCircular::SensorCircular(const SensorCircular &otro) {
  id = otro.id;

  if (otro.posicion) {
    posicion = new double[2];
    for (int i = 0; i < 2; i++)
      posicion[i] = otro.posicion[i];
  } else {
    posicion = nullptr;
  }
}

SensorCircular &SensorCircular::operator=(const SensorCircular &otro) {
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

SensorCircular::~SensorCircular() { delete[] posicion; }

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

void SensorCircular::imprimir() const {
  Sensor::imprimir();
  std::cout << "Radio: " << radio;
};
Sensor *SensorCircular::copiar() const { return new SensorCircular(*this); };

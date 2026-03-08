#include "sensor.h"
#include <iostream>

Sensor::Sensor() {
  id = "";
  posicion = new double[2];
};

Sensor::Sensor(std::string i, double x, double y, double *pos) : id(i) {
  posicion = new double[2];
  posicion[0] = x;
  posicion[1] = y;
};

Sensor::Sensor(const Sensor &otro) {
  id = otro.id;

  if (otro.posicion) {
    posicion = new double[2];
    for (int i = 0; i < 2; i++)
      posicion[i] = otro.posicion[i];
  } else {
    posicion = nullptr;
  }
}

Sensor &Sensor::operator=(const Sensor &otro) {
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

Sensor::~Sensor() { delete[] posicion; }

void Sensor::imprimir() const {
  std::cout << "ID: " << id;
  std::cout << "X: " << posicion[0] << std::endl;
  std::cout << "Y: " << posicion[1] << std::endl;
};

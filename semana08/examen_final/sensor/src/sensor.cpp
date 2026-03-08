#include "sensor.h"
#include <iostream>

Sensor::Sensor() {
  id = "";
  posicion = new double[2];
  posicion[0] = 0;
  posicion[1] = 0;
};

Sensor::Sensor(std::string i, double x, double y) : id(i) {
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
      for (int i = 0; i < 2; i++)
        posicion[i] = otro.posicion[i];
    } else {
      posicion = nullptr;
    }
  }

  return *this;
};

// Sensor::~Sensor() { delete[] posicion; }

void Sensor::imprimir() const {
  std::cout << "ID: " << id << std::endl;
  std::cout << "X: " << posicion[0] << std::endl;
  std::cout << "Y: " << posicion[1] << std::endl;
};

SalidaInfo Sensor::getInfo(double x, double y) const {
  std::string texto = "";
  texto.append("ID: ");
  texto.append(id);
  texto.append("\n");

  for (int i = 0; i < 2; i++) {
    if (i == 0) {
      texto.append("X: ");
    }
    else if (i == 1) {
      texto.append("Y: ");
    }
    std::string color = std::to_string(posicion[i]);
    texto.append(color.substr(0, color.find(".") + 3));
    texto.append("\n");
  }
  SalidaInfo out = SalidaInfo{texto,0,false};

  return out;
};

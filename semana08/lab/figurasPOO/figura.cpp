#include "figura.h"
#include <iostream>

Figura::Figura() {
  nombre = "";
  colorRGB = new double[3];
  colorRGB[0] = 0;
  colorRGB[1] = 0;
  colorRGB[2] = 0;
};

Figura::Figura(std::string nom, double r, double g, double b) : nombre(nom) {
  colorRGB = new double[3];
  colorRGB[0] = r;
  colorRGB[1] = g;
  colorRGB[2] = b;
};

Figura::Figura(const Figura &otro) {
  nombre = otro.nombre;

  if (otro.colorRGB) {
    colorRGB = new double[3];
    for (int i = 0; i < 3; i++)
      colorRGB[i] = otro.colorRGB[i];
  } else {
    colorRGB = nullptr;
  }
}

Figura &Figura::operator=(const Figura &otro) {
  if (this != &otro) {
    nombre = otro.nombre;
    delete[] colorRGB;

    if (otro.colorRGB) {
      colorRGB = new double[3];
      for (int i = 0; i < 3; i++)
        colorRGB[i] = otro.colorRGB[i];
    } else {
      colorRGB = nullptr;
    }
  }

  return *this;
};

Figura::~Figura() { delete[] colorRGB; }

void Figura::imprimir() const {
  std::cout << "Nombre: " << nombre << std::endl;
  std::cout << "Colores R: " << colorRGB[0] << " | G: " << colorRGB[1]
            << " | B: " << colorRGB[2] << std::endl;
};

std::string Figura::getNombre() const { return nombre; };
double *Figura::getColor() const { return colorRGB; };

std::string Figura::getInfo() const {
  std::string texto = "";
  texto.append("Nombre: ");
  texto.append(nombre);
  texto.append("\n");

  for (int i = 0; i < 3; i++) {
    if (i == 0) {
      texto.append("Color R: ");
    }
    else if (i == 1) {
      texto.append("Color G: ");
    }
    else if (i == 2) {
      texto.append("Color B: ");
    }
    std::string color = std::to_string(colorRGB[i]);
    texto.append(color.substr(0, color.find(".") + 3));
    texto.append("\n");
  }

  return texto;
};

#include "gestorFiguras.h"
#include "figura.h"
#include <fstream>
#include <iostream>
#include <string>

GestorFiguras::GestorFiguras() {
  cantidad = 0;
  capacidad = 0;
  figuras = new Figura *[capacidad];
  for (int i = 0; i < capacidad; i++) {
    figuras[i] = nullptr;
  }
}

GestorFiguras &GestorFiguras::operator=(GestorFiguras &otro) {
  if (this != &otro) {
    cantidad = otro.cantidad;
    capacidad = otro.capacidad;
    for (int i = 0; i < capacidad; i++) {
      delete figuras[i];
    }
    delete[] figuras;
    figuras = new Figura *[capacidad];
    for (int i = 0; i < cantidad; i++) {
      figuras[i] = otro.figuras[i]->copiar(); // no copia el contenido del
                                              // puntero, solo toma la direccion
    }
  }
  return *this;
};

GestorFiguras::GestorFiguras(Figura **fig, int cant, int cap)
    : cantidad(cant), capacidad(cap) {
  figuras = new Figura *[capacidad];

  for (int i = 0; i < capacidad; i++) {
    if (i < cantidad) {
      figuras[i] = fig[i];
    } else {
      figuras[i] = nullptr;
    }
  }
};

GestorFiguras::~GestorFiguras() {
  for (int i = 0; i < cantidad; i++) {
    delete figuras[i];
  }
  delete[] figuras;
};

void GestorFiguras::agregarFiguras(Figura *f) {
  if (cantidad < capacidad) {
    std::cout << "Espacio disponible para agregar figuras" << std::endl;
  } else {
    std::cout << "Capacidad llena, redimensionando..." << std::endl;
    // REDIMENSIONAR AL DOBLE
    GestorFiguras::aumentarCapacidad(capacidad);
  }
  figuras[cantidad] = f->copiar();
  cantidad++;
};
void GestorFiguras::aumentarCapacidad(int cap) {
  if (cap > 0) {
    int nuevaCapacidad = capacidad + cap;
    Figura **nuevo = new Figura *[nuevaCapacidad];
    for (int i = 0; i < cantidad; i++) {
      nuevo[i] = figuras[i];
    }
    for (int i = cantidad; i < nuevaCapacidad; i++) {
      nuevo[i] = nullptr;
    }
    delete[] figuras;
    figuras = nuevo;
    capacidad = nuevaCapacidad;
    std::cout << "Se aumento la capacidad a: " << capacidad << std::endl;
  } else {
    std::cerr << "La capacidad adicional debe ser positiva.\n";
  }
}

void GestorFiguras::mostrarFiguras() {
  for (int i = 0; i < cantidad; i++) {
    figuras[i]->imprimir();
  }
};

void GestorFiguras::mostrarCapacidad() {
  std::cout << "Capacidad: " << capacidad << std::endl;
};
double GestorFiguras::area() {
  double area = 0;
  for (int i = 0; i < cantidad; i++) {
    area += figuras[i]->area();
  }
  return area;
};
double GestorFiguras::perimetro() {
  double perimetro = 0;
  for (int i = 0; i < cantidad; i++) {
    perimetro += figuras[i]->perimetro();
  }
  return perimetro;
};
std::string GestorFiguras::getInfo() {
  std::string info = "";
  double perimetroTotal = 0.;
  double areaTotal = 0.;
  for (int i = 0; i < cantidad; i++) {
    SalidaInfo figInfo = figuras[i]->getInfo();
    perimetroTotal += figInfo.perimetro;
    areaTotal += figInfo.area;
    info.append(figInfo.info);
  }
  info.append("Area total: ");
  std::string temp = std::to_string(areaTotal);
  info.append(temp.substr(0, temp.find(".") + 3));
  info.append("\n");

  info.append("Perimetro: ");
  temp = std::to_string(perimetroTotal);
  info.append(temp.substr(0, temp.find(".") + 3));
  info.append("\n");

  return info;
};

void GestorFiguras::guardarArchivo(std::string &direccion) {
  std::ofstream archivo;
  archivo.open(direccion);
  if (!archivo) {
    std::cerr << "No se pudo abrir el archivo\n";
    return;
  }
  std::string info = GestorFiguras::getInfo();
  archivo << info;
  archivo.close();
  std::cout << "Archivo guardado correctamente\n";
};

#include "sistemaSensores.h"
#include "sensor.h"
#include <fstream>
#include <iostream>
#include <string>

bool SistemaSensores::detectarError() const {
  if (cantidad == 0) {
    std::cerr
        << "No se puede realizar esta operacion sin sensores registrados.\n";
    return true;
  }
  return false;
}

SistemaSensores::SistemaSensores() {
  cantidad = 0;
  capacidad = 0;
  sensores = new Sensor *[capacidad];
  for (int i = 0; i < capacidad; i++) {
    sensores[i] = nullptr;
  }
}

SistemaSensores &SistemaSensores::operator=(SistemaSensores &otro) {
  if (this != &otro) {
    cantidad = otro.cantidad;
    capacidad = otro.capacidad;
    for (int i = 0; i < capacidad; i++) {
      delete sensores[i];
    }
    delete[] sensores;
    sensores = new Sensor *[capacidad];
    for (int i = 0; i < cantidad; i++) {
      sensores[i] =
          otro.sensores[i]->copiar(); // no copia el contenido del
                                      // puntero, solo toma la direccion
    }
  }
  return *this;
};

SistemaSensores::SistemaSensores(Sensor **sens, int cant, int cap)
    : cantidad(cant), capacidad(cap) {
  sensores = new Sensor *[capacidad];

  for (int i = 0; i < capacidad; i++) {
    if (i < cantidad) {
      sensores[i] = sens[i];
    } else {
      sensores[i] = nullptr;
    }
  }
};

SistemaSensores::~SistemaSensores() {
  for (int i = 0; i < cantidad; i++) {
    delete sensores[i];
  }
  delete[] sensores;
};

void SistemaSensores::agregarSensor(Sensor *s) {
  if (cantidad < capacidad) {
    std::cout << "Espacio disponible para agregar sensores" << std::endl;
  } else {
    std::cout << "Capacidad llena, redimensionando..." << std::endl;
    // REDIMENSIONAR AL DOBLE
    if (capacidad == 0) {
      SistemaSensores::aumentarCapacidad(1);
    }
    else{
      SistemaSensores::aumentarCapacidad(capacidad);
    }
  }
  sensores[cantidad] = s->copiar();
  cantidad++;
};
void SistemaSensores::aumentarCapacidad(int cap) {
  if (cap > 0) {
    int nuevaCapacidad = capacidad + cap;
    Sensor **nuevo = new Sensor *[nuevaCapacidad];
    for (int i = 0; i < cantidad; i++) {
      nuevo[i] = sensores[i];
    }
    for (int i = cantidad; i < nuevaCapacidad; i++) {
      nuevo[i] = nullptr;
    }
    delete[] sensores;
    sensores = nuevo;
    capacidad = nuevaCapacidad;
    std::cout << "Se aumento la capacidad a: " << capacidad << std::endl;
  } else {
    std::cerr << "La capacidad adicional debe ser positiva.\n";
  }
}

void SistemaSensores::mostrarSensores() const {
  for (int i = 0; i < cantidad; i++) {
    sensores[i]->imprimir();
  }
};

void SistemaSensores::mostrarCapacidad() const {
  std::cout << "Capacidad: " << capacidad << std::endl;
};
double SistemaSensores::areaTotalCobertura() const {
  double area = 0;
  for (int i = 0; i < cantidad; i++) {
    area += sensores[i]->areaCobertura();
  }
  return area;
};
std::string SistemaSensores::getInfo(double x, double y) const {
  std::string info = "";
  double areaTotal = 0.;
  for (int i = 0; i < cantidad; i++) {
    SalidaInfo figInfo = sensores[i]->getInfo(x, y);
    areaTotal += figInfo.area;
    info.append(figInfo.info);
  }
  info.append("Area total: ");
  std::string temp = std::to_string(areaTotal);
  info.append(temp.substr(0, temp.find(".") + 3));
  info.append("\n");

  return info;
};

void SistemaSensores::guardarArchivo(std::string &direccion) {
  std::ofstream archivo;
  archivo.open(direccion);
  if (!archivo) {
    std::cerr << "No se pudo abrir el archivo\n";
    return;
  }
  double x, y;
  std::cout << "Ingrese las coordenadas X: ";
  std::cin >> x;
  std::cout << " Y: ";
  std::cin >> y;
  std::string info = SistemaSensores::getInfo(x, y);
  archivo << info;
  archivo.close();
  std::cout << "Archivo guardado correctamente\n";
};
int SistemaSensores::sensoresQueDetectan(double x, double y) const {
  int cantSensores = 0;
  for (int i = 0; i < cantidad; i++) {
    cantSensores += sensores[i]->detecta(x, y);
  }
  return cantSensores;
};
Sensor *SistemaSensores::sensorMayorCobertura() const {
  Sensor *s = sensores[0];
  for (int i = 1; i < cantidad; i++) {
    if (sensores[i]->areaCobertura() > s->areaCobertura()) {
      s = sensores[i];
    }
  }
  return s;
};

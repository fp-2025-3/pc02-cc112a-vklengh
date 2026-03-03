#include "Vehiculo.h"
#include <fstream>
#include <iostream>

using namespace std;

Vehiculo::Vehiculo()
    : placa("desconocido"), marca("desconocido"), anio(0), precio(0.0) {};
Vehiculo::Vehiculo(string nPlaca, string marcaVehiculo, int anioVehiculo,
                   double precioVehiculo)
    : placa(nPlaca), marca(marcaVehiculo), anio(anioVehiculo),
      precio(precioVehiculo) {};
void Vehiculo::mostrarInfo() const {
  cout << "Placa: " << placa << endl;
  cout << "Marca: " << marca << endl;
  cout << "Anio: " << anio << endl;
  cout << "Precio: " << precio << endl;
};
void Vehiculo::registrarVehiculo() {
  // Registro manual
  cout << "Ingrese el numero de placa: ";
  cin.ignore();
  getline(cin, placa);
  cout << "Ingrese la marca: ";
  getline(cin, marca);
  cout << "Ingrese el anio: ";
  cin >> anio;
  cout << "Ingrese el precio: ";
  cin >> precio;
};
Vehiculo::~Vehiculo() { cout << "Llamado destructor de Vehiculo\n"; };

Automovil::Automovil() : Vehiculo(), numeroPuertas(0) {};
Automovil::Automovil(string p, string m, int a, double pr, int nP)
    : Vehiculo(p, m, a, pr), numeroPuertas(nP) {};
void Automovil::mostrarInfo() const {
  cout << "Automovil\n";
  Vehiculo::mostrarInfo();
  cout << "Numero puertas: " << numeroPuertas << endl;
};
void Automovil::registrarVehiculo() {
  // Registro manual
  cout << "Ingrese datos del automovil\n";
  Vehiculo::registrarVehiculo();
  cout << "Ingrese el numero de puertas: ";
  cin >> numeroPuertas;
};
double Automovil::calcularPrecioFinal() const {
  double precioFinal = precio * 1.05;
  cout << "Precio final: " << precioFinal << endl;
  return precioFinal;
};
void Automovil::guardar(ofstream &out) const {
  if (!out) {
    cerr << "No se pudo abrir el archivo de guardado\n.";
    return;
  }

  out.close();
};
void Automovil::cargar(ifstream &out) {};
Automovil::~Automovil() { cout << "Llamado destructor de Automovil\n"; };

Camion::Camion() : Vehiculo(), capacidadCarga(0.) {};
Camion::Camion(string p, string m, int a, double pr, double cC)
    : Vehiculo(p, m, a, pr), capacidadCarga(cC) {};
void Camion::mostrarInfo() const {
  cout << "Camion\n";
  Vehiculo::mostrarInfo();
  cout << "Capacidad de carga: " << capacidadCarga << endl;
};
void Camion::registrarVehiculo() {
  // Registro manual
  cout << "Ingrese datos del camion\n";
  Vehiculo::registrarVehiculo();
  cout << "Ingrese la capacidad de carga (en toneladas): ";
  cin >> capacidadCarga;
};
double Camion::calcularPrecioFinal() const {
  double precioFinal = precio * 1.12;
  cout << "Precio final: " << precioFinal << endl;
  return precioFinal;
};
void Camion::guardar(ofstream &out) const {};
void Camion::cargar(ifstream &out) {};

Camion::~Camion() { cout << "Llamado destructor de Camion\n"; };

Motocicleta::Motocicleta() : Vehiculo(), potencia(0.) {};
Motocicleta::Motocicleta(string p, string m, int a, double pr, double pot)
    : Vehiculo(p, m, a, pr), potencia(pot) {};
void Motocicleta::mostrarInfo() const {
  cout << "Motocicleta\n";
  Vehiculo::mostrarInfo();
  cout << "Potencia: " << potencia << endl;
};
void Motocicleta::registrarVehiculo() {
  // Registro manual
  cout << "Ingrese datos de la motocicleta\n";
  Vehiculo::registrarVehiculo();
  cout << "Ingrese la potencia: ";
  cin >> potencia;
};
double Motocicleta::calcularPrecioFinal() const {
  double precioFinal = precio * 1.03;
  cout << "Precio final: " << precioFinal << endl;
  return precioFinal;
};
void Motocicleta::guardar(ofstream &out) const {};
void Motocicleta::cargar(ifstream &out) {};
Motocicleta::~Motocicleta() { cout << "Llamado destructor de Motocicleta\n"; };

#include "Vehiculo.h"
#include <iostream>

using namespace std;

int main() {
  Vehiculo *p[] = {new Motocicleta("AB12", "Yamaha", 2020, 4000, 50000),
                   // new Vehiculo,
                   new Automovil("CD34", "Toyota", 2021, 50000, 12),
                   new Camion("EF56", "Hyundai", 2022, 100000, 100)};

  // Manual
  // Vehiculo *p[] = {new Motocicleta, new Automovil, new Camion};
  // // Polimorfismo
  // for (int i = 0; i < 3; i++) {
  //   p[i]->registrarVehiculo();
  //   cout << endl;
  // }

  for (int i = 0; i < 3; i++) {
    p[i]->mostrarInfo();
    p[i]->calcularPrecioFinal();
    cout << endl;
  }

  for (int i = 0; i < 3; i++) {
    delete p[i];
  }
  return 0;
}

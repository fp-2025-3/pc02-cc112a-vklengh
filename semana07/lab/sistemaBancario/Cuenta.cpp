#include "Cuenta.h"
#include <iostream>

using namespace std;

Cuenta::Cuenta() {
  numero = 0;
  titular = "Desconocido";
  saldo = 0.;
  activo = true;
};
Cuenta::Cuenta(int num, string nombre, double saldoInicial)
    : numero(num), titular(nombre), saldo(saldoInicial) {};

Cuenta::~Cuenta() {};

// setters
void Cuenta::depositar(double monto) { saldo += monto; };
void Cuenta::retirar(double monto) { saldo -= monto; };

void Cuenta::mostrarCuenta() {
  cout << "Cuenta: " << numero << endl;
  cout << "Titular: " << titular << endl;
  cout << "Saldo: " << saldo << endl;
};

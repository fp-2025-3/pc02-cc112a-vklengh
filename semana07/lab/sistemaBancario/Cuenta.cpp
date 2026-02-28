#include "Cuenta.h"
#include <cmath>
#include <iostream>

using namespace std;

Cuenta::Cuenta() {
  numero = 0;
  titular = "Desconocido";
  saldo = 0.;
  bloqueado = false;
};
Cuenta::Cuenta(int num, string nombre, double saldoInicial)
    : numero(num), titular(nombre), saldo(saldoInicial), bloqueado(false) {};

Cuenta::~Cuenta() {};

// getters
int Cuenta::getNumeroCuenta() { return numero; }
double Cuenta::getSaldo() { return saldo; }
bool Cuenta::getEstado() { return bloqueado; }

// setters
void Cuenta::setSaldo(double monto) { saldo = monto; };

bool Cuenta::depositar(double monto) {
  if (!bloqueado) {
    if (saldo - monto < 0) {
      cout << "No cuenta con saldo suficiente para esta operación.\n";
      return false;
    } else {
      saldo -= monto;
      return true;
    }
  } else {
    cout << "No se puede depositar, la cuenta esta bloqueada\n";
    return false;
  }
};

void Cuenta::retirar(double monto) {
  if (!bloqueado) {
    if (saldo - monto < 0) {
      cout << "No cuenta con saldo suficiente para esta operación.\n";
    } else {
      saldo -= monto;
      cout << "Se realizó el retiro con exito\n";
    }
  } else {
    cout << "No se puede retirar, la cuenta esta bloqueada\n";
  }
};

void Cuenta::mostrarCuenta() {
  cout << "Cuenta: " << numero << endl;
  cout << "Titular: " << titular << endl;
  cout << "Saldo: " << saldo << endl;
  cout << "Estado de cuenta: " << (bloqueado ? "BLOQUEADO" : "ACTIVO") << endl;
};

void Cuenta::interesMensual(double tasa, int meses) {
  saldo *= pow(1 + tasa, meses);
};

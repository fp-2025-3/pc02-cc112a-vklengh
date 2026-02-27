#include "Banco.h"
#include <iostream>

using namespace std;

Banco::Banco() {
  cantidadCuentas = 0;
  for (int i = 0; i < MAX_CUENTAS; i++) {
    Cuenta();
  }
};

Banco::Banco(int numeros[], std::string titulares[], double saldos[], int n)
    : cantidadCuentas(n) {
  for (int i = 0; i < n; i++) {
    if (n >= MAX_CUENTAS) {
      cerr << "Se sobrepaso la cantidad maxima de cuentas, no se pueden "
              "registrar mas cuentas.\n";
      break;
    }
    Cuenta(numeros[i], titulares[i], saldos[i]);
  }
};

int Banco::getCantidadCuentas() { return cantidadCuentas; };

int Banco::buscarCuenta(int numeroCuenta) {
  for (int i = 0; i < cantidadCuentas; i++) {
    if (numeroCuenta == cuentas[i].getNumeroCuenta()) {
      return i;
    }
  }
  return -1;
};

void Banco::transferir(int cuentaDepositante, int cuentaReceptora,
                       double monto) {
  if (monto <= 0) {
    cerr << "Se ingreso un monto inválido, intente nuevamente\n";
    return;
  }
  if (cuentaDepositante == cuentaReceptora) {
    cerr << "No se puede hacer la operación en la misma cuenta.\n";
    return;
  }
  int idxDepositante = buscarCuenta(cuentaDepositante);
  int idxReceptor = buscarCuenta(cuentaReceptora);
  if (idxDepositante >= 0 and idxReceptor >= 0) {
    bool depositado = cuentas[idxDepositante].depositar(monto);
    if (depositado) {
      double saldoActual = cuentas[idxReceptor].getSaldo();
      cuentas[idxReceptor].setSaldo(saldoActual + monto);
      cout << "Se realizó el deposito con exito\n";
    }
  } else {
    cerr << "Datos ingresados incorrectos, intente nuevamente\n";
  }
};

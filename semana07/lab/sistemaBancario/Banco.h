#ifndef BANCO_H
#define BANCO_H
#include "Cuenta.h"
#include <string>

const int MAX_CUENTAS = 100;
class Banco {
private:
  Cuenta cuentas[MAX_CUENTAS];
  int cantidadCuentas;

public:
  Banco();
  Banco(int numeros[], std::string titulares[], double saldos[], int n);
  ~Banco();
  int getCantidadCuentas();
  void transferir(int cuentaDepositante, int cuentaReceptora, double monto);
  int buscarCuenta(int numeroCuenta);
};
#endif

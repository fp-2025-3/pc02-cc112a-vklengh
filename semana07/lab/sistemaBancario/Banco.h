#ifndef BANCO_H
#define BANCO_H
#include "Cuenta.h"
#include <string>

const int MAX_CUENTAS = 100;
class Banco {
private:
  Cuenta cuentas[MAX_CUENTAS];

public:
  Banco();
  Banco(int numeros[], std::string titulares[], double saldos[], int n);
  ~Banco();
  void transferir(int cuentaDepositante, int cuentaReceptora);

};
#endif

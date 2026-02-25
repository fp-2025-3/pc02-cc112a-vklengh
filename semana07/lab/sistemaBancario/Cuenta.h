#ifndef CUENTA_H
#define CUENTA_H
#include <string>

class Cuenta {
private:
  int numero;
  std::string titular;
  double saldo;
  bool activo;

public:
  Cuenta();
  Cuenta(int num, std::string nombre, double saldoInicial);
  ~Cuenta();
  void depositar(double monto);
  void retirar(double monto);
  void mostrarCuenta();
  void interesMensual(int meses);
  void bloquearCuenta();
};
#endif

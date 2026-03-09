#ifndef CUENTA_H
#define CUENTA_H
#include <string>

class Cuenta {
private:
  int numero;
  std::string titular;
  double saldo;
  bool bloqueado;

public:
  Cuenta();
  Cuenta(int num, std::string nombre, double saldoInicial);
  ~Cuenta();
  int getNumeroCuenta();
  double getSaldo();
  bool getEstado();
  void setSaldo(double monto);
  bool depositar(double monto);
  void retirar(double monto);
  void mostrarCuenta();
  void interesMensual(double tasa, int meses);
};
#endif

#include <iostream>
#include <string>
using namespace std;

struct Cuenta {
    int numero;
    string titular;
    double saldo;
};

// Variable global
Cuenta cuentaGlobal;

// Crear cuenta
void crearCuenta(int num, string nombre, double saldoInicial) {
    cuentaGlobal.numero = num;
    cuentaGlobal.titular = nombre;
    cuentaGlobal.saldo = saldoInicial;
}

// Depositar
void depositar(double monto) {
    cuentaGlobal.saldo += monto;
}

// Retirar
void retirar(double monto) {
    cuentaGlobal.saldo -= monto;
}

// Mostrar información
void mostrarCuenta() {
    cout << "Cuenta: " << cuentaGlobal.numero << endl;
    cout << "Titular: " << cuentaGlobal.titular << endl;
    cout << "Saldo: " << cuentaGlobal.saldo << endl;
}

int main() {
    crearCuenta(123, "Carlos", 1000);
    retirar(1500);   // ¿Qué pasa aquí?
    mostrarCuenta();
    return 0;
}

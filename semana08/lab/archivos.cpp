#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;

struct CuentaBancaria {
  int numeroCuenta;
  char titular[40];
  double saldo;
  bool activa;
};

void leerArchivo() {
  ifstream archivo;
  archivo.open("cuentas.dat", ios::binary);
  if (!archivo) {
    cerr << "No se pudo abrir el achivo\n";
    return;
  }
  CuentaBancaria temp;
  while (archivo.read((char *)&temp, sizeof(CuentaBancaria))) {
    cout << "Numero de cuenta: " << temp.numeroCuenta << endl;
    cout << "Nombre del titular: " << temp.titular << endl;
    cout << "Saldo: " << temp.saldo << endl;
    cout << "Estado de cuenta: " << (temp.activa ? "ACTIVA" : "INACTIVA") << endl;
  }

  archivo.close();
}

void mostrarCuentasActivas() {
  ifstream archivo;
  archivo.open("cuentas.dat", ios::binary);
  if (!archivo) {
    cerr << "No se pudo abrir el achivo\n";
    return;
  }
  CuentaBancaria temp;
  while (archivo.read((char *)&temp, sizeof(CuentaBancaria))) {
    if (temp.activa) {
      cout << "Numero de cuenta: " << temp.numeroCuenta << endl;
      cout << "Nombre del titular: " << temp.titular << endl;
      cout << "Saldo: " << temp.saldo << endl;
      cout << "Estado de cuenta: " << (temp.activa ? "ACTIVA" : "INACTIVA") << endl;
    }
  }
  archivo.close();
}

bool buscarCuenta(int codigo) {
  ifstream archivo;
  archivo.open("cuentas.dat", ios::binary);
  if (!archivo) {
    cerr << "No existe el archivo\n";
    return false;
  }
  CuentaBancaria temp;

  archivo.seekg(-sizeof(CuentaBancaria), ios::end);
  archivo.read((char *)&temp, sizeof(CuentaBancaria));
  if (codigo > temp.numeroCuenta or codigo <= 0) {
    cerr << "No se encuentra en la lista\n"; // fuera de rango
    archivo.close();
    return false;
  } else {
    archivo.seekg((codigo - 1) * sizeof(CuentaBancaria), ios::beg);
    archivo.read((char *)&temp, sizeof(CuentaBancaria));
    if (temp.numeroCuenta != 0 and strcmp(temp.titular, "") > 0) {
      cout << temp.numeroCuenta << " " << temp.titular << " " << temp.activa
           << endl;
      archivo.close();
      return true;
    } else {
      cerr << "No se encuentra en la lista\n"; // datos llenados de forma
      // predeterminada y vacios
      archivo.close();
      return false;
    }
  }
}
void activarCuenta(int codigo) {
  fstream archivo;
  archivo.open("cuentas.dat", ios::binary | ios::out | ios::in);

  if (!archivo) {
    cerr << "No existe el archivo\n";
    return;
  }
  bool cuentaEncontrada = buscarCuenta(codigo);
  if (cuentaEncontrada) {
    CuentaBancaria temp;
    archivo.seekg((codigo - 1) * sizeof(CuentaBancaria), ios::beg);
    archivo.read((char *)&temp, sizeof(CuentaBancaria));
    temp.activa = true;
    archivo.seekp((codigo - 1) * sizeof(CuentaBancaria), ios::beg);
    archivo.write((char *)&temp, sizeof(CuentaBancaria));
  }
  archivo.close();
}

void desactivarCuenta(int codigo) {
  fstream archivo;
  archivo.open("cuentas.dat", ios::binary | ios::out | ios::in);

  if (!archivo) {
    cerr << "No existe el archivo\n";
    return;
  }
  bool cuentaEncontrada = buscarCuenta(codigo);
  if (cuentaEncontrada) {
    CuentaBancaria temp;
    archivo.seekg((codigo - 1) * sizeof(CuentaBancaria), ios::beg);
    archivo.read((char *)&temp, sizeof(CuentaBancaria));
    temp.activa = false;
    archivo.seekp((codigo - 1) * sizeof(CuentaBancaria), ios::beg);
    archivo.write((char *)&temp, sizeof(CuentaBancaria));
  }
  archivo.close();
}

void crearArchivo(int N) {

  fstream archivo("cuentas.dat", ios::binary | ios::out | ios::in);

  if (!archivo) {
    // Si no existe lo creamos
    archivo.open("cuentas.dat", ios::out | ios::binary);

    archivo.close();

    archivo.open("cuentas.dat", ios::binary | ios::out | ios::in);
  }

  CuentaBancaria cuenta;

  for (int i = 0; i < N; ++i) {

    cout << "Numero de cuenta " << i + 1 << endl;
    cin >> cuenta.numeroCuenta;

    int posicion = sizeof(CuentaBancaria) * (cuenta.numeroCuenta - 1);

    // Movemos el puntero de lectura (seekg) a posicion
    archivo.seekg(posicion);

    // Creamos un objeto temporal para verificar si hay registros en esa
    // posision
    CuentaBancaria temp;
    archivo.read((char *)&temp, sizeof(CuentaBancaria));

    // cout << temp.numeroCuenta<< " "<<temp.titular<< "
    // "<<strcmp(temp.titular,"")<<endl;
    if (archivo and temp.numeroCuenta != 0 and strcmp(temp.titular, "") > 0) {
      cout << "Ya existe una cuenta con este numero\n";
      i--;
    } else {
      // Si fallo la lectura, debemos reestablecer los valores de archivo
      archivo.clear();

      // mover el puntero de escritura
      archivo.seekp(posicion);

      cout << "Titular: ";
      cin >> cuenta.titular;
      cout << "Saldo: ";
      cin >> cuenta.saldo;
      cuenta.activa = true;

      archivo.write((char *)&cuenta, sizeof(CuentaBancaria));
    }
    // No se pueden repetir numero de cuentas
  }

  archivo.close();
}

void operacionBancaria(int codigo, double monto) {
  fstream archivo;
  archivo.open("cuentas.dat", ios::binary | ios::out | ios::in);

  if (!archivo) {
    cerr << "No existe el archivo\n";
    return;
  }
  bool cuentaEncontrada = buscarCuenta(codigo);
  if (cuentaEncontrada) {
    CuentaBancaria temp;
    archivo.seekg((codigo - 1) * sizeof(CuentaBancaria), ios::beg);
    archivo.read((char *)&temp, sizeof(CuentaBancaria));

    if (temp.activa) {
      double saldoFinal = temp.saldo + monto;
      if (saldoFinal < 0) {
        cerr
            << "No se puede realizar la operacion, no tiene saldo suficiente\n";
        archivo.close();
        return;
      } else {
        temp.saldo = saldoFinal;
        archivo.seekp((codigo - 1) * sizeof(CuentaBancaria), ios::beg);
        archivo.write((char *)&temp, sizeof(CuentaBancaria));
        archivo.close();
        cout << "Se realizo la operacion exitosamente.\n";
        return;
      }
    } else {
      cerr << "No puede realizar operaciones en una cuenta inactiva\n";
      archivo.close();
      return;
    }
  }
  archivo.close();
}

int main() {

  int N;
  cout << "Ingrese la cantidad de cuentas que quiere registrar:";
  cin >> N;
  crearArchivo(N);
  // leerArchivo();
  // buscarCuenta(N);
  // activarCuenta(N);
  // desactivarCuenta(N);
  // buscarCuenta(N);
  return 0;
}

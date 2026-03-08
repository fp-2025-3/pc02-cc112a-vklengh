#include <fstream>
#include <iostream>

using namespace std;

struct Empleado {
  int id;
  char nombre[30];
  double salario;
};

void abrirArchivo(const string &direccion, int idEmpleado) {
  fstream archivo;
  archivo.open(direccion, ios::in | ios::out | ios::binary);

  if (!archivo) {
    cerr << "No se pudo abrir archivo: " << direccion << endl;
    return;
  }
  Empleado e;
  archivo.seekg(-sizeof(Empleado), ios::end);
  archivo.read((char *)&e, sizeof(Empleado));
  int cantEmpleados = e.id;
  if (idEmpleado > cantEmpleados) {
    cerr << "No existe el empleado\n"; // empleado fuera de rango
    archivo.close();
    return;
  }

  archivo.seekg(sizeof(Empleado) * (idEmpleado - 1), ios::beg);
  archivo.read((char *)&e, sizeof(Empleado));
  cout << "--- DATOS DEL EMPLEADO ---\n";
  cout << "ID: " << e.id << endl;
  cout << "Nombre: " << e.nombre << endl;
  cout << "Salario: " << e.salario << endl;
  cout << endl;

  // modificar salario
  cout << "Ingrese nuevo salario: ";
  cin >> e.salario;
  if (e.salario <= 0) {
    cerr << "Salario no valido, no se pudo actualizar.\n";
  } else {
    archivo.seekp(sizeof(Empleado) * (idEmpleado - 1), ios::beg);
    archivo.write((char *)&e, sizeof(Empleado));
    cout << endl;
    cout << "Salario actualizado correctamente.\n";
  }
  archivo.close();
}

void menu(const string &direccion) {
  int idEmpleado;
  cout << "Ingrese ID de empleado: ";
  cin >> idEmpleado;
  cout << endl;
  if (idEmpleado < 1) {
    cout << "Ingrese un ID valido (1 o mas).\n";
  }
  abrirArchivo(direccion, idEmpleado);
}

int main() {
  const string direccionEntrada = "entradas/empleados.dat";
  menu(direccionEntrada);
  return 0;
}

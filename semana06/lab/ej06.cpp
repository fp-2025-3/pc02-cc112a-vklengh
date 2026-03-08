#include <fstream>
#include <iostream>

using namespace std;

struct Empleado {
  int id;
  char nombre[20];
  float salario;
};

void escribirEmpleados();
void leerEmpleados();
void buscarEmpleados();

int main() {
  escribirEmpleados();
  leerEmpleados();
  buscarEmpleados();
  return 0;
}

void escribirEmpleados() {
  Empleado e[8];
  const string path = "outputs/empleados.bin";
  ofstream archivo(path, ios::binary);

  if (!archivo) {
    cout << "Error al abrir el archivo" << endl;
    return;
  }
  e[0] = {1, "Empleado A", 3000};
  e[1] = {2, "Empleado B", 4000};
  e[2] = {3, "Empleado C", 3500};
  e[3] = {4, "Empleado D", 4500};
  e[4] = {5, "Empleado E", 3200};
  e[5] = {6, "Empleado F", 3800};
  e[6] = {7, "Empleado G", 4200};
  e[7] = {8, "Empleado H", 3900};

  for (int i = 0; i < 8; i++) {
    archivo.write((char *)&e[i], sizeof(Empleado));
  }
  archivo.close();
  cout << "Empleados registrados adecuadamente\n";
}

void leerEmpleados() {
  Empleado e;
  const string path = "outputs/empleados.bin";
  ifstream archivo(path, ios::binary);

  if (!archivo) {
    cout << "Error al abrir el archivo" << endl;
    return;
  }

  cout << "Informacion de los empleados\n";
  while (archivo.read((char *)&e, sizeof(Empleado))) {
    cout << "ID: " << e.id << ", Nombre: " << e.nombre << ", Salario: $"
         << e.salario << endl;
  }

  archivo.close();
}

void buscarEmpleados() {
  int min, max;
  Empleado e;
  const string path = "outputs/empleados.bin";
  ifstream archivo(path, ios::binary);
  cout << "Ingrese el salario minimo: $";
  cin >> min;
  cout << "Ingrese el salario maximo: $";
  cin >> max;
  cout << "Informacion de los empleados en el rango de salarios: $" << min
       << " - $" << max << endl;
  while (archivo.read((char *)&e, sizeof(Empleado))) {
    if (e.salario <= max and e.salario >= min) {
      cout << "ID: " << e.id << ", Nombre: " << e.nombre << ", Salario: $"
           << e.salario << endl;
    }
  }
  archivo.close();
}

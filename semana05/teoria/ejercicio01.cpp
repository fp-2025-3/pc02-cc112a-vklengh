#include <iostream>

using namespace std;

struct Estudiante {
  int codigo;
  float promedio;
};

Estudiante *crearEstudiantes(int &n) {
  cout << "Ingrese la cantidad de estudiantes: " << endl;
  cin >> n;
  Estudiante *e = new Estudiante[n];
  return e;
}

void leerDatos(Estudiante *e, int n) {
  for (int i = 0; i < n; i++) {
    cout << "Para el estudiante: " << i + 1 << endl;
    cout << "Codigo: ";
    cin >> e[i].codigo;
    cout << "Promedio: ";
    cin >> e[i].promedio;
  }
}

void mostrarEstudiantes(Estudiante *e, int n) {
  cout << "Mostrar estudiantes aprobados: " << endl;
  bool hayAprobados = false;
  for (int i = 0; i < n; i++) {
    if (e[i].promedio >= 10) {
      cout << "Estudiante con codigo: ";
      cout << e[i].codigo;
      cout << " , Promedio: ";
      cout << e[i].promedio << endl;
      if (!hayAprobados) {
        hayAprobados = true;
      }
    }
  }
  if (!hayAprobados) {
    cout << "No hay estudiantes aprobados." << endl;
  }
}

void liberarMemoria(Estudiante *&e) {
  delete[] e;
  e = nullptr;
}

int main() {
  int n;
  Estudiante *e = crearEstudiantes(n);
  leerDatos(e, n);
  mostrarEstudiantes(e, n);
  liberarMemoria(e);
  return 0;
}

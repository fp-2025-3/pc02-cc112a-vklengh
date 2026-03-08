#include <iostream>

using namespace std;

struct Estudiante {
  string nombre;
  int nota;
};

Estudiante *crearEstudiante(int &n) {
  cout << "Ingrese el numero de estudiantes: ";
  cin >> n;
  cin.ignore();
  Estudiante *e = new Estudiante[n];
  return e;
}

void leerDatos(Estudiante *e, int n) {
  for (int i = 0; i < n; i++) {
    cout << "Ingrese el nombre del estudiante " << i + 1 << ": ";
    getline(cin, e[i].nombre);
    cout << "Ingrese la nota del estudiante " << i + 1 << ": ";
    cin >> e[i].nota;
    cin.ignore();
  }
}

void mejorEstudiante(Estudiante *e, int n) {
  Estudiante mejorEst = *e;
  for (int i = 0; i < n; i++) {
    if (mejorEst.nota < (*(e + i)).nota) {
      mejorEst = *(e + i);
    }
  }
  cout << "El estudiante con la mayor nota es: " << mejorEst.nombre << endl;
  cout << "Nota: " << mejorEst.nota << endl;
}

void liberarMemoria(Estudiante *&e) {
  delete[] e;
  e = nullptr;
}

int main() {
  int n;
  Estudiante *e = crearEstudiante(n);
  leerDatos(e, n);
  mejorEstudiante(e, n);
  liberarMemoria(e);
  return 0;
}

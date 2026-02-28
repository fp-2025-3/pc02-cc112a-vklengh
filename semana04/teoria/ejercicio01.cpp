#include <iostream>

using namespace std;

void leerEstudiantes(int &n);
float *reservarMemoria(int n);
void leerNotas(int n, float *notas);
void calculoNotas(int n, float *notas);
void redimensionarEstudiantes(int &k, int &n, float *&notas);
void liberarMemoria(float *&notas);

int main() {
  int n, k;
  float *notaEstudiantes = nullptr;
  leerEstudiantes(n);
  notaEstudiantes = reservarMemoria(n);
  leerNotas(n, notaEstudiantes);
  calculoNotas(n, notaEstudiantes);
  redimensionarEstudiantes(k, n, notaEstudiantes);
  leerNotas(k, notaEstudiantes + n - k);
  cout << "Cantidad de estudiantes: " << n << endl;
  calculoNotas(n, notaEstudiantes);
  liberarMemoria(notaEstudiantes);
  return 0;
}
void leerEstudiantes(int &n) {
  cout << "Ingrese el numero de estudiantes: " << endl;
  cin >> n;
}

float *reservarMemoria(int n) { return new float[n]; }

void leerNotas(int n, float *notas) {
  for (int i = 0; i < n; i++) {
    cout << "Ingrese la nota del estudiante " << i << endl;
    cin >> *(notas + i);
  }
}

void calculoNotas(int n, float *notas) {
  float menor = *notas;
  float mayor = *notas;
  float promedio = *notas;
  for (int i = 1; i < n; i++) {
    // if (*(notas + i - 1) < *(notas + i)) {
    if (menor > *(notas + i)) {
      menor = *(notas + i);
    }
    if (mayor < *(notas + i)) {
      mayor = *(notas + i);
    }
    promedio += *(notas + i);
  }
  promedio /= n;
  cout << "Promedio del curso: " << promedio << endl;
  cout << "Nota maxima del curso: " << mayor << endl;
  cout << "Nota minima del curso: " << menor << endl;
}

void redimensionarEstudiantes(int &k, int &n, float *&notas) {
  cout << "Ingrese la cantidad adicional de estudiantes: " << endl;
  cin >> k;
  float *nuevaNota = new float[n + k];
  for (int i = 0; i < n; i++) {
    *(nuevaNota + i) = *(notas + i);
  }
  delete[] notas;
  notas = nuevaNota;
  n += k;
}

void liberarMemoria(float *&notas) {
  delete[] notas;
  notas = nullptr;
}

#include <iostream>
using namespace std;
// g++ src/*.cpp main.cpp -o build/main

int **crearMatriz(int n, int m);
void llenarMatriz(int **M, int n, int m);
int *sumaFilas(int **M, int n, int m);
void liberarMatriz(int **M, int n);
void mostrarMatriz(int **M, int n, int m);
void mostrarArray(int *a, int n);

int main() {
  int n, m;
  cout << "Ingrese filas (n): ";
  cin >> n;
  cout << "Ingrese las columnas (m): ";
  cin >> m;
  int **M = crearMatriz(n, m);
  llenarMatriz(M, n, m);
  cout << "Matriz:\n";
  mostrarMatriz(M, n, m);
  int *sumaFila = sumaFilas(M, n, m);
  cout << "\nArray suma de filas:\n";
  mostrarArray(sumaFila, n);
  liberarMatriz(M, n);
  delete[] sumaFila;
  sumaFila = nullptr;
  return 0;
}

int **crearMatriz(int n, int m) {
  int **matriz = new int *[n];
  for (int i = 0; i < n; i++) {
    matriz[i] = new int[m];
  }
  return matriz;
}

void llenarMatriz(int **M, int n, int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      M[i][j] = (i + 1) * (j + 1);
    }
  }
}

int *sumaFilas(int **M, int n, int m) {
  int *sumFilas = new int[n];
  for (int i = 0; i < n; i++) {
    sumFilas[i] = 0;
    for (int j = 0; j < m; j++) {
      sumFilas[i] += M[i][j];
    }
  }
  return sumFilas;
}
void liberarMatriz(int **M, int n) {
  for (int i = 0; i < n; i++) {
    delete[] M[i];
    M[i] = nullptr;
  }
  delete[] M;
  M = nullptr;
}

void mostrarMatriz(int **M, int n, int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << M[i][j] << " ";
    }
    cout << endl;
  }
}
void mostrarArray(int *a, int n) {
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}

#include <cctype>  // tolower()
#include <cstring> // para usar strlen()
#include <iostream>
//
const int N = 5;

using namespace std;
bool esMatrizEscalonada(int (*M)[N]);
bool esFilaDominante(int (*M)[N], int fila);
int contarColumnasCriticas(int (*M)[N]);
int main() {
  int M[N][N] = {{0, 0, 0, 0, 8},
                 {0, 0, 1, 2, 8},
                 {1, 2, 3, 4, 8},
                 {5, 6, 7, 8, 8},
                 {9, 7, 1, 1, 8}};
  cout << "Es fila dominante: " << esFilaDominante(M, 4) << endl;
  cout << "Cantidad de columnas critica: " << contarColumnasCriticas(M) << endl;
  return 0;
}

bool esFilaDominante(int (*M)[N], int fila) {
  for (int j = 0; j < N; j++) {
    // obtiene la columna  la fila de entrada
    int elemFila = *(*M + fila * N + j);
    for (int i = 0; i < N; i++) {
      if (i != fila) {
        // elemento de columna
        if (*(*M + i * N + j) >= elemFila) {
          return false;
        }
      }
    }
  }
  return true;
}
bool esMatrizEscalonada(int (*M)[N]) {
  int posAnterior = -1;
  for (int i = 0; i < N; i++) {
    int *fila = *(M + i);
    int posActual = -1;
    // for (int j=0; j<N; j++){
    //     if (*(fila
    // }
    if (posActual != -1) {
      if (posActual <= posAnterior) {
        return false;
      }
    }
  }
  return true;
}
int contarColumnasCriticas(int (*M)[N]) {
  int colCriticas = 0;
  int sumaFilasMax = 0;
  for (int i = 0; i < N; i++) {
    int sumaFila = 0;
    for (int j = 0; j < N; j++) {
      sumaFila += *(*M + i * N + j);
    }
    if (sumaFila > sumaFilasMax) {
      sumaFilasMax = sumaFila;
    }
  }

  for (int j = 0; j < N; j++) {
    // obtiene la suma de la columna
    int sumaCol = 0;
    for (int i = 0; i < N; i++) {
      sumaCol += *(*M + i * N + j);
    }
    if (sumaCol > sumaFilasMax) {
      colCriticas++;
    }
  }
  return colCriticas;
}

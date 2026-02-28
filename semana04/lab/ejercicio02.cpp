#include <cctype>  // tolower()
#include <cstring> // para usar strlen()
#include <iostream>
//
const int N = 5;

using namespace std;
bool esMatrizEscalonada(int (*M)[N]);
bool esFilaDominante(int (*M)[N], int fila);
int contarColumnasCriticas(int (*M)[N]);
int valorNucleo(int (*M)[N]);

int main() {
  int M[N][N] = {{3, 0, 20, 0, 8},
                 {2, 20, 13, 2, 8},
                 {1, 2, 13, 15, 7},
                 {5, 6, 9, 2, 3},
                 {9, 7, 11, 1, 20}};
  // max[2,1,3,2,4]
  // min[2,0,3,0,3]
  cout << "Es fila dominante: " << esFilaDominante(M, 4) << endl;
  cout << "Cantidad de columnas critica: " << contarColumnasCriticas(M) << endl;
  cout << "Es matriz escalonada: " << esMatrizEscalonada(M) << endl;
  cout << "Valor nucleo: " << valorNucleo(M) << endl;
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

  for (int i = 0; i < N; ++i) {
    int *fila = *(M + i);
    int posActual = -1;
    for (int j = 0; j < N; ++j) {
      if (*(fila + j) != 0) {
        posActual = j;
        break;
      }
    }

    if (posActual != -1) {
      if (posActual <= posAnterior) {
        return false;
      }
      posAnterior = posActual;
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

int valorNucleo(int (*M)[N]) { // complejidad O(n^2)
  int array_max_fila[N];       // array con la columna  maxima para cada fila
  int array_min_col[N];        // array con la fila maxima para cada columna

  for (int k = 0; k < N; k++) {
    int max_fila = *(*M + k * N);
    int min_col = *(*M + k);
    *(array_max_fila + k) = 0;
    *(array_min_col + k) = 0;
    // int max_j = 0; // numero de columna del elemento maximo de la fila
    // int min_i = 0; // numero de fila del elemento minimo de la columna

    // maximo fila M[k][i] k fijo
    for (int i = 0; i < N; i++) {
      int elemFila = *(*M + k * N + i);
      if (elemFila > max_fila) {
        max_fila = elemFila;
        *(array_max_fila + k) = i;
      }
    }
    // minimo columna M[j][k] k fijo
    for (int j = 0; j < N; j++) {
      int elemCol = *(*M + j * N + k);
      if (elemCol < min_col) {
        min_col = elemCol;
        *(array_min_col + k) = j;
      }
    }
  }

  for (int i = 0; i < N; i++) {

    int col = *(array_max_fila + i); // columna del maximo de la fila i

    if (*(array_min_col + col) == i) { // Comprobar si tiene mínimo en la fila i

      return *(*M + i * N + col); // M[i][col]
    }
  }
  return -1;
}

#include <iomanip>
#include <iostream>
using namespace std;

const int MAX_COLS = 5;
const int MAX_FILAS = 4;

void imprimirMatriz(int (*inicio)[MAX_COLS], int (*fin)[MAX_COLS]) {
  for (int (*fila)[MAX_COLS] = inicio; fila < fin; fila++) {
    for (int *col = *fila; col < *fila + MAX_COLS; col++) {
      cout << setw(2) << *col << setw(2) << " ";
    }
    cout << endl;
  }
}

int subMatrizSuma(int (*inicio)[MAX_COLS], int i1, int j1, int i2, int j2) {
  // segun las instrucciones del examen se deben especificar las posiciones
  // (i1,j1) y (i2,j2) en la funcion, ademas del puntero al inicio de la matriz
  // por lo que se usara las posiciones i,j en la aritmetica de punteros
  // para determinar las posiciones de la submatriz

  int suma = 0;
  for (int (*fila)[MAX_COLS] = inicio + i1; fila <= inicio + i2; fila++) {
    for (int *col = *fila + j1; col <= *fila + j2; col++) {
      suma += *col;
    }
  }
  return suma;
}

void subMatrizSumaMaxima(int (*inicio)[MAX_COLS], int columnas, int filas) {
  int sumaMax = 0;
  // loop paraa recorrer todos los elementos de la matriz, con una coordenada
  // inicial fija
  int i1max = 0;
  int j1max = 0;
  int i2max = 0;
  int j2max = 0;
  for (int m = 0; m < filas; m++) {
    for (int i = m; i < filas; i++) {
      for (int n = 0; n < columnas; n++) {
        for (int j = n; j < columnas; j++) {
          int suma = subMatrizSuma(inicio, m, n, i, j);
          if (sumaMax < suma) {
            sumaMax = suma;
            i1max = m;
            j1max = n;
            i2max = i;
            j2max = j;
          }
        }
      }
    }
  }
  cout << "Submatriz de suma maxima: " << endl;
  cout << "Esquina superior izquierda: (" << i1max << "," << j1max << ")"
       << endl;
  cout << "Esquina inferior derecha: (" << i2max << "," << j2max << ")" << endl;
  cout << "Suma maxima: " << sumaMax << endl;
}

int main() {
  int M[MAX_FILAS][MAX_COLS] = {{-2, 1, -3, 4, -1},
                                {2, 3, -2, 1, -5},
                                {-1, 4, 2, -3, 2},
                                {1, -2, 3, 4, -1}};
  int (*inicio)[MAX_COLS] = M;
  int filas = sizeof(M) / sizeof(M[0]);
  int (*fin)[MAX_COLS] = M + filas;
  cout << "Matriz: " << endl;
  imprimirMatriz(inicio, fin);
  subMatrizSumaMaxima(inicio, MAX_COLS, filas);
  return 0;
}

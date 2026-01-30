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

int abs(int a) {
  if (a < 0) {
    a = -a;
  }
  return a;
}

void picos(int (*inicio)[MAX_COLS], int (*fin)[MAX_COLS]) {
  int filas = fin - inicio;
  int fi = 0, co = 0;
  bool primer_pico = false;
  for (int (*fila)[MAX_COLS] = inicio; fila < fin; fila++) {
    for (int *col = *fila; col < *fila + MAX_COLS; col++) {
      int valor = *col;
      bool esPico = true;
      bool esMayorAbs = false;
      int f = fila - inicio;
      int c = col - *fila;
      // Buscar en los bordes del elemento es igual a tomar combinaciones de
      // indices de orden relativo
      //
      //          [-1,0]
      //
      //  [0,-1]   [X]    [0,+1]
      //
      //          [+1,0]
      //
      for (int df = -1; df <= 1 and esPico; df++) {
        for (int dc = -1; dc <= 1; dc++) {
          if (!(abs(df) == abs(dc))) {
            int nf = f + df;
            int nc = c + dc;
            if (nf < 0 or nf >= filas or nc < 0 or nc >= MAX_COLS) {
              // omitir punteros fuera de los limites de la matriz
              // cuando los elementos estan en los bordes de la matriz
              continue;
            }

            int vecino =
                *(*(inicio + nf) + nc); // Si valor es menor o igual rompe
            if (valor < vecino) {       // Si valor es menor o igual rompe
              esPico = false;           // bandera para romper los dos for loops
              break;
            }
            if (valor > vecino) {
              esMayorAbs = true;
            }
          }
        }
      }
      if (!primer_pico and esPico) {
        cout << "Elementos pico:" << endl;
        primer_pico = true;
      }
      if (esPico and esMayorAbs) {
        cout << "Pico en : (" << fi << "," << co << "): " << valor << endl;
      }
      co++;
    }
    fi++;
    co = 0;
  }
  if (!primer_pico) {
    cout << "No hay elementos pico" << endl;
  }
}

int main() {
  int M[MAX_FILAS][MAX_COLS] = {
      {3, 3, 3, 3, 3}, {3, 4, 4, 2, 3}, {3, 4, 5, 4, 3}, {3, 3, 3, 3, 3}};
  int (*inicio)[MAX_COLS] = M;
  int (*fin)[MAX_COLS] = M + MAX_FILAS;
  cout << "Matriz:" << endl;
  imprimirMatriz(inicio, fin);
  picos(inicio, fin);
  return 0;
}

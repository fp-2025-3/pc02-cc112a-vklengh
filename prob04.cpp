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
void submatriz(int (*inicio)[MAX_COLS], int (*fin)[MAX_COLS]) {
  int suma = 0;
  for (int (*fila)[MAX_COLS] = inicio; fila < fin; fila++) {
    for (int *col = *fila; col < *fila + MAX_COLS; col++) {
      suma = suma + *col;
    }
  }
  cout << suma << endl;
}

void subMax(int (*inicio)[MAX_COLS], int (*fin)[MAX_COLS]) {
  int sumaMax = 0;
  for (int (*fila)[MAX_COLS] = inicio; fila < fin; fila++) {
    // for (int *col = *fila; col < *fila + MAX_COLS; col++) {
      submatriz(fila, fin);
      // for (int (*fi)[MAX_COLS] = fila; fi < fin - (MAX_FILAS - maxfil + 1);
      //      fi++) {
      //   for (int *co = *fi; co < *fi - (MAX_COLS - maxcol + 1); co++) {
      //     cout << *fi << " " << *co << endl;
      //   }
      //   maxcol--;
      // }
      // maxfil--;
    // }
  }
}

int main() {
  int M[MAX_FILAS][MAX_COLS] = {{-2, 1, -3, 4, -1},
                                {2, 3, -2, 1, -5},
                                {-1, 4, 2, -3, 2},
                                {1, -2, 3, 4, -1}};
  int (*inicio)[MAX_COLS] = M;
  int (*fin)[MAX_COLS] = M + MAX_FILAS;
  imprimirMatriz(inicio, fin);
  subMax(inicio, fin);
  return 0;
}

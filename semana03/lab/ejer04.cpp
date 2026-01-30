#include <cstdlib>
#include <iostream>
#include <random>

const int NFILAS = 9;
const int NCOLS = 9;

using namespace std;

int generar_aleatorio() { return rand() % 9 + 1; }

void verificar_columnas(int *p, int j) {
  *p = generar_aleatorio();
  bool finalizoLoop = false;
  while (!finalizoLoop and j>1) {
    for (int *i = p + 1; i < p + j; i++) {
        cout << *i << " "<<*p <<endl;
      if (*i == *p) {
        *p = generar_aleatorio();
        cout << *p << " alea"<<endl;
        break;
      }
      if (i == p + j - 1) {
          cout << "finalizoLoop"<<endl;
        finalizoLoop = true;
      }
    }
  }
}

void generarmat(int **A) {
  for (int i = 0; i < NFILAS; i++) {
    for (int j = 0; j < NCOLS; j++) {
      // *(*A + i * NCOLS + j) = generar_aleatorio();
      // *(*A + i * NCOLS + j) = 0;
      // *(*A + i * NCOLS + j) = verificar_columnas(*A + i * NCOLS, j);
      verificar_columnas(*A + i * NCOLS, j);
      cout << *(*A + i * NCOLS + j) << endl;
      // verificar_columnas(*A + i * NCOLS, j);
      // cout << "======" << endl;
    }
  }
}

void imprimir(int **A) {
  for (int i = 0; i < NFILAS; i++) {
    for (int j = 0; j < NCOLS; j++) {
      cout << *(*A + i * NCOLS + j) << " ";
    }
    cout << endl;
  }
}
int main() {
  srand(time(0));
  int M[NFILAS][NCOLS];
  int *p = &M[0][0];
  int **A = &p;
  generarmat(A);
  imprimir(A);
  // verificar_columnas(p);
  return 0;
}

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int **reservarMemoriaMatriz(int filas, int columnas);
void liberarMemoriaMatriz(int filas, int **&M);
void aleatorioMatriz(int filas, int columnas, int **M);

int main() {
  srand(time(0));
  int n, m;
  int **M;
  n = 5, m = 3;
  M = reservarMemoriaMatriz(n, m);
  aleatorioMatriz(n, m, M);
  liberarMemoriaMatriz(n, M);
  return 0;
}

int **reservarMemoriaMatriz(int filas, int columnas) {
  int **M = new int *[filas];
  for (int i = 0; i < filas; i++) {
    M[i] = new int[columnas];
  }
  return M;
}

void aleatorioMatriz(int filas, int columnas, int **M) {
  for (int i = 0; i < filas; i++) {
    for (int j = 0; j < columnas; j++) {
      M[i][j] = rand() % 9 + 1;
      cout << M[i][j] << " ";
    }
    cout << endl;
  }
}

void liberarMemoriaMatriz(int filas, int **&M) {
  for (int i = 0; i < filas; i++) {
    delete[] M[i];
    M[i] = nullptr;
  }
  delete[] M;
  M = nullptr;
}

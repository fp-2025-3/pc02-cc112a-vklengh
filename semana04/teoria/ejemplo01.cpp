#include <iostream>

using namespace std;

void memal(int n) {
  int *p = new int[n];
  cout << p << endl;
  delete[] p;

  int *y = new int(0);
  cout << *y << " " << y << endl;
  delete y;
  y = nullptr;
  y = new int(10);
  // delete libera memoria
  // dangling pointer (puntero colgante)
  cout << *y << " " << y << endl;
  delete y;
  y = nullptr;
}

void matriz(int filas, int columnas) {
  int **M = new int *[filas];
  for (int i = 0; i < filas; i++) {
    M[i] = new int[columnas];
  }

  // FORMA CORRECTA DE LIBERAR MATRICES
  for (int i = 0; i < filas; i++) {
    delete[] M[i];
  }
  delete[] M;
}
int main() {
  memal(5);
  int *ptr = new int[100];
  delete[] ptr;

  return 0;
}

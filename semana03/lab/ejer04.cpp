#include <iostream>

const int NFILAS = 9;
const int NCOLS = 9;

using namespace std;
void imprimir(int **A) {
  for (int i = 0; i < NFILAS; i++) {
    for (int j = 0; j < NCOLS; j++) {
      cout << *(*A + i * NCOLS + j) << " ";
    }
    cout << endl;
  }
}
int main() {
  int M[NFILAS][NCOLS];
  int *p = &M[0][0];
  int **A = &p;
  imprimir(A);
  return 0;
}

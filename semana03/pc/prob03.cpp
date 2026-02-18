#include <cstdlib>
#include <iostream>
#include <random>

// ALGORITMO FISHER-YATES
const int NFILAS = 9;
const int NCOLS = 9;

using namespace std;

int busca_elemento(int *p, int n, int key) {
  for (int i = 0; i < n; i++) {
    if (*(p + i) == key) {
      return i;
    }
  }
  return -1; // nunca deberia llegar a esta condicion porque los elementos
             // siempre estan en el array
}

void reordenar_array(int *p, int n, int key, int columna) {
  int pos = busca_elemento(p, n, key);
  int dif = columna - pos;
  int temp[NCOLS];
  // GUARDA LOS VALORES DEL ARRAY ORDENADO
  for (int i = 0; i < n; i++) {
    int new_pos = 0;
    if (i - dif > n - 1) {
      new_pos = (i - dif) - n;
    } else if (i - dif >= 0) {
      new_pos = i - dif;
    } else {
      new_pos = n + i - dif;
    }
    *(temp + i) = *(p + new_pos);
  }
  // DEVUEVE LOS VALORES ORDENADOS AL PUNTERO
  for (int i = 0; i < n; i++) {
    *(p + i) = *(temp + i);
  }
}

void genera_array_aleatorio(int *p, int n) {
  // primero crea un array con 1 a 9
  for (int i = 0; i < n; i++) {
    *(p + i) = i + 1;
  }
  // luego los reordena de forma aleatoria
  for (int i = n - 1; i > 0; i--) {
    int temp = *(p + i);
    int col = rand() % i;
    *(p + i) = *(p + col);
    *(p + col) = temp;
  }
}

void generarmat(int **A) {
  for (int i = 0; i < NFILAS; i++) {
    genera_array_aleatorio((*A + i * NCOLS), NFILAS);
  }
}

void reordenar_matriz(int **A, int n, int key, int columna, int fila) {
  for (int i = 0; i < NFILAS; i++) {
    if (i != fila) {
      reordenar_array((*A + i * NCOLS), n, key, columna);
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
  int fila, columna;
  cout << "Matriz inicial:" << endl;
  generarmat(A);
  imprimir(A);
  cout << "Fila inicial (1-9): ";
  cin >> fila;

  fila--;
  cout << "Columna inicial (1-9): ";
  cin >> columna;
  cout << endl;
  columna--;
  int num = *(*A + fila * NCOLS + columna);
  cout<<"Valor seleccionado: "<<num<<endl;
  reordenar_matriz(A, NCOLS, num, columna, fila);
  imprimir(A);
  return 0;
}

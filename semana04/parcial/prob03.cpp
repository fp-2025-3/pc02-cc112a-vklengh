#include <iomanip>
#include <iostream>
//
const int N = 4;

using namespace std;
bool esFilaDominanteEstricta(int (*M)[N], int f);
bool esFilaFuertementeDominante(int (*M)[N], int f);
void imprimir(int (*M)[N]);

int main() {
  int M[N][N] = {{2, 3, 1, 4}, {1, 2, 3, 2}, {5, 6, 7, 8}, {0, 1, 2, 1}};
  // cout << "Es fila dominante: " << esFilaDominanteEstricta(M, 2) << endl;
  imprimir(M);
  return 0;
}

bool esFilaDominanteEstricta(int (*M)[N], int f) {
  bool esMayor;
  bool estrictamenteMayor = false;
  int contadorMayor = 0;
  for (int j = 0; j < N; j++) {
    // obtiene la columna  la fila de entrada
    int elemFila = *(*M + f * N + j);
    int contadorEstrictoMayor = 0;
    esMayor = false;
    for (int i = 0; i < N; i++) {
      if (i != f) {
        // elemento de columna
        if (*(*M + i * N + j) <= elemFila) {
          contadorMayor++;
        }
        if (*(*M + i * N + j) < elemFila) {
          contadorEstrictoMayor++;
        }
      }
    }
    // cout << contadorEstrictoMayor << endl;
    if (contadorEstrictoMayor >= N - 1) {
      estrictamenteMayor = true;
    }
  }
  if (contadorMayor >= N * (N - 1)) {
    esMayor = true;
  }
  // cout << contadorMayor << " " << estrictamenteMayor << endl;
  if (esMayor and estrictamenteMayor) {
    return true;
  } else {
    return false;
  }
}

int sumarFila(int (*M)[N], int f) {
  int suma = 0;
  for (int i = 0; i < N; i++) {
    suma += *(*M + f * N + i);
  }
  return suma;
}

bool esFilaFuertementeDominante(int (*M)[N], int f, bool esDominante) {
  if (esDominante) {
    // algo;
    int sumaFilaMayor = 0; // Que no sea la fila deseada
    int sumaFilaDeseada;

    for (int j = 0; j < N; j++) {
      if (j == f) {
        sumaFilaDeseada = sumarFila(M, j);
      } else {
        int suma = sumarFila(M, j);
        if (suma > sumaFilaMayor) {
          sumaFilaMayor = suma;
        }
      }
    }
    if (sumaFilaMayor < sumaFilaDeseada) {
      return true;
    } else {
      return false;
    }
  }
  return false;
}

void imprimir(int (*M)[N]) {

  cout << setw(15) << left << "Fila" << setw(15) << right
       << "Dominante Estricta" << setw(30) << right << "Fuertemente Dominante"
       << endl;
  cout << "---------------------------------------------------------" << endl;
  for (int i = 0; i < N; i++) {
    bool esDominante = esFilaDominanteEstricta(M, i);
    bool esFilaFuerte = esFilaFuertementeDominante(M, i, esDominante);
    if (esDominante) {
      cout << setw(15) << left << i << setw(28) << "SI" << right ;
    } else {
      cout << setw(15) << left << i << setw(28) << "NO" << right ;
    }
    if (esFilaFuerte) {
      cout << "SI" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}

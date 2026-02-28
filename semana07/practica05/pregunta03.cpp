#include <cmath>
#include <fstream>
#include <iostream>

const int N = 81; // uno extra para el caracter nulo
const int FILAS = 21;
using namespace std;

struct Punto {
  int x;
  int y;
};

void graficarSeno(ofstream &archivo) {
  // Graficar de 0 a 2pi es igual para una cantidad de 80
  // es igual a muestrar un dato cada 2*pi/80 o 9°
  double pi = acos(-1);
  int contador = 0;
  char cad[FILAS][N];
  Punto puntos[N];

  for (int i = 0; i < N; i++) {
    // double y = 10*sin(i * 2 * pi / 80 * 5);
    double y = 10 * (1 - sin(i * 2 * pi / 80 * 5));
    if (int(y) == 10) {
      y = 9;
    }
    puntos[i].x = i;
    puntos[i].y = int(y);
    // cout << "x: " << puntos[i].x << " y: " << puntos[i].y << endl;
  }

  for (int i = 0; i < FILAS; i++) {
    for (int j = 0; j < N; j++) {
      cad[i][j] = ' ';
      bool dibujadoPunto = false;
      for (int k = 0; k < N; k++) {
        if (contador < N and i == puntos[k].y and j == puntos[k].x) {
          if (j == N - 1) {
            cad[i][j] = '\n';
            break;
          }
          cad[i][j] = '*';
          dibujadoPunto = true;
          contador++;
          break;
        }
      }
      if (!dibujadoPunto) {
        if (j == 0) {
          cad[i][j] = '|';
        } else if (j == N - 1) {
          cad[i][j] = '\n';
        } else if (i == FILAS / 2) {
          cad[i][j] = '-';
        } else {
          cad[i][j] = ' ';
        }
      }
      cout << cad[i][j];
      archivo << cad[i][j];
    }
  }
}

void escribirArchivo(const string &direccionSalida) {
  ofstream archivoSalida;
  archivoSalida.open(direccionSalida);

  if (!archivoSalida) {
    cerr << "No se pudo abrir archivo: " << direccionSalida << endl;
    return;
  }
  graficarSeno(archivoSalida);
  archivoSalida.close();
}

int main() {
  const string direccionSalida = "salidas/grafico.txt";
  escribirArchivo(direccionSalida);
  return 0;
}

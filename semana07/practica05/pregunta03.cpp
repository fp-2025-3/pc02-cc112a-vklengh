#include <cmath>
#include <fstream>
#include <iostream>

using namespace std;

void graficarSeno(ofstream &archivo) {
  // Graficar de 0 a 2pi es igual para una cantidad de 80
  // es igual a muestrar un dato cada 2*pi/80 o 9°
  int N = 80;
  int COLS = 21;
  double pi = acos(-1);
  int contador = 0;
  int arrX[N];
  int arrY[N];
  char cad[N][COLS];
  for (int i = 0; i < COLS; i++) {
    for (int j = 0; j < N; j++) {
      double y = 10 * sin(j * 2 * pi / 80 * 5);
      if (i == abs(int(y))) {
        arrX[contador] = int(y) + 10;
        arrY[contador] = j;
        contador++;
      }
    }
  }
  // for (int i = 0; i < contador; i++) {
  //   cout << arrX[i] << " " << arrY[i] << endl;
  // }

  for (int i = 0; i < COLS; i++) {
    for (int j = 0; j < N; j++) {
        cad[i][j]='.';
    }
  }
  for (int i = 0; i < COLS; i++) {
    for (int j = 0; j < N; j++) {
      // ejes
      if (i == 10) {
        if (j == 0) {
          cout << " ";
          archivo << " ";
          cad[i][j] = ' ';
        } else {
          cout << "-";
          archivo << "-";
          cad[i][j] = '-';
          if (j == N - 1) {
            cad[i][j] = '\n';
            cout << endl;
            archivo << endl;
          }
        }
      } else {
        if (j == 0 and i != 10) {
          cad[i][j] = '|';
          cout << "|" << endl;
          archivo << "|" << endl;
        }
      }
    }
  }
  for (int i = 0; i < COLS; i++) {
    for (int j = 0; j < N; j++) {
        cout << cad[i][j];
    }
  }
  // bool puntoImpreso = false;
  // // puntos
  // if (i == arrY[i] and j == arrX[j]) {
  //   cout << i << " " << j << endl;
  //   // cout << "*";
  //   c++;
  //   puntoImpreso = true;
  // }
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

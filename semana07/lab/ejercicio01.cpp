#include <fstream>
#include <iostream>

using namespace std;

void insertionsort(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 and arr[j] > key) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
}

void leerArchivo(ifstream &archivo, int arr[], int &i) {
  int lectura;
  while (archivo >> lectura) {
    // cout << lectura1 << endl;
    if (lectura == -1) {
      break;
    }
    arr[i] = lectura;
    i++;
  };
  archivo.close();
}

void abrirArchivo() {
  const string direccion1 = "./entradas/archivo1.txt";
  const string direccion2 = "./entradas/archivo2.txt";
  const string direccionSalida = "./salidas/nombreM.txt";

  ifstream archivo1, archivo2;
  ofstream archivoSalida;

  archivo1.open(direccion1);

  if (!archivo1) {
    cerr << "Error al abrir el archivo 1 para la lectura" << endl;
    return;
  }
  archivo2.open(direccion2);
  if (!archivo2) {
    cerr << "Error al abrir el archivo 2 para la lectura" << endl;
    return;
  }
  int i = 0;
  int arr[50];
  leerArchivo(archivo1, arr, i);
  leerArchivo(archivo2, arr, i);

  archivoSalida.open(direccionSalida);

  if (!archivoSalida) {
    cerr << "Error al abrir el archivo de salida para escritura" << endl;
    return;
  }
  insertionsort(arr, i);

  for (int j = 0; j < i; j++) {
    archivoSalida << arr[j] << '\n';
  }
  archivoSalida.close();
  cout << "Escrito el archivo en: " << direccionSalida << endl;
}

int main() {
  abrirArchivo();
  return 0;
}

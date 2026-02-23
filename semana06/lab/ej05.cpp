#include <fstream>
#include <iostream>

const int N = 20;
using namespace std;

double areaTriangulo(double x1, double y1, double x2, double y2, double x3,
                     double y3) {
  return abs((x1 * (y3 - y2) + x2 * (y1 - y3) + x3 * (y2 - y1)) / 2);
}

void leerArchivo() {

  const string archivoLagunaDir = "inputs/laguna.txt";
  const string archivoAreaDir = "outputs/area.txt";

  ifstream archivo(archivoLagunaDir);

  if (!archivo) {
    cout << "Error al abrir el archivo" << endl;
    return;
  }
  int nt, nv;
  archivo >> nt;
  archivo >> nv;
  // crear lista dinamica de coordenadas
  double **coords = new double *[nv];
  for (int i = 0; i < nv; i++) {
    coords[i] = new double[2];
  }
  for (int i = 1; i <= nv; i++) {
    double x, y;
    archivo >> x >> y;
    coords[i - 1][0] = x;
    coords[i - 1][1] = y;
  }
  int v1, v2, v3;
  double area = 0.;
  while (archivo >> v1 >> v2 >> v3) {
    v1--;
    v2--;
    v3--;
    double x1 = coords[v1][0];
    double y1 = coords[v1][1];
    double x2 = coords[v2][0];
    double y2 = coords[v2][1];
    double x3 = coords[v3][0];
    double y3 = coords[v3][1];
    area += areaTriangulo(x1, y1, x2, y2, x3, y3);
  }
  archivo.close();
  // cout << "Area total: "<<area <<endl;
  for (int i = 0; i < nv; i++) {
    delete[] coords[i];
    coords[i] = nullptr;
  }
  delete[] coords;
  coords = nullptr;

  ofstream archivoArea(archivoAreaDir);
  archivoArea << area << "\n";
  archivoArea.close();
}

struct Fibonacci {
  int terminos[N];
};

Fibonacci generarFibonacci() {
  Fibonacci arr;
  arr.terminos[0] = 0;
  arr.terminos[1] = 1;
  for (int i = 2; i < N; i++) {
    arr.terminos[i] = arr.terminos[i - 1] + arr.terminos[i - 2];
  }
  return arr;
}

void escribirFibonacciBinario() {
  Fibonacci fib = generarFibonacci();
  const string path = "outputs/fibonacci.bin";
  ofstream archivo(path, ios::binary);

  if (!archivo) {
    cout << "Error al abrir el archivo" << endl;
    return;
  }

  archivo.write((char *)&fib, sizeof(Fibonacci));
  archivo.close();
  cout << "Funcion escribirFibonacciBinario:\n";
  cout << "Terminos de Fibonacci en el archivo correctamente\n";

  return;
}

void leerFibonacciBinario() {
  const string path = "outputs/fibonacci.bin";
  ifstream archivo(path, ios::binary);
  if (!archivo) {
    cout << "Error al abrir el archivo" << endl;
    return;
  }
  Fibonacci fib;
  cout << "\nFuncion leerFibonacciBinario:\n";
  while (archivo.read((char *)&fib, sizeof(Fibonacci))) {
    for (int i = 0; i < N; i++) {
      cout << "Termino " << i + 1 << ": " << fib.terminos[i] << endl;
    }
  }

  archivo.close();
}

int main() {
  escribirFibonacciBinario();
  leerFibonacciBinario();
  return 0;
}

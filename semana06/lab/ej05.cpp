#include <fstream>
#include <iostream>

using namespace std;

void escribirFibonacciBinario();
void leerFibonacciBinario();

int main() {
  escribirFibonacciBinario();
  leerFibonacciBinario();
  return 0;
}

const int N = 20;
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

#include <iostream>
#include <climits>

using namespace std;

int costoMaximoConSalidas(int arr[], int n, int pos, int cantLlamadas) {
  // Caso base
  if (pos == n) {
    return 0;
  }
  // Caso recursivo
  int max = INT_MIN;
  int producto = 1;
  for (int i = pos; i < n; i++) {
    producto *= arr[i];
    int costoLocal = costoMaximoConSalidas(arr, n, i + 1, cantLlamadas + 1);
    int costoTotal = producto + costoLocal;
    cout << "Llamada en rama: " << cantLlamadas
         << " costo en ejecucion recursiva: " << costoTotal << endl;
    if (costoTotal > max)
      max = costoTotal;
  }
  return max;
}

int costoMaximo(int arr[], int n, int pos) {
  // Caso base
  if (pos == n) {
    return 0;
  }
  // Caso recursivo
  int max = INT_MIN;
  int producto = 1;
  for (int i = pos; i < n; i++) {
    producto *= arr[i];
    int costoLocal = costoMaximo(arr, n, i + 1);
    int costoTotal = producto + costoLocal;
    if (costoTotal > max)
      max = costoTotal;
  }
  return max;
}

int main() {
  int arr[] = {1, 2, 3, 4, 5};
  int n = sizeof(arr) / sizeof(arr[0]);
  int cmin = costoMaximo(arr, n, 0);
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
  cout << "Costo maximo: " << cmin << endl;
  cout << "Salidas de la recursion" << endl;
  costoMaximoConSalidas(arr, n, 0, 0);
  return 0;
}

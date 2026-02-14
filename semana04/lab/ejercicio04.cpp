#include <iostream>

#include <climits>

using namespace std;

void imprimirSegmento(int arr[], int ini, int fin) {
  cout << "[";
  for (int k = ini; k <= fin; k++) {
    cout << arr[k];
    if (k < fin)
      cout << " ";
  }
  cout << "]";
}

int costoMinimo(int arr[], int n, int pos) {
  // Caso base
  if (pos == n) {
    return 0;
  }

  // Caso recursivo
  int min = INT_MAX;
  int producto = 1;
  for (int i = pos; i < n; i++) {
    producto *= arr[i];
    int costoLocal = costoMinimo(arr, n, i + 1);
    int costoTotal = producto + costoLocal;
    // cout << "Costo anterior: " << producto << " elem " << arr[i]
    //      << " Costo: " << costoLocal << endl;
    if (costoTotal < min)
      min = costoTotal;
  }
  return min;
}

int main() {

  int arr[] = {1, 2, 3};
  int n = sizeof(arr) / sizeof(arr[0]);
  int cmin = costoMinimo(arr, n, 0);
  cout << "Costo minimo: " << cmin << endl;
  return 0;
}

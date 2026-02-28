#include <climits>
#include <iostream>

using namespace std;

int costoMaximoConSalida(int arr[], int n, int pos, int arbol[][5], int &iter,
                         int nivel) {
  // Caso base
  if (pos == n) {
    return 0;
  }
  // Caso recursivo
  int max = INT_MIN;
  int producto = 1;
  for (int i = pos; i < n; i++) {
    producto *= arr[i];
    int costoLocal =
        costoMaximoConSalida(arr, n, i + 1, arbol, iter, nivel + 1);
    int costoTotal = producto + costoLocal;
    arbol[iter][0] = pos;
    arbol[iter][1] = i;
    arbol[iter][2] = producto;
    arbol[iter][3] = costoTotal;
    arbol[iter][4] = nivel;
    iter++;
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
  int arbol[100][5];
  int iter = 0;
  int n = sizeof(arr) / sizeof(arr[0]);
  int cmin = costoMaximo(arr, n, 0);
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
  cout << "Costo maximo: " << cmin << endl;
  cout << "Salidas del arbol recursivo" << endl;
  costoMaximoConSalida(arr, n, 0, arbol, iter, 0);
  for (int i = iter - 1; i >= 0; i--) {
    for (int d = 0; d < arbol[i][4]; d++) {
      cout << "  ";
    }
    cout << "pos=" << arbol[i][0] << " || i=" << arbol[i][1]
         << " || producto=" << arbol[i][2] << " || costo=" << arbol[i][3]
         << endl;
  }
  return 0;
}

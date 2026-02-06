#include <iostream>
using namespace std;

int *crearArreglo(int n, char *texto) {
  int *array = new int[n];
  for (int i = 0; i < n; i++) {
    cout << texto << " : ";
    cin >> array[i];
  }
  return array;
}

int *AumentarArreglo(int *arr, int tam, int n, char *texto) {
  if (tam == n) {
    int *temp = new int[2 * n];
    for (int i = 0; i < n; i++) {
      temp[i] = arr[i];
    }
    cout << texto << " : ";
    cin >> arr[n + 1];
    delete[] arr;
    return temp;
  } else {
    cout << texto << " : ";
    cin >> arr[tam + 1];
    return arr;
  }
}

void EliminarMemoria(int *&arr) {
  delete[] arr;
  arr = nullptr;
}

void eliminarEstudiantes(int *codigo, int *promedio, int n) {
  for (int i = 0; i < n; i++) {
      if (promedio[i]<10){}
  }
}

int main() {
  int n;
  cout << "Ingrese la cantidad de estudiantes: ";
  cin >> n;
  char texto1[] = "Codigo";
  char texto2[] = "Promedio";
  int *codigo = crearArreglo(n, texto1);
  int *promedio = crearArreglo(n, texto2);

  int tam = sizeof(codigo) / sizeof(codigo[0]);
  codigo = AumentarArreglo(codigo, tam, n, texto1);
  promedio = AumentarArreglo(promedio, tam, n, texto2);
  EliminarMemoria(codigo);
  EliminarMemoria(promedio);
  return 0;
}

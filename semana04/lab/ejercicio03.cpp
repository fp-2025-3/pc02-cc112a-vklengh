#include <iostream>
const int N = 10;
using namespace std;

void leerDatos(int codigo[], float nota[], int faltas[], int n);
void ordenarPorNota(int codigo[], float nota[], int faltas[], int n);
void mostrarRanking(int codigo[], float nota[], int faltas[], int n);
void buscarEstudiante(int codigo[], float nota[], int faltas[], int n,
                      int codKey);
void ordenarPorCodigo(int codigo[], float nota[], int faltas[], int n);
int busquedaBinaria(int codigo[], int n, int clave);
void printarray(int codigo[], float nota[], int faltas[], int n);

int main() {
  // int codigo[N];
  // float nota[N];
  // int faltas[N];
  int n = 6;
  // leerDatos(codigo, nota, faltas, n);
  int codigo[] = {2, 3, 4, 1, 5, 6};
  float nota[] = {13, 13, 4, 11, 9, 17};
  int faltas[] = {3, 0, 4, 1, 0, 5};
  cout << "Datos sin ordenar: " << endl;
  printarray(codigo, nota, faltas, n);
  ordenarPorNota(codigo, nota, faltas, n);
  cout << "Datos ordenados: " << endl;
  printarray(codigo, nota, faltas, n);
  mostrarRanking(codigo, nota, faltas, n);
  buscarEstudiante(codigo, nota, faltas, n, 5);
  ordenarPorCodigo(codigo, nota, faltas, n);
  printarray(codigo, nota, faltas, n);
  int clave = 6;
  int busqueda = busquedaBinaria(codigo, n, clave);
  if (busqueda >= 0) {
    cout << "Encontrado estudiante con codigo: " << clave << endl;
  } else {
    cout << "No se encontro estudiante." << endl;
  }
  return 0;
}

void leerDatos(int codigo[], float nota[], int faltas[], int n) {
  for (int i = 0; i < n; i++) {
    cout << "Ingrese el código del estudiante " << i << ":";
    cin >> codigo[i];
    cout << "Ingrese la nota del estudiante " << i << ":";
    cin >> nota[i];
    cout << "Ingrese las faltas del estudiante " << i << ":";
    cin >> faltas[i];
  }
}
void ordenarPorNota(int codigo[], float nota[], int faltas[], int n) {

  for (int i = 1; i < n; i++) {
    float keyNota = nota[i];
    int keyFaltas = faltas[i];
    int keyCodigo = codigo[i];
    int j = i - 1;
    while (j >= 0 and (nota[j] < keyNota or
                       (nota[j] == keyNota and faltas[j] > keyFaltas))) {
      nota[j + 1] = nota[j];
      faltas[j + 1] = faltas[j];
      codigo[j + 1] = codigo[j];

      j--;
    }

    nota[j + 1] = keyNota;
    faltas[j + 1] = keyFaltas;
    codigo[j + 1] = keyCodigo;
  }
}

void mostrarRanking(int codigo[], float nota[], int faltas[], int n) {
  float promedio = 0.;
  int cantDesaprobados = 0;
  for (int i = 0; i < n; i++) {
    if (i < 5) {
      cout << "Estudiante puesto " << i + 1 << ", con codigo: " << codigo[i]
           << " nota: " << nota[i] << " faltas: " << faltas[i] << endl;
    }
    if (nota[i] < 10) {
      cantDesaprobados++;
    }
    promedio += nota[i];
  }
  promedio /= n;
  cout << "Promedio del curso: " << promedio << endl;
  cout << "Cantidad de desaprobados: " << cantDesaprobados << endl;
}

void buscarEstudiante(int codigo[], float nota[], int faltas[], int n,
                      int codKey) {
  bool noEncontrado = true;
  for (int i = 0; i < n; i++) {
    if (codKey == codigo[i]) {
      cout << "Estudiante con codigo: " << codKey << " Tiene nota: " << nota[i]
           << " Faltas: " << faltas[i] << " Ranking: " << i + 1 << endl;
      noEncontrado = false;
      break;
    }
  }
  if (noEncontrado) {
    cout << "Codigo de estudiante no encontrado" << endl;
  }
}

void ordenarPorCodigo(int codigo[], float nota[], int faltas[], int n) {
  for (int i = 0; i < n - 1; i++) {
    int min_idx = i;
    for (int j = i + 1; j < n; j++) {
      if (codigo[j] < codigo[min_idx]) {
        min_idx = j;
      }
    }
    swap(codigo[i], codigo[min_idx]);
    swap(nota[i], nota[min_idx]);
    swap(faltas[i], faltas[min_idx]);
  }
}

int busquedaBinaria(int codigo[], int n, int clave) {
  int low = 0, high = n - 1;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (codigo[mid] == clave) {
      return mid;
    } else if (codigo[mid] < clave) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return -1;
}

void printarray(int codigo[], float nota[], int faltas[], int n) {
  cout << "Codigo: ";
  for (int i = 0; i < n; i++) {
    cout << codigo[i] << " ";
  }
  cout << endl;
  cout << "Notas: ";
  for (int i = 0; i < n; i++) {
    cout << nota[i] << " ";
  }
  cout << endl;
  cout << "faltas: ";
  for (int i = 0; i < n; i++) {
    cout << faltas[i] << " ";
  }
  cout << endl;
}

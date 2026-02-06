#include <iostream>
const int N = 30;
using namespace std;

void leerDatos(char *nombre[], int tiempo[], int n);
void ordenarPorTiempo(char *nombre[], int tiempo[], int n);
void mostrarRanking(char *nombre[], int tiempo[], int n);
void buscarCorredor(char *nombre[], int tiempo[], int n, char *clave);
void buscarEnRango(char *nombre[], int tiempo[], int n, int t_min, int t_max);

int main() {
  int n;
  char *nombre[N];
  int tiempo[N];
  char clave[20];
  int t_min, t_max;
  cout << "Ingrese numero de corredores: ";
  cin >> n;
  leerDatos(nombre, tiempo, n);
  cout << "\n" << endl;

  mostrarRanking(nombre, tiempo, n);
  cout << "\n" << endl;
  cout << "Ingrese el nombre a buscar: ";
  cout << clave << endl;
  // cin.getline(clave, 20);
  buscarCorredor(nombre, tiempo, n, clave);
  cout << "\n" << endl;
  cout << "Ingrese el tiempo minimo y maximo: ";
  cin >> t_min;
  cin >> t_max;
  buscarEnRango(nombre, tiempo, n, t_min, t_max);
  return 0;
}

void leerDatos(char *nombre[], int tiempo[], int n) {
  for (int i = 0; i < n; i++) {
    cout << "Nombre del corredor " << i + 1 << ":";
    cin.getline(nombre[i], 20);

    cout << "Tiempo (en segundos): ";
    cin >> tiempo[i];
  }
}
void ordenarPorTiempo(char *nombre[], int tiempo[], int n) {

  for (int i = 1; i < n; i++) {
    char *keyNombre = nombre[i];
    int keyTiempo = tiempo[i];
    int j = i - 1;
    while (j >= 0 and tiempo[j] > keyTiempo) {
      nombre[j + 1] = nombre[j];
      tiempo[j + 1] = tiempo[j];

      j--;
    }

    nombre[j + 1] = keyNombre;
    tiempo[j + 1] = keyTiempo;
  }
}

void mostrarRanking(char *nombre[], int tiempo[], int n) {
  // Primero se ordena los datos
  ordenarPorTiempo(nombre, tiempo, n);
  for (int i = 0; i < n; i++) {
    cout << i + 1 << ". " << nombre[i] << " - " << tiempo[i] << " segundos"
         << endl;
  }
}

void buscarCorredor(char *nombre[], int tiempo[], int n, char *clave) {
  bool corredorNoEncontrado = true;
  for (int i = 0; i < n; i++) {
    if (nombre[i] == clave) {
      cout << "Corredor encontrado" << endl;
      cout << "Posicion: " << i + 1 << endl;
      cout << "Tiempo: " << tiempo[i] << " segundos" << endl;
      corredorNoEncontrado = false;
      break;
    }
  }
  if (corredorNoEncontrado) {
    cout << "No se encontro al corredor." << endl;
  }
}

void buscarEnRango(char *nombre[], int tiempo[], int n, int t_min, int t_max) {
  for (int i = 0; i < n; i++) {
    if (tiempo[i] >= t_min and tiempo[i] <= t_max) {
      cout << nombre[i] << " - " << tiempo[i] << " segundos" << endl;
    }
  }
}

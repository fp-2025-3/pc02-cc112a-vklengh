#include <cstring>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void leerArchivo();

int main() {
  leerArchivo();
  return 0;
}

struct Estudiante {
  string nombre;
  string apellido;
  int nota;
};

void insertionSort(Estudiante e[], int n) {
  for (int i = 0; i < n; i++) {
    Estudiante key = e[i];
    int j = i - 1;
    while ((j >= 0 and e[j].apellido > key.apellido) or
           (j >= 0 and e[j].apellido == key.apellido and
            e[j].nombre > key.nombre) or
           (j >= 0 and e[j].apellido == key.apellido and
            e[j].nombre == key.nombre and e[j].nota > key.nota)) {
      e[j + 1] = e[j];
      j = j - 1;
    }
    e[j + 1] = key;
  }
}

void leerArchivo() {

  const string archivoEntradaDir = "inputs/Entrada.csv";

  ifstream archivo(archivoEntradaDir);

  if (!archivo) {
    cout << "Error al abrir el archivo en:" << archivoEntradaDir << endl;
    return;
  }
  string texto;
  int n = 0;

  while (getline(archivo, texto)) {
    n++;
  }

  archivo.clear();
  archivo.seekg(0, ios::beg);
  Estudiante *e = new Estudiante[n];
  n = 0;

  while (getline(archivo, texto)) {
    int p1 = texto.find(',');
    e[n].apellido = texto.substr(0, p1);
    int p2 = texto.substr(p1 + 1).find(',');
    e[n].nombre = texto.substr(p1 + 1, p2);
    e[n].nota = stoi(texto.substr(p1 + p2 + 2));
    e[n].nota += 2;
    if (e[n].nota > 20) {
      e[n].nota = 20;
    }
    cout << "apellido: " << e[n].apellido << " | nombre: " << e[n].nombre
         << " | nota: " << e[n].nota << endl;
    n++;
  }
  insertionSort(e, n);
  cout << "ordenado\n";
  for (int i = 0; i < n; i++) {
    cout << "apellido: " << e[i].apellido << " | nombre: " << e[i].nombre
         << " | nota: " << e[i].nota << endl;
  }
  archivo.close();

  const string archivoSalidaDir = "outputs/Salida.csv";
  ofstream archivoSalida(archivoSalidaDir);
  if (!archivoSalida) {
    cout << "Error al abrir el archivo en:" << archivoSalidaDir << endl;
    return;
  }

  for (int i = 0; i < n; i++) {
    archivoSalida << e[i].apellido << "," << e[i].nombre << "," << e[i].nota
                  << endl;
  }
  archivoSalida.close();

  delete[] e;
  e = nullptr;
}

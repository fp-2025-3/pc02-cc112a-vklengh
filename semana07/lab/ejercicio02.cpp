#include <cstring>
#include <fstream>
#include <iomanip>
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
  double nota1;
  double nota2;
  int numero;
  double promedio;
};

// void insertionSort(Estudiante e[], int n) {
//   for (int i = 0; i < n; i++) {
//     Estudiante key = e[i];
//     int j = i - 1;
//     while ((j >= 0 and e[j].apellido > key.apellido) or
//            (j >= 0 and e[j].apellido == key.apellido and
//             e[j].nombre > key.nombre) or
//            (j >= 0 and e[j].apellido == key.apellido and
//             e[j].nombre == key.nombre and e[j].nota > key.nota)) {
//       e[j + 1] = e[j];
//       j = j - 1;
//     }
//     e[j + 1] = key;
//   }
// }

void leerArchivo() {

  const string archivoEntradaDir = "./entradas/baseUNI.txt";

  ifstream archivo(archivoEntradaDir);

  if (!archivo) {
    cout << "Error al abrir el archivo en:" << archivoEntradaDir << endl;
    return;
  }
  string texto;
  int n = 0;

  Estudiante e[10];

  Estudiante mayorEstudiante;
  n = 0;

  cout << left << setw(5) << "Num" << setw(20) << "Apellidos" << setw(20)
       << "Nombre" << setw(10) << "Nota1" << setw(10) << "Nota2" << setw(10)
       << "Promedio" << endl;
  while (getline(archivo, texto)) {
    int p1 = texto.find('.');
    e[n].numero = stoi(texto.substr(0, p1));
    int p2 = texto.substr(p1 + 1).find(',');
    e[n].apellido = texto.substr(p1 + 1, p2);
    int p3 = texto.substr(p1 + p2 + 2).find('-');
    e[n].nombre = texto.substr(p1 + p2 + 2, p3);
    int p4 = texto.substr(p1 + p2 + p3 + 3).find('-');
    e[n].nota1 = stod(texto.substr(p1 + p2 + p3 + 3, p4));
    e[n].nota2 = stod(texto.substr(p1 + p2 + p3 + p4 + 4));
    e[n].promedio = (e[n].nota1 + e[n].nota2) / 2.;
    if (n == 0) {
      mayorEstudiante = e[0];
    } else {
      if (mayorEstudiante.promedio < e[n].promedio) {
        mayorEstudiante = e[n];
      }
    }
    cout << left << setw(5) << e[n].numero << setw(20) << e[n].apellido
         << setw(20) << e[n].nombre << setw(10) << e[n].nota1 << setw(10)
         << e[n].nota2 << setw(10) << e[n].promedio << endl;
    n++;
  }
  cout << "\n";
  cout << "El promedio maximo: " << mayorEstudiante.promedio << endl;
  cout << "Alumno: " << mayorEstudiante.nombre << " "
       << mayorEstudiante.apellido << endl;
  archivo.close();
}

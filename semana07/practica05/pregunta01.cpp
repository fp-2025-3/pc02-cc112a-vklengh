#include <fstream>
#include <iostream>

using namespace std;

struct Estudiante {
  double promedio;
  string nombre;
};

void abrirArchivo(const string &direccionEntrada, const string &direccionSalida) {
  ifstream archivo;
  ofstream archivoSalida;
  archivo.open(direccionEntrada);
  archivoSalida.open(direccionSalida);

  if (!archivo) {
    cerr << "No se pudo abrir archivo: " << direccionEntrada << endl;
    return;
  }

  if (!archivoSalida) {
    cerr << "No se pudo abrir archivo: " << direccionSalida << endl;
    return;
  }

  string linea;
  int totalEstudiantes = 0;
  double promedioCurso = 0.;
  Estudiante eMayorPromedio;
  Estudiante eMenorPromedio;
  while (getline(archivo, linea)) {

    // cout << linea << endl;
    int p1 = linea.find(" ");
    int p2 = linea.substr(p1 + 1).find(" ");
    int p3 = linea.substr(p1 + p2 + 2).find(" ");
    int p4 = linea.substr(p1 + p2 + p3 + 3).find(" ");
    int codigo = stoi(linea.substr(0, p1));
    string nombre = linea.substr(p1 + 1, p2);
    int nota1 = stoi(linea.substr(p1 + p2 + 2, p3));
    int nota2 = stoi(linea.substr(p1 + p2 + p3 + 3, p4));
    int nota3 = stoi(linea.substr(p1 + p2 + p3 + p4 + 4));
    double promedio = (nota1 + nota2 + nota3) / 3.;
    string condicion;
    if (nota1 < 5 or nota2 < 5 or nota3 < 5) {
      condicion = "DESAPROBADO POR REGLA ACADEMICA";
    } else {
      if (promedio >= 10) {
        condicion = "APROBADO";
      } else {
        condicion = "DESAPROBADO";
      }
    }

    if (totalEstudiantes == 0) {
      eMayorPromedio = {promedio, nombre};
      eMenorPromedio = {promedio, nombre};
    } else {
      if (eMayorPromedio.promedio < promedio) {
        eMayorPromedio.promedio = promedio;
        eMayorPromedio.nombre = nombre;
      }
      if (eMenorPromedio.promedio > promedio) {
        eMenorPromedio.promedio = promedio;
        eMenorPromedio.nombre = nombre;
      }
    }
    // cout << codigo << " " << nombre << " " << nota1 << " " << nota2 << " "
    //      << nota3 << endl;
    archivoSalida << codigo << " " << nombre << " " << promedio << " "
                  << condicion << endl;
    promedioCurso += promedio;
    totalEstudiantes++;
  }
  if (totalEstudiantes > 0) {
    promedioCurso /= totalEstudiantes;
    archivoSalida << "\n";
    archivoSalida << "-----------------------\n";
    archivoSalida << "Total de estudiantes: " << totalEstudiantes << endl;
    archivoSalida << "Promedio general del curso: " << promedioCurso << endl;
    archivoSalida << "Estudiante con mayor promedio: " << eMayorPromedio.nombre
                  << endl;
    archivoSalida << "Estudiante con menor promedio: " << eMenorPromedio.nombre
                  << endl;
  }

  archivo.close();
  archivoSalida.close();
}

int main() {
  const string direccionEntrada = "entradas/notas.txt";
  const string direccionSalida = "salidas/reporteAlumnos.txt";
  abrirArchivo(direccionEntrada, direccionSalida);
  return 0;
}

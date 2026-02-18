#include <fstream>
#include <iostream>

using namespace std;

struct Estudiantes {
  int numEstudiantes;
  double *nota;
  double promedio;
  double notaMayor;
  double notaMenor;
  int estudiantesAprobados;
  int estudiantesDesaprobados;
};

void estadisticasEstudiantes(Estudiantes &e);

bool abrirArchivo(fstream &archivo, int modo, const string &archivo_path);
void ejemplo02();

int main() {
  ejemplo02();
  return 0;
}

bool abrirArchivo(fstream &archivo, int modo, const string &archivo_path) {
  // 1: escritura
  // 2: lectura
  // 3: lectura - escritura
  // 4: escritura - agregar al final
  // 5: binario - agregar al final
  // 6: lectura binario
  switch (modo) {
  case 1:
    archivo.open(archivo_path, ios::out);
    break;
  case 2:
    archivo.open(archivo_path, ios::in);
    break;
  case 3:
    archivo.open(archivo_path, ios::out | ios::in);
    break;
  case 4:
    archivo.open(archivo_path, ios::out | ios::app);
    break;
  case 5:
    archivo.open(archivo_path, ios::binary | ios::app);
    break;
  case 6:
    archivo.open(archivo_path, ios::binary | ios::in);
    break;
  default:
    cerr << "Opcion invalida" << endl;
    return false;
  }
  if (!archivo) {
    cerr << "Error al abrir el archivo para la escritura" << endl;
    return false;
  }
  return true;
}
void estadisticasEstudiantes(Estudiantes &e) {
  e.notaMayor = e.nota[0];
  e.notaMenor = e.nota[0];
  e.promedio = 0;
  e.estudiantesAprobados = 0;
  e.estudiantesDesaprobados = 0;

  for (int i = 0; i < e.numEstudiantes; i++) {
    e.promedio += e.nota[i];
    if (i > 0 and e.notaMenor > e.nota[i]) {
      e.notaMenor = e.nota[i];
    }
    if (i > 0 and e.notaMayor < e.nota[i]) {
      e.notaMayor = e.nota[i];
    }
    if (e.nota[i] >= 10) {
      e.estudiantesAprobados++;
    } else {
      e.estudiantesDesaprobados++;
    }
  }
  e.promedio /= e.numEstudiantes;
}

void leerArchivo() {
  fstream archivo, archivoReporte;
  Estudiantes e;
  const string archivoDir = "outputs/notas.txt";
  const string archivoReporteDir = "outputs/reporte.txt";
  bool abierto = abrirArchivo(archivo, 2, archivoDir);
  string nombre;
  double nota;
  int contador = 0;
  if (abierto) {
    while (archivo >> nota) {
      contador++;
    }
    archivo.clear();
    archivo.seekg(0, ios::beg);
    e.numEstudiantes = contador;
    e.nota =
        new double[contador]; // mejor solucion porque no conocemos el tamanio
                              // del array, la opcion 2 seria asignar de forma
                              // constante el tamanio maximo del array
    contador = 0;
    while (archivo >> nota) {
      cout << nota << endl;
      *(e.nota + contador) = nota;
      contador++;
    }
    estadisticasEstudiantes(e);
    archivo.close();
  } else {
    cerr << "No se pudo abrir el archivo de entrada" << endl;
  }
  bool abiertoReporte = abrirArchivo(archivoReporte, 4, archivoReporteDir);
  if (abiertoReporte) {
    archivoReporte << "REPORTE GENERAL\n";
    archivoReporte << "------------------------\n";
    archivoReporte << "Total estudiantes: " << e.numEstudiantes << "\n";
    archivoReporte << "Promedio: " << e.promedio << "\n";
    archivoReporte << "Mayor nota: " << e.notaMayor << "\n";
    archivoReporte << "Menor nota: " << e.notaMenor << "\n";
    archivoReporte << "Aprobados: " << e.estudiantesAprobados << "\n";
    archivoReporte << "Desaprobados: " << e.estudiantesDesaprobados << "\n";
    archivoReporte.close();
  } else {
    cerr << "No se pudo abrir el archivo de reporte" << endl;
  }
  delete[] e.nota;
}

void ejemplo02() { leerArchivo(); }

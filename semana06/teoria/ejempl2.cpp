#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;

//--------------------------------
// ARCHIVOS BINARIOS
// Para trabajar con binarios se debe usar char[], no strings
// El tamaño debe ser fijo

struct Estudiante {
  char nombre[50];
  int nota;
};

bool abrirArchivo(fstream &archivo, int modo, const string &archivo_path);
void escribirArchivo();
void leerArchivo();
void agregarArchivo();
void estudiantesAprobados();
void trabajarConArchivo();
void escribirBinario(const string &nombreArchivo, const string &nombre,
                     int nota);
void leerBinario(const string &nombreArchivo);

int main() {
  trabajarConArchivo();
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

void escribirArchivo() {
  fstream archivo;
  string archivo_path = "archivos/notas.txt";
  bool abierto = abrirArchivo(archivo, 1, archivo_path);
  if (abierto) {
    archivo << "Juan 15\n";
    archivo << "Pedro 11\n";
    archivo << "Maria 18\n";
    archivo.close();
  } else {
    cerr << "No se pudo abrir el archivo" << endl;
  }
}

void leerArchivo() {
  fstream archivo;
  string archivo_path = "archivos/notas.txt";
  bool abierto = abrirArchivo(archivo, 2, archivo_path);
  string nombre;
  int nota;
  if (abierto) {
    while (archivo >> nombre >> nota) {
      cout << nombre << " " << nota << endl;
    }
    archivo.close();
  } else {
    cerr << "No se pudo abrir el archivo" << endl;
  }
}

void agregarArchivo() {
  fstream archivo;
  string archivo_path = "archivos/notas.txt";
  bool abierto = abrirArchivo(archivo, 4, archivo_path);
  if (abierto) {
    archivo << "Jorge 9\n";
    archivo << "Enrique 11\n";
    archivo << "David 8\n";
    archivo.close();
  } else {
    cerr << "No se pudo abrir el archivo" << endl;
  }
}

void estudiantesAprobados() {
  fstream archivo;
  string archivo_path = "archivos/notas.txt";
  bool abierto = abrirArchivo(archivo, 2, archivo_path);
  string nombre;
  int nota;
  if (abierto) {
    while (archivo >> nombre >> nota) {
      if (nota >= 10) {
        cout << nombre << " " << nota << endl;
      }
    }
    archivo.close();
  } else {
    cerr << "No se pudo abrir el archivo" << endl;
  }
}

void escribirBinario(const string &nombreArchivo, const string &nombre,
                     int nota) {
  fstream archivo;
  abrirArchivo(archivo, 5, nombreArchivo);
  Estudiante e;
  e.nota = nota;
  int sizeNombre = sizeof(e.nombre);
  strncpy(e.nombre, nombre.c_str(), sizeNombre);
  e.nombre[sizeNombre + 1] = '\0';
  // ESCRITURA en archivo binario
  archivo.write((char *)&e, sizeof(Estudiante));
  archivo.close();
}
void leerBinario(const string &nombreArchivo) {
  fstream archivo;
  abrirArchivo(archivo, 6, nombreArchivo);
  Estudiante e;
  while (archivo.read((char *)&e, sizeof(Estudiante))) {
    cout << e.nombre << " " << e.nota << endl;
  }
}

void trabajarConArchivo() {
  escribirArchivo();
  cout << "Archivo escrito:\n" << endl;
  leerArchivo();
  cout << endl;
  agregarArchivo();
  cout << "Datos añadidos:\n" << endl;
  leerArchivo();
  cout << endl;
  cout << "Estudiantes aprobados:\n" << endl;
  estudiantesAprobados();
  cout << endl;
  const string archivoBinario = "archivos/notas.bin";
  escribirBinario(archivoBinario, "Daniel",11);
  escribirBinario(archivoBinario, "Darwin",5);
  leerBinario(archivoBinario);
}

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {

  string archivo_path = "archivos/notas.txt";
  // ECRITURA EN UN ARCHIVO
  // Paso 1: instaciar el objeto
  ofstream archivoEscritura;

  // Abrir archivo en la ruta
  archivoEscritura.open(archivo_path, ios::app);

  // Verificar la integridad del archivo
  if (!archivoEscritura) {
    cerr << "Error al abrir el archivo para la escritura" << endl;
    return 1;
  }

  // Procesar los datos
  archivoEscritura << "Juan 15\n";
  archivoEscritura << "Pedro 11\n";
  archivoEscritura << "Maria 18\n";

  // Deconectar la fuente/destino
  archivoEscritura.close(); // el destructor se encarga de descaonectar

  // LECTURA EN UN ARCHIVO
  ifstream archivoLectura;
  archivoLectura.open(archivo_path);
  if (!archivoLectura) {
    cerr << "Error al abrir el archivo para la escritura" << endl;
    return 1;
  }
  string nombre;
  int nota;
  while (archivoLectura >> nombre >> nota) {
    cout << nombre << " " << nota << endl;
  }

  archivoLectura.close();

  // // Segunda forma , mediante constructores
  // ofstream f(archivo_path);
  // string s;
  //
  // if (f.is_open()){
  //     getline(f, s);
  //     while(!f.eof()){
  //         cout << s <<endl;
  //         getline(f,s);
  //     }
  //
  // }

  return 0;
}

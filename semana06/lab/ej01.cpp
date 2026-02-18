#include <cstring>
#include <fstream>
#include <iostream>

const int DIAS = 7;

void trab();
using namespace std;

bool abrirArchivo(fstream &archivo, int modo, const string &archivo_path);

int main() { 
    trab();
    return 0; }

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

struct VentasSemanales {
  double ventaDiaria[DIAS];
  double total;
  double promedio;
  double mayorVenta;
  double menorVenta;
};

void estadisticasVenta(VentasSemanales &ventas) {
  ventas.menorVenta = ventas.ventaDiaria[0];
  ventas.mayorVenta = ventas.ventaDiaria[0];
  ventas.total = ventas.ventaDiaria[0];
  for (int i = 1; i < DIAS; i++) {
    ventas.total += ventas.ventaDiaria[i];
    if (ventas.menorVenta > ventas.ventaDiaria[i]) {
      ventas.menorVenta = ventas.ventaDiaria[i];
    }
    if (ventas.mayorVenta < ventas.ventaDiaria[i]) {
      ventas.mayorVenta = ventas.ventaDiaria[i];
    }
  }
  ventas.promedio = ventas.total / DIAS;
}

void trab() {
  fstream archivo;
  const string archivoDir = "outputs/ventas.txt";
  bool abierto = abrirArchivo(archivo, 4, archivoDir);
  VentasSemanales ventas;

  if (abierto) {
    double venta;
    for (int i = 1; i <= DIAS; i++) {
      cout << "Ingrese la venta del dia: " << i << ":";
      cin >> venta;
      ventas.ventaDiaria[i - 1] = venta;
      archivo << venta<<"\n";
    }
    estadisticasVenta(ventas);
    archivo << "---------------------------\n";
    archivo << "RESUMEN\n";
    archivo << "Total: "<< ventas.total<<"\n";
    archivo << "Promedio: "<< ventas.promedio<<"\n";
    archivo << "Mayor venta: "<< ventas.mayorVenta<<"\n";
    archivo << "Menor venta: "<< ventas.menorVenta<<"\n";
    archivo.close();
  } else {
    cerr << "No se pudo abrir el archivo" << endl;
    return;
  }
}

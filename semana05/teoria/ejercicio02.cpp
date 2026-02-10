#include <iostream>

using namespace std;

struct Fecha {
  int dia;
  int mes;
  int anio;
};

struct Contacto {
  char nombre[20];
  Fecha fechaNacimiento;
};

Contacto *crearContacto(int &n) {
  cout << "Ingrese la cantidad de contactos: " << endl;
  cin >> n;
  Contacto *c = new Contacto[n];
  return c;
}

void leerDatos(Contacto *c, int n) {
  for (int i = 0; i < n; i++) {
    cout << "Para el contacto: " << i + 1 << endl;
    cout << "Nombre: ";
    cin >> c[i].nombre;
    cout << "Fecha (dia mes anio): ";
    cin >> c[i].fechaNacimiento.dia;
    cin >> c[i].fechaNacimiento.mes;
    cin >> c[i].fechaNacimiento.anio;
  }
}

void mostrarContacto(Contacto *c, int n) {
  int anio;
  cout << "Ingrese el el anio de la fecha de nacimiento para buscar contactos: "
       << endl;
  cin >> anio;
  cout << "Mostrar los contactos nacidos en el anio: " << anio << endl;
  bool hayContactos = false;
  for (int i = 0; i < n; i++) {
    if (c[i].fechaNacimiento.anio == anio) {
      cout << "Contacto: " << c[i].nombre << " ";
      cout << " ,fecha de nacimiento: " << c[i].fechaNacimiento.dia << " "
           << c[i].fechaNacimiento.dia << " " << c[i].fechaNacimiento.dia
           << endl;
      if (!hayContactos) {
        hayContactos = true;
      }
    }
  }
  if (!hayContactos) {
    cout << "No hay contactos nacidos en el anio " << anio << "." << endl;
  }
}

void liberarMemoria(Contacto *&e) {
  delete[] e;
  e = nullptr;
}

int main() {
  int n;
  Contacto *e = crearContacto(n);
  leerDatos(e, n);
  mostrarContacto(e, n);
  liberarMemoria(e);
  return 0;
}

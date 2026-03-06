#include <fstream>
#include <iostream>
using namespace std;

struct Proyecto {
  int id;
  char titulo[40];
  double presupuesto;
  int duracionMeses;
};

void insertionsort(Proyecto arr[], int n) {
  for (int i = 0; i < n; i++) {
    Proyecto key = arr[i];
    int j = i - 1;
    while (j >= 0 and arr[j].presupuesto < key.presupuesto) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
}

void crearArchivo(string &direccion, int N) {
  ofstream archivo;
  archivo.open(direccion, ios::binary);
  if (!archivo) {
    cerr << "No se pudo leer archivo.\n";
    return;
  }
  Proyecto *proyectos = new Proyecto[N];
  for (int i = 0; i < N; i++) {
    cout << "Ingrese id del proyecto: ";
    cin >> proyectos[i].id;

    cout << "Ingrese el titulo del proyecto: ";
    cin >> proyectos[i].titulo;

    cout << "Ingrese el presupuesto del proyecto: ";
    cin >> proyectos[i].presupuesto;

    cout << "Ingrese la duracion en meses del proyecto: ";
    cin >> proyectos[i].duracionMeses;
  }
  insertionsort(proyectos, N);
  for (int i = 0; i < N; i++) {
    archivo.seekp((i) * sizeof(Proyecto), ios::beg);
    archivo.write((char *)&proyectos[i], sizeof(Proyecto));
    cout << "ID: " << proyectos[i].id << endl;
    cout << "Titulo: " << proyectos[i].titulo << endl;
    cout << "Presupuesto: " << proyectos[i].presupuesto << endl;
    cout << "Duracion: " << proyectos[i].duracionMeses << " meses" << endl;
  }

  delete[] proyectos;
  proyectos = nullptr;
  archivo.close();
}

void agregarProyecto(string &direccion) {
  fstream archivo;
  archivo.open(direccion, ios::binary | ios::in | ios::out);
  if (!archivo) {
    cerr << "No se pudo leer archivo.\n";
    return;
  }
  Proyecto proyecto, proyOut;
  int pos = 1;

  cout << "Ingrese id del proyecto: ";
  cin >> proyecto.id;

  cout << "Ingrese el titulo del proyecto: ";
  cin >> proyecto.titulo;

  cout << "Ingrese el presupuesto del proyecto: ";
  cin >> proyecto.presupuesto;

  cout << "Ingrese la duracion en meses del proyecto: ";
  cin >> proyecto.duracionMeses;
  archivo.seekg((pos) * sizeof(Proyecto), ios::beg);
  Proyecto copia;
  while (archivo.read((char *)&proyOut, sizeof(Proyecto))) {
    // cout << "ID: " << proyOut.id << endl;
    // cout << "Titulo: " << proyOut.titulo << endl;
    // cout << "Presupuesto: " << proyOut.presupuesto << endl;
    // cout << "Duracion: " << proyOut.duracionMeses << " meses" << endl;
    if (proyOut.presupuesto < proyecto.presupuesto) {
      break;
    }
    pos++;
    archivo.seekg((pos) * sizeof(Proyecto), ios::beg);
  }
  // archivo.seekg((pos) * sizeof(Proyecto), ios::beg);
  // archivo.read((char *)&proyecto, sizeof(Proyecto) * pos);
  // cout << "continuando.......\n";
  archivo.seekg((pos) * sizeof(Proyecto), ios::beg);
  archivo.read((char *)&copia, sizeof(Proyecto));
  archivo.seekg((pos+1) * sizeof(Proyecto), ios::beg);

  // cout << "ID: " << copia.id << endl;
  // cout << "Titulo: " << copia.titulo << endl;
  // cout << "Presupuesto: " << copia.presupuesto << endl;
  // cout << "Duracion: " << copia.duracionMeses << " meses" << endl;
  //
  // cout << ".....\n";
  // cout << "ID: " <<proyecto.id << endl;
  // cout << "Titulo: " << proyecto.titulo << endl;
  // cout << "Presupuesto: " << proyecto.presupuesto << endl;
  // cout << "Duracion: " << proyecto.duracionMeses << " meses" << endl;
  archivo.seekp((pos) * sizeof(Proyecto), ios::beg);
  archivo.write((char *)&proyecto, sizeof(Proyecto));
  pos++;
  while (archivo.read((char *)&proyOut, sizeof(Proyecto))) {
    copia = proyOut;
    archivo.seekp((pos) * sizeof(Proyecto), ios::beg);
    archivo.write((char *)&copia, sizeof(Proyecto));
    // cout << "ID: " << proyOut.id << endl;
    // cout << "Titulo: " << proyOut.titulo << endl;
    // cout << "Presupuesto: " << proyOut.presupuesto << endl;
    // cout << "Duracion: " << proyOut.duracionMeses << " meses" << endl;
    copia = proyOut;
    pos++;
    archivo.seekg((pos) * sizeof(Proyecto), ios::beg);
  }
    archivo.seekp(-sizeof(Proyecto), ios::end);
    archivo.write((char *)&copia, sizeof(Proyecto));

  archivo.close();
}

void leerProyecto(string &direccion) {
// cp salidas/proyectos1.dat salidas/proyectos.dat

  fstream archivo;
  archivo.open(direccion, ios::binary | ios::in | ios::out);
  if (!archivo) {
    cerr << "No se pudo leer archivo.\n";
    return;
  }
  Proyecto proyOut;
  int pos = 0;
  while (archivo.read((char *)&proyOut, sizeof(Proyecto))) {
    cout << "ID: " << proyOut.id << endl;
    cout << "Titulo: " << proyOut.titulo << endl;
    cout << "Presupuesto: " << proyOut.presupuesto << endl;
    cout << "Duracion: " << proyOut.duracionMeses << " meses" << endl;
    pos++;
    archivo.seekg((pos) * sizeof(Proyecto), ios::beg);
  }

  // archivo.seekg((pos) * sizeof(Proyecto), ios::beg);
  // archivo.read((char *)&proyecto, sizeof(Proyecto) * pos);

  archivo.close();
}

int main() {
  string dir = "salidas/proyectos.dat";
  int N;
  cout << "Ingrese la cantidad de proyectos que quiere registrar: ";
  cin >> N;
  crearArchivo(dir, N);
  leerProyecto(dir);
  agregarProyecto(dir);
  return 0;
}

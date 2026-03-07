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
    cout << "Proyecto " << i + 1 << endl;
    cout << "ID: ";
    cin >> proyectos[i].id;

    cout << "Titulo: ";
    cin >> proyectos[i].titulo;

    cout << "Presupuesto: ";
    cin >> proyectos[i].presupuesto;

    cout << "Duracion (meses): ";
    cin >> proyectos[i].duracionMeses;
    cout << endl;
  }
  insertionsort(proyectos, N);
  for (int i = 0; i < N; i++) {
    archivo.seekp((i) * sizeof(Proyecto), ios::beg);
    archivo.write((char *)&proyectos[i], sizeof(Proyecto));
    // cout << "ID: " << proyectos[i].id << endl;
    // cout << "Titulo: " << proyectos[i].titulo << endl;
    // cout << "Presupuesto: " << proyectos[i].presupuesto << endl;
    // cout << "Duracion: " << proyectos[i].duracionMeses << " meses" << endl;
  }

  delete[] proyectos;
  proyectos = nullptr;
  archivo.close();
}
void agregarProyecto(string &direccion) {
  fstream archivo(direccion, ios::binary | ios::in | ios::out);
  if (!archivo) {
    cerr << "No se pudo abrir archivo.\n";
    return;
  }

  Proyecto proyecto;

  cout << "Nuevo proyecto a insertar\n";
  cout << "ID: ";
  cin >> proyecto.id;

  int n = 0;
  Proyecto temp;

  archivo.seekg(0, ios::beg);

  // verificar ID repetido y contar registros
  while (archivo.read((char *)&temp, sizeof(Proyecto))) {
    if (temp.id == proyecto.id) {
      cout << "Error: el ID ya existe.\n";
      archivo.close();
      return;
    }
    n++;
  }

  cout << "Titulo: ";
  cin >> proyecto.titulo;

  cout << "Presupuesto: ";
  cin >> proyecto.presupuesto;

  cout << "Duracion (meses): ";
  cin >> proyecto.duracionMeses;
  cout << endl;

  int pos = 0;

  archivo.clear(); // limpiar EOF
  archivo.seekg(0, ios::beg);

  // buscar posición de inserción
  while (pos < n) {
    archivo.read((char *)&temp, sizeof(Proyecto));

    if (temp.presupuesto < proyecto.presupuesto)
      break;

    pos++;
  }

  int i = n - 1;

  // mover registros hacia la derecha
  while (i >= pos) {
    archivo.seekg(i * sizeof(Proyecto), ios::beg);
    archivo.read((char *)&temp, sizeof(Proyecto));

    archivo.seekp((i + 1) * sizeof(Proyecto), ios::beg);
    archivo.write((char *)&temp, sizeof(Proyecto));

    i--;
  }

  // insertar nuevo proyecto
  archivo.seekp(pos * sizeof(Proyecto), ios::beg);
  archivo.write((char *)&proyecto, sizeof(Proyecto));

  archivo.close();
}
void leerProyecto(string &direccion) {

  fstream archivo;
  archivo.open(direccion, ios::binary | ios::in | ios::out);
  if (!archivo) {
    cerr << "No se pudo leer archivo.\n";
    return;
  }
  Proyecto proyOut;
  int pos = 0;
  cout << "Contenido del archivo\n";
  while (archivo.read((char *)&proyOut, sizeof(Proyecto))) {
    cout << proyOut.id << " " << proyOut.titulo << " " << proyOut.presupuesto
         << " " << proyOut.duracionMeses << endl;
    pos++;
    archivo.seekg((pos) * sizeof(Proyecto), ios::beg);
  }

  archivo.close();
}

int main() {
  string dir = "salidas/proyectos.dat";
  int N;
  cout << "Numero de proyectos: ";
  cin >> N;
  cout << endl;
  crearArchivo(dir, N);
  agregarProyecto(dir);
  leerProyecto(dir);
  return 0;
}

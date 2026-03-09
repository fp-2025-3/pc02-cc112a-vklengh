#include <fstream>
#include <iostream>

const int MAX_LIBROS = 100;
using namespace std;

struct Libro {
  int codigo;
  char titulo[50];
  bool prestado;
};

struct Usuario {
  int codigo;
  string nombre;
};

void registrarLibro(Libro libros[], int &n);

int buscarLibro(Libro libros[], int n, int codigo);

void prestarLibro(Libro libros[], int n, int codigo);

void devolverLibro(Libro libros[], int n, int codigo);

void guardarEnArchivo(Libro libros[], int n);

void cargarDesdeArchivo(Libro libros[], int n);

void mostrarLibros(Libro libros[], int n);

void menu();

int main() { return 0; }

void menu() {
  bool terminado = false;
  while (!terminado) {
    int opcion;
    int n = 0;
    Libro libros[MAX_LIBROS];
    cout << "MENU\n";
    cout << "--------------------------------------\n";
    cout << "Presione 1 para registrar libro\n";
    cout << "Presione 2 para buscar libro\n";
    cout << "Presione 3 para prestar libro\n";
    cout << "Presione 4 para devolver libro\n";
    cout << "Presione 5 para guardar archivo\n";
    cout << "Presione 6 para cargar archivo\n";
    cout << "Presione 7 para mostrar libros\n";
    cin >> opcion;
    switch (opcion) {
    case 1: {
      registrarLibro(libros, n);
      break;
    }
    case 2: {
      int codigo;
      cout << "Ingrese codigo del libro: ";
      cin >> codigo;
      int idx = buscarLibro(libros, n, codigo);
      if (idx == -1) {
        cout << "Libro no encontrado\n";
      } else {
        cout << "Libro encontrado en: " << idx << "\n";
      }
      break;
    }
    case 3: {
      prestarLibro(libros, n, 0);
      break;
    }
    case 4: {
      devolverLibro(libros, n, 0);
      break;
    }
    case 5: {
      guardarEnArchivo(libros, n);
      break;
    }
    case 6: {
      cargarDesdeArchivo(libros, n);
      break;
    }
    case 7: {
      mostrarLibros(libros, n);
      break;
    }
    default: {
      cout << "Opcion invalida, intentelo nuevamente\n";
      break;
    }
    }
  }
}

void registrarLibro(Libro libros[], int &n) {
  if (n > MAX_LIBROS) {
    cout << "Capacidad de libros sobrepasada\n";
    return;
  }
  cout << "Registre el libro " << n + 1 << endl;
  cout << "Ingrese el codigo del libro: ";
  cin >> libros[n].codigo;
  cin.ignore();
  cout << "Ingrese el titulo del libro: ";
  cin.getline(libros[n].titulo, 50);
  libros[n].prestado = false;
  n++;
}

int buscarLibro(Libro libros[], int n, int codigo) {
  for (int i = 0; i < n; i++) {
    if (libros[i].codigo == codigo) {
      return i;
    }
  }
  return -1;
}

void prestarLibro(Libro libros[], int n, int codigo) {}

void devolverLibro(Libro libros[], int n, int codigo) {}

void guardarEnArchivo(Libro libros[], int n) {}

void cargarDesdeArchivo(Libro libros[], int n) {}

void mostrarLibros(Libro libros[], int n) {}

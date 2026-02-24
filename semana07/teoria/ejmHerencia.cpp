#include <fstream>
#include <iostream>

using namespace std;

class Libro {
private:
  string titulo;
  string autor;
  int paginas;

public:
  // CONSTRUCTOR
  Libro(string t, string a, int p) : titulo(t), autor(a), paginas(p) {
    cout << "Llamando al constructor\n";
  };

  // DESTRUCTOR
  ~Libro() { cout << "Llamando al destructor\n"; };

  // getter
  string getTitulo() { return titulo; }
  // setter
  void setTitulo(string t) { titulo = t; }

  void mostrarInfo() {
    cout << "Titutlo: " << titulo << " | Autor: " << autor << " | Paginas "
         << paginas << endl;
  }
};

class LibroDigital : public Libro {
private:
  string formato;

public:
  // CONSTRUCTOR HEREDADO
  LibroDigital(string t, string a, int p, string f)
      : Libro(t, a, p), formato(f) {
    cout << "Llamando al constructor de clase derivada\n";
  };
  // DESTRUCTOR
  ~LibroDigital() { cout << "Llamando al destructor de clase derivada\n"; };
  void mostrarInfoDigital() {
    mostrarInfo();
    cout << "Formato digital: " << formato << endl;
  }
};

int main() {
  Libro libro1("Ek", "Antonio", 100);
  Libro libro2("Ak", "Cervantes", 800);
  libro1.mostrarInfo();
  libro2.mostrarInfo();
  LibroDigital libroDigital1("Ck", "Fervantes", 200, "PDF");
  libroDigital1.mostrarInfoDigital();
  return 0;
}

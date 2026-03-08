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
  Libro(string t, string a, int p) : titulo(t), autor(a), paginas(p) {};

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

int main() {
  Libro libro1("Ek", "Antonio", 100);
  Libro libro2("Ak", "Cervantes", 800);
  libro1.mostrarInfo();
  libro2.mostrarInfo();
  return 0;
}

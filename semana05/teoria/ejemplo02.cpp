#include <iostream>
using namespace std;

// Estructura autoreferenciada
struct Producto {
  int codigo;
  float precio;
  Producto *sig;
};

int main() {
  Producto *cabeza = nullptr;
  // Insertar producto al inicio
  for (int i = 0; i < 2; i++) {
    Producto *nuevo = new Producto;
    cout << "Ingrese codigo: ";
    cin >> nuevo->codigo;
    cout << "Ingrese precio: ";
    cin >> nuevo->precio;
    nuevo->sig = cabeza;
    cabeza = nuevo;
  }
  // Imprime los elementos
  Producto *aux = cabeza;
  while (aux != nullptr) {
    cout << "Codigo: " << aux->codigo << " Precio: " << aux->precio << endl;
    aux = aux->sig;
  }

  // Limpia la memoria
  while (cabeza != nullptr) {
    Producto *temp = cabeza;
    cabeza = cabeza->sig;
    delete temp;
  }
  return 0;
}

#include <iostream>
using namespace std;

struct Pasajero {
  int dni;
  char nombre[50];
};

struct Asiento {
  int numero;
  bool reservado;
  Pasajero *pasajero; // nullptr si está libre
};

struct NodoReserva {
  Pasajero pasajero;
  int numeroAsiento;
  NodoReserva *siguiente;
};

struct Vuelo {
  char codigo[10];
  char destino[50];
  int capacidad;
  Asiento *asientos;          // arreglo dinámico
  NodoReserva *listaReservas; // lista enlazada
};

void crearVuelo(Vuelo &vuelo) {
  cout << "Ingrese el código del vuelo: ";
  cin >> vuelo.codigo;

  cout << "Ingrese el destino: ";
  cin.ignore();
  cin.getline(vuelo.destino, 50);

  cout << "Ingrese la capacidad: ";
  cin >> vuelo.capacidad;

  // Reservamos memoria dinámica para la cantidad de asientos

  vuelo.asientos = new Asiento[vuelo.capacidad];

  for (int i = 0; i < vuelo.capacidad; ++i) {
    vuelo.asientos[i].numero = i + 1;
    vuelo.asientos[i].reservado = false;
    vuelo.asientos[i].pasajero = nullptr;
  }

  vuelo.listaReservas = nullptr;
}

int main() {

  Vuelo vuelo;

  crearVuelo(vuelo);

  return 0;
}

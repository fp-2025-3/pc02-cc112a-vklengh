#include <cmath>
#include <iostream>

using namespace std;

struct Punto {
  float x;
  float y;
  float z;
};

float distancia(Punto p1, Punto p2) {
  return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2) + pow(p1.z - p2.z, 2));
}

Punto leerPunto(string texto) {
  Punto p;
  cout << "Ingrese las coordenadas del " << texto << " punto" << endl;
  cout << "X: ";
  cin >> p.x;
  cout << "Y: ";
  cin >> p.y;
  cout << "Z: ";
  cin >> p.z;
  return p;
}

int main() {
  Punto p1 = leerPunto("primer");
  Punto p2 = leerPunto("segundo");
  float dist = distancia(p1, p2);
  cout << "La distancia entre los dos puntos es: "<<dist<<endl;

  return 0;
}

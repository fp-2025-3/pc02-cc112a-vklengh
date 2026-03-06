#include <cmath>
#include <iostream>
using namespace std;

struct Punto {
  double x;
  double y;
};

void leerPunto(Punto *p);
double distanciaOrigen(const Punto *p);
Punto *masLejano(Punto *p1, Punto *p2);

int main() {
  // algo
  Punto *p1 = new Punto;
  Punto *p2 = new Punto;
  Punto *pLejano = new Punto;
  leerPunto(p1);
  leerPunto(p2);
  pLejano = masLejano(p1, p2);
  cout << "Punto mas lejano x: " << (*pLejano).x << " | y:" << (*pLejano).y
       << endl;
  delete p1;
  delete p2;
  delete pLejano;

  p1 = nullptr;
  p2 = nullptr;
  pLejano = nullptr;
  return 0;
}

void leerPunto(Punto *p) {
  cout << "Ingrese la coordenada x:";
  cin >> (*p).x;
  cout << "Ingrese la coordenada y:";
  cin >> (*p).y;
}
double distanciaOrigen(const Punto *p) {
  return pow((pow((*p).x, 2) + pow((*p).y, 2)), 0.5);
}

Punto *masLejano(Punto *p1, Punto *p2) {
  double dist1 = distanciaOrigen(p1);
  double dist2 = distanciaOrigen(p2);
  if (dist1 > dist2) {
    return p1;
  } else {
    return p2;
  }
}

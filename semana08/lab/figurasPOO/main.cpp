#include "circulo.h"
#include "figura.h"
#include "gestorFiguras.h"
#include "rectangulo.h"
#include <iostream>

using namespace std;
int main() {
  // Figura *f[] = {new Circulo("",0,0,0,0)};
  // Circulo c("circ1",1,2,3,5);
  // Rectangulo r("rec1",1,2,3,5,10);
  // int cantidad = 2;
  // Figura **figura = new Figura*[cantidad];
  // *figura[0] = c;
  // *figura[1] = r;
  // GestorFiguras gf(figura, cantidad, 10);
  //
  // c.imprimir();
  // r.imprimir();

  // GestorFiguras gestor;
  Figura *f1 = new Rectangulo("rec1", 1, 2, 3, 4, 5);
  Figura *f2 = new Circulo("circ1", 7, 8, 9, 3);
  int cant = 2;
  Figura **f = new Figura *[cant] { f1, f2 };
  GestorFiguras gestor(f, cant, 2);
  // gestor.mostrarFiguras();
  gestor.mostrarCapacidad();
  // gestor.aumentarCapacidad(10);

  Figura *f3 = new Rectangulo("rec2", 4, 5, 6, 15, 20);
  Figura *f4 = new Circulo("circ2", 11, 12, 13, 16);
  gestor.agregarFiguras(f4);
  gestor.agregarFiguras(f3);

  // gestor.mostrarFiguras();
  // cout << "Area total: "<<gestor.area()<<endl;
  // cout << "Perimetro total: "<<gestor.perimetro()<<endl;

  cout << gestor.getInfo() << endl;

  delete[] f;
  f = nullptr;
  delete f3;
  delete f4;
  string salida = "salidas/archivo.txt";
  gestor.guardarArchivo(salida);

  return 0;
}

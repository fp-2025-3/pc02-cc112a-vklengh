#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>

using namespace std;

struct Equipo {
  int pg;
  int pp;
  int pe;
  int puntaje;
  float rendimiento;
};

void imprimirSeleccion(Equipo e, int n) {
  cout << "Pais_seleccion " << n << setw(10) << e.pg << setw(5) << e.pp
       << setw(5) << e.pe << setw(10) << e.puntaje << setw(15) << e.rendimiento
       << endl;
}
void generarPuntaje(Equipo e[], int n) {
  cout << "Seleccion" << setw(17) << "PG" << setw(5) << "PP" << setw(5) << "PE"
       << setw(10) << "Puntaje" << setw(15) << "Rendimiento" << endl;
  for (int i = 0; i < n; i++) {
    e[i].pg = rand() % 101;
    e[i].pp = 0;
    e[i].pe = 0;
    if (e[i].pg < 100) {
      e[i].pp = rand() % (101 - e[i].pg);
      if (e[i].pp + e[i].pg < 100) {
        e[i].pe = 100 - e[i].pp - e[i].pg;
      }
    }
    e[i].puntaje = e[i].pg * 3 + e[i].pe;
    e[i].rendimiento = e[i].puntaje / 3.;
    imprimirSeleccion(e[i], i);
  }
}

void mejorRendimiento(Equipo e[], int n) {
  int mejorIndex = 0;
  Equipo mejorEquipo = e[mejorIndex];
  for (int i = 1; i < n; i++) {
    if (mejorEquipo.rendimiento < e[i].rendimiento) {
      mejorEquipo = e[i];
      mejorIndex = i;
    }
  }
  cout << "La seleccion con mejor rendimiento es: Seleccion " << mejorIndex
       << " Rendimiento: " << mejorEquipo.rendimiento << endl;
}

int main() {
  srand(time(0));
  Equipo e[5];
  int n = sizeof(e) / sizeof(e[0]);
  generarPuntaje(e, n);
  mejorRendimiento(e, n);
  return 0;
}

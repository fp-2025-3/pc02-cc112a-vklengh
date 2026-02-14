#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>

using namespace std;

struct Equipo {
  int pg;
  int pp;
  int pe;
  int gf; // goles a favor
  int gc; // goles en contra
  int dg; // diferencia de goles
  int puntaje;
  int nombre;
  float rendimiento;
};

void imprimirSeleccion(Equipo e) {
  cout << "Pais_" << e.nombre << setw(10) << e.pg << setw(5) << e.pe << setw(5)
       << e.pp << setw(5) << e.gf << setw(5) << e.gc << setw(5) << e.dg
       << setw(10) << e.puntaje << setw(12) << fixed << setprecision(1)
       << e.rendimiento << endl;
}
void encabezado(){
  cout << "Seleccion" << setw(7) << "PG" << setw(5) << "PE" << setw(5) << "PP"
       << setw(5) << "GF" << setw(5) << "GC" << setw(5) << "DG" << setw(5)
       << setw(10) << "Pts" << setw(15) << "Rend(%)" << endl;
  cout << "--------------------------------------------------------------------"
          "-----"
       << endl;
}
void generarPuntaje(Equipo e[], int n) {
    encabezado();

  for (int i = 0; i < n; i++) {
    e[i].nombre = i;
    e[i].pg = 0;
    e[i].pp = 0;
    e[i].pe = 0;

    e[i].gc = 0;
    e[i].gf = 0;
    e[i].dg = 0;
    // generar goles
    for (int j = 0; j < 100; j++) {
      int golaFavor = rand() % 6;
      int golContra = rand() % 6;
      int difGoles = golaFavor - golContra;
      e[i].gf += golaFavor;
      e[i].gc += golContra;
      e[i].dg += difGoles;

      if (difGoles == 0) {
        e[i].pe += 1;
      } else if (difGoles > 0) {
        e[i].pg += 1;
      } else {
        e[i].pp += 1;
      }
    }

    e[i].puntaje = e[i].pg * 3 + e[i].pe;
    e[i].rendimiento = e[i].puntaje / 3.;
    imprimirSeleccion(e[i]);
  }
}

void ordenarSeleccion(Equipo e[], int n) {
    encabezado();
  for (int i = 0; i < n; i++) {
    int key = e[i].puntaje;
    int keyDg = e[i].dg;
    int keyGf = e[i].gf;
    int j = i - 1;
    Equipo eqTemp = e[i];
    while (j >= 0 and
           (e[j].puntaje < key or (e[j].puntaje == key and e[j].dg < keyDg) or
            (e[j].puntaje == key and e[j].dg < keyDg and e[j].gf < keyGf))) {
      e[j + 1] = e[j];
      j = j - 1;
    }
    e[j + 1] = eqTemp;
  }

  for (int i = 0; i < n; i++) {
    imprimirSeleccion(e[i]);
  }
  cout << endl;
  cout << "CAMPEON: Pais_" << e[0].nombre << " | Puntaje: " << e[0].puntaje
       << " | DG: " << e[0].dg << " | Rendimiento: " << e[0].rendimiento << "%"
       << endl;
}

int main() {
  srand(time(0));
  Equipo e[5];
  int n = sizeof(e) / sizeof(e[0]);
  cout << "Equipos sin ordenar\n"<<endl;
  generarPuntaje(e, n);
  // mejorRendimiento(e, n);
  cout << endl;
  cout <<"Equipos ordenados\n"<<endl;
  ordenarSeleccion(e, n);
  return 0;
}

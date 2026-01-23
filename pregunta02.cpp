#include <iostream>
#include <string>
using namespace std;

// Complete la funcion de busqueda
int *buscar(
    int *inicio, // Estos dos primeros parametros
    int *fin,    // delimitan el rango de busqueda a [inicio, fin)
    bool (*equivale)(int, int), // equivale es una funcion que determina cuando
                                // dos enteros se condideran equivalentes
    int clave // clave es el valor a buscar segun el criterio indicado
) {
  for (int *p = inicio; p < fin; p++) {
    // cout << *p << endl;
    if (equivale(*p, clave)) {
      return p;
    }
  }
  return nullptr;
  // Complete aqui
}

// Implemente aqui los Criterios de equivalencia
// y si es necesario algunas funciones adicionales para reproducir el ejemplo de
// salida
bool igual(int a, int b) { return a == b; }

int abs(int a){
    if (a>0){
        a = -a;
    }
    return a;
}
bool mismaParidad(int a, int b) {
  int resA = abs(a) % 2; // Tomar abs ya que puede retornar -1 el modulo
  int resB = abs(b) % 2;
  if (resA == resB){
    return true;
  } else {
    return false;
  }
}
bool divideA(int a, int b) {
  if (b % a == 0) {
    return true;
  } else {
    return false;
  }
}
int cantDigitos(int a) {
  int dig = 0;
  while (a != 0) {
    a = a / 10;
    dig++;
  }
  return dig;
}

bool mismaCantidadDigitos(int a, int b) {
  int cantDigA = cantDigitos(a);
  int cantDigB = cantDigitos(b);
  if (cantDigA == cantDigB) {
    return true;
  } else {
    return false;
  }
}
bool mismoResiduoMod5(int a, int b) {
  int resA = a % 5;
  int resB = b % 5;
  if (resA == resB) {
    return true;
  } else {
    return false;
  }
}

void imprimirArray(int *inicio, int *fin) {
  for (int *p = inicio; p < fin; p++) {
    cout << *p << " ";
  }
  cout << endl;
}

void imprimirRes(int *p, string texto) {
  if (p != nullptr) {
    cout << texto << " encontrado valor: " << *p << " Pos: " << p << endl;
  } else {
    cout << "Buscqueda no encontrada" << endl;
  }
}
int main() {
  int A[] = {-1, 21, 2, -2, 8, 13, 25};
  int *inicio = A;
  int *fin = A + 7;

  int clave = 13;
  bool (*equivale)(int, int);
  cout << " Arreglo: ";
  imprimirArray(inicio, fin);
  cout << " Clave: " << clave << endl;

  int *pbusc = buscar(inicio, fin, igual, clave);
  // Imprima el arreglo
  string texto = "Igualdad exacta: ";
  imprimirRes(pbusc, texto);
  pbusc = buscar(inicio, fin, mismaParidad, clave);
  texto = "Misma paridad: ";
  imprimirRes(pbusc, texto);
  pbusc = buscar(inicio, fin, divideA, clave);
  texto = "Divide a: ";
  imprimirRes(pbusc, texto);
  pbusc = buscar(inicio, fin, mismaCantidadDigitos, clave);
  texto = "Misma cantidad de digitos: ";
  imprimirRes(pbusc, texto);
  pbusc = buscar(inicio, fin, mismoResiduoMod5, clave);
  texto = "Mismo residuo modulo 5: ";
  imprimirRes(pbusc, texto);

  // Llame a la funcion buscar para cada criterio implementado
  return 0;
}

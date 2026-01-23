#include <iostream>
using namespace std;

// Complete la funcion que calcula la derivada de orden k de un polinomio
// Usar EXCLUSIVAMENTE punteros (NO indices)
//

void derivadaK(const double *coef, //
               int grado, int k,   //
               double *res,        //
               int &gradoRes       //
) {
  // Escriba su codigo aqui
  gradoRes = grado - k; // 3 - 2  = 1

  int gradoAc = 0;
  for (const double *p = coef; p <= coef + grado; p++) {
    if (gradoAc - gradoRes > 0) {
      *res = *p;
      for (int i = gradoAc; i > 0; i--) {
        *res = *res * i;
      }
      res++;
    }
    gradoAc++;
  }
}

// Complete la función auxiliar para imprimir un polinomio
void imprimirPolinomio(const double *p, int grado) {
  int exp = grado;
  for (const double *i = p+grado; i >= p; i--) {
    if (*i != 0) {
      if (exp == 0) {
        cout << *i << " ";
      } else if (exp == 1) {
        cout << *i << "x ";
      } else {
        cout << *i << "x^" << exp;
      }
      if (exp != 0) {
        cout << " + ";
      }
      exp--;
    }
  }
  cout << endl;
}

int main() {
  // Polinomio:
  // P(x) = 2 + 3x - x^2 + 4x^3
  double coef[] = {2, 3, -1, 4};
  const int grado = 3;

  double resultado[10]; // espacio suficiente
  // int gradoResultado;
  int gradoResultado = 2;

  int k = 2; // derivada de orden 2

  cout << "Polinomio original:" <<endl;
  imprimirPolinomio(coef, 3);
  derivadaK(coef, grado, k, resultado, gradoResultado);
  cout << "Derivada de orden: "<<k <<endl;
  imprimirPolinomio(resultado, gradoResultado);
  // Llamar a su funcion derivadaK

  // Llamar la funcion imprimir para mostrar el polinomio original y  la
  // derivada

  return 0;
}

void imprimir2(const int *inicio, const int *fin) {
  int exp = 0;
  for (const int *p = inicio; p < fin; p++) {
    if (*p != 0) {
      if (exp == 0) {
        cout << *p << " ";
      } else if (exp == 1) {
        cout << *p << "x ";
      } else {
        cout << *p << "x^" << exp;
      }
      if (p != fin - 1) {
        cout << " + ";
        // if (*p >= 0) {
        //   cout << " + ";
        // } else {
        //   cout << " ";
        // }
      }
      exp++;
    }
  }
  cout << endl;
}


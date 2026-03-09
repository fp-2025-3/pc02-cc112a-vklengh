#include <cmath>
#include <iostream>
// python tutor (visualizador de punteros)

using namespace std;

struct Polinomio {
  int *coef;
  int grado;
};

Polinomio *crearPolinomio(int &n, string texto) {
  cout << "Ingrese el grado del " << texto << " polinomio: ";
  cin >> n;
  Polinomio *p = new Polinomio;
  (*p).coef = new int[n + 1];
  (*p).grado = n;
  return p;
}

void leerDatos(Polinomio *p) {
  for (int i = 0; i < (*p).grado + 1; i++) {
    cout << "Ingrese el coeficiente de x^" << (*p).grado - i << ": ";
    cin >> *((*p).coef + i);
  }
}

void escribirPol(Polinomio *p, string texto) {
  cout << texto << " polinomio: ";
  for (int i = 0; i < (*p).grado + 1; i++) {
    if (i != (*p).grado) {
      cout << *((*p).coef + i) << "x^" << (*p).grado - i << " + ";
    } else {
      cout << *((*p).coef + i) << endl;
    }
  }
}
void liberarMemoria(Polinomio *&p) {
  delete[] (*p).coef;
  (*p).coef = nullptr;
  delete p;
  p = nullptr;
}

void escribirPolinomios(int *coef, int grado) {
  for (int i = grado; i >= 0; i--) {
    if (i != 0) {
      cout << *(coef + i) << "x^" << i << " + ";
    } else {
      cout << *(coef + i) << endl;
    }
  }
}

void polinomioComparacion(Polinomio *p1, Polinomio *p2, Polinomio *&polMayor,
                          Polinomio *&polMenor, int &gradoMayor,
                          int &gradoMenor) {
  if ((*p1).grado >= (*p2).grado) {
    polMayor = p1;
    polMenor = p2;
    gradoMayor = (*p1).grado;
    gradoMenor = (*p2).grado;
  } else {
    polMayor = p2;
    polMenor = p1;
    gradoMayor = (*p2).grado;
    gradoMenor = (*p1).grado;
  }
}

void sumarPolinomios(Polinomio *p1, Polinomio *p2) {
  int gradoMayor;
  int gradoMenor;
  Polinomio *polMayor;
  Polinomio *polMenor;
  polinomioComparacion(p1, p2, polMayor, polMenor, gradoMayor, gradoMenor);
  int *coefSuma = new int[gradoMayor + 1];
  for (int i = 0; i <= gradoMayor; i++) {
    int coef = *((*polMayor).coef + gradoMayor - i);
    if (gradoMenor >= i) {
      coef += *((*polMenor).coef + gradoMenor - i);
    }
    *(coefSuma + i) = coef;
  }
  cout << "La suma de los polinomios es: ";
  escribirPolinomios(coefSuma, gradoMayor);
  delete[] coefSuma;
}

void multiplicarPolinomios(Polinomio *p1, Polinomio *p2) {
  int gradoMult = (*p1).grado + (*p2).grado;
  int gradoMayor;
  int gradoMenor;
  Polinomio *polMayor;
  Polinomio *polMenor;
  polinomioComparacion(p1, p2, polMayor, polMenor, gradoMayor, gradoMenor);
  int *coefProd = new int[gradoMult + 1]; // filas
  // inicializando el array
  for (int i = 0; i <= gradoMult; i++) {
    coefProd[i] = 0;
  }
  for (int i = 0; i <= gradoMayor; i++) {
    int gradoMayorActual = gradoMayor - i;
    for (int j = 0; j <= gradoMenor; j++) {
      int gradoActual = gradoMayorActual + gradoMenor - j;
      coefProd[gradoActual] += (*polMayor).coef[i] * (*polMenor).coef[j];
    }
  }

  cout << "El producto de los polinomios es: ";
  escribirPolinomios(coefProd, gradoMult);
  delete[] coefProd;
}

int evaluarPolinomio(Polinomio *p, int x) {
  int eval = 0;
  for (int i = 0; i <= (*p).grado; i++) {
    eval += ((*p).coef[i]) * pow(x, ((*p).grado - i));
  }
  return eval;
}

int main() {
  int n1;
  Polinomio *p1 = crearPolinomio(n1, "primer");
  leerDatos(p1);
  cout << "\n" << endl;
  Polinomio *p2 = crearPolinomio(n1, "segundo");
  leerDatos(p2);
  cout << "\n" << endl;
  escribirPol(p1, "Primer");
  escribirPol(p2, "Segundo");

  sumarPolinomios(p1, p2);
  multiplicarPolinomios(p1, p2);

  cout << "\n" << endl;

  int x;
  cout << "Ingrese el valor de x para evaluar el primer polinomio ";

  cin >> x;
  cout << "El primer polinomio evaluado en x = " << x
       << " es: " << evaluarPolinomio(p1, 2) << endl;

  liberarMemoria(p1);
  liberarMemoria(p2);
  return 0;
}

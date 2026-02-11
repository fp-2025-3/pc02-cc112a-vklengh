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

void leerDatos(Polinomio p) {
  for (int i = 0; i < p.grado + 1; i++) {
    cout << "Ingrese el coeficiente de x^" << p.grado - i << ": ";
    cin >> *(p.coef + i);
  }
}

void escribirPol(Polinomio p, string texto) {
  cout << texto << " polinomio: ";
  for (int i = 0; i < p.grado + 1; i++) {
    if (i != p.grado) {
      cout << *(p.coef + i) << "x^" << p.grado - i << " + ";
    } else {
      cout << *(p.coef + i) << endl;
    }
  }
}
void liberarMemoria(Polinomio *&p) {
  delete[] (*p).coef;
  (*p).coef = nullptr;
  delete p;
  p = nullptr;
}

//[1,2,3,4]
//[5,6,7]
//  [5,6,7]
//
void escribirSumaPolinomios(int *coefSuma, int gradoMayor) {
  cout << "La suma de los polinomios es: ";
  for (int i = gradoMayor; i >= 0; i--) {
    if (i != 0) {
      cout << *(coefSuma + i) << "x^" << i << " + ";
    } else {
      cout << *(coefSuma + i) << endl;
    }
  }
  cout << endl;
}

void sumarPolinomios(Polinomio p1, Polinomio p2) {
  int gradoMayor;
  int gradoMenor;
  Polinomio polMayor;
  Polinomio polMenor;
  if (p1.grado >= p2.grado) {
    polMayor = p1;
    polMenor = p2;
    gradoMayor = p1.grado;
    gradoMenor = p2.grado;
  } else {
    polMayor = p2;
    polMenor = p1;
    gradoMayor = p2.grado;
    gradoMenor = p1.grado;
  }
  int *coefSuma = new int[gradoMayor + 1];
  for (int i = 0; i <= gradoMayor; i++) {
    int coef = *(polMayor.coef + gradoMayor - i);
    if (gradoMenor >= i) {
      coef += *(polMenor.coef + gradoMenor - i);
    }
    *(coefSuma + i) = coef;
  }
  escribirSumaPolinomios(coefSuma, gradoMayor);
  delete[] coefSuma;
}

void multiplicarPolinomios(Polinomio p1, Polinomio p2) {
  int gradoMult = p1.grado + p2.grado;
  int gradoMayor;
  int gradoMenor;
  Polinomio polMayor;
  Polinomio polMenor;
  if (p1.grado >= p2.grado) {
    polMayor = p1;
    polMenor = p2;
    gradoMayor = p1.grado;
    gradoMenor = p2.grado;
  } else {
    polMayor = p2;
    polMenor = p1;
    gradoMayor = p2.grado;
    gradoMenor = p1.grado;
  }
  int **coefProd = new int *[gradoMayor + 1]; // filas
  for (int i = 0; i <= gradoMult; i++) {
    for (int j = 0; i <= gradoMayor; j++) {
      coefProd[i][j] = 0;
      cout << coefProd[i][j] << " ";
    }
    cout << endl;
  }

  // for (int i = 0; i <= gradoMayor; i++) {
  //   coefProd[i] = new int[gradoMult + 1]; // cols
  //   for (int j = 0; i <= gradoMenor; j++) {
  //     int gradoMultActual = gradoMult - i - j;
  //     coefProd[i][gradoMultActual] = polMayor.coef[i] * polMenor.coef[j];
  //   }
  // }

  delete[] coefProd;
}

int main() {
  int n1;
  Polinomio *p1 = crearPolinomio(n1, "primer");
  leerDatos(*p1);
  escribirPol(*p1, "Primer");
  cout << "\n" << endl;
  Polinomio *p2 = crearPolinomio(n1, "segundo");
  leerDatos(*p2);
  escribirPol(*p2, "Segundo");
  cout << "\n" << endl;

  sumarPolinomios(*p1, *p2);
  multiplicarPolinomios(*p1, *p2);

  liberarMemoria(p1);
  liberarMemoria(p2);
  return 0;
}

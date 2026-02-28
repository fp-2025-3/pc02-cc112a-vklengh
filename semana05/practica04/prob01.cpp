#include <cmath>
#include <iostream>

using namespace std;

struct Polinomio {
  int *coef;
  int grado;
};

Polinomio *crearPolinomio(int arr[], int n) {
  Polinomio *p = new Polinomio;
  (*p).coef = new int[n + 1];
  (*p).grado = n;
  for (int i = 0; i <= n; i++) {
    *((*p).coef + i) = arr[i];
  }
  return p;
}

void escribirPol(Polinomio *p) {
  for (int i = 0; i < (*p).grado + 1; i++) {
    if (i != (*p).grado) {
      if (*((*p).coef + i) != 0) {
        cout << *((*p).coef + i) << "x^" << (*p).grado - i << " + ";
      }
    } else {
      if (*((*p).coef + i) != 0) {
        cout << *((*p).coef + i) << endl;
      } else {
        cout << endl;
      }
    }
  }
}
void liberarMemoria(Polinomio *&p) {
  delete[] (*p).coef;
  (*p).coef = nullptr;
  delete p;
  p = nullptr;
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

int *sumarPolinomios(Polinomio *p1, Polinomio *p2, int &grad) {
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
  int *coefInvertido = new int[gradoMayor + 1];
  for (int i = 0; i <= gradoMayor; i++) {
    *(coefInvertido + i) = *(coefSuma + gradoMayor - i);
  }
  grad = gradoMayor;
  delete[] coefSuma;
  return coefInvertido;
}

void sumar3polinomios(Polinomio *p1, Polinomio *p2, Polinomio *p3) {
  Polinomio *temp1 = new Polinomio;
  Polinomio *temp2 = new Polinomio;
  int gradtemp1, gradtemp2;
  temp1->coef = sumarPolinomios(p1, p2, gradtemp1);
  temp1->grado = gradtemp1;

  temp2->coef = sumarPolinomios(temp1, p3, gradtemp2);
  temp2->grado = gradtemp2;
  cout << "Suma de los tres polinomios: ";
  escribirPol(temp2);
  cout << endl;
  liberarMemoria(temp1);
  liberarMemoria(temp2);
}

int *multiplicarPolinomios(Polinomio *p1, Polinomio *p2, int &grad) {
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
  int *coefInvertido = new int[gradoMult + 1];
  for (int i = 0; i <= gradoMult; i++) {
    *(coefInvertido + i) = *(coefProd + gradoMult - i);
  }
  grad = gradoMult;
  delete[] coefProd;
  return coefInvertido;
}

void mult3polinomios(Polinomio *p1, Polinomio *p2, Polinomio *p3) {
  Polinomio *temp1 = new Polinomio;
  Polinomio *temp2 = new Polinomio;
  int gradtemp1, gradtemp2;
  temp1->coef = multiplicarPolinomios(p1, p2, gradtemp1);
  temp1->grado = gradtemp1;

  temp2->coef = multiplicarPolinomios(temp1, p3, gradtemp2);
  temp2->grado = gradtemp2;
  cout << "Suma de los tres polinomios: ";
  escribirPol(temp2);
  cout << endl;
  liberarMemoria(temp1);
  liberarMemoria(temp2);
}

int evaluarPolinomio(Polinomio *p, int x) {
  int eval = 0;
  for (int i = 0; i <= (*p).grado; i++) {
    eval += ((*p).coef[i]) * pow(x, ((*p).grado - i));
  }
  return eval;
}

int *llenarArray(int &n, string texto) {
  cout << "Ingrese el grado del " << texto << " polinomio: ";
  cin >> n;
  int *arr = new int[n + 1];
  cout << "Debe ingresar los coeficientes del polinomio para los grados en "
          "orden decreciente"
       << endl;
  for (int i = 0; i <= n; i++) {
    cout << "Coeficiente de grado (" << n - i << "):";
    cin >> arr[i];
  }
  return arr;
}

void liberarMemoriaArray(int *&arr) {
  delete[] arr;
  arr = nullptr;
}

int main() {
  // int arr1[] = {1, 0, 3};
  // int n1 = 2;
  // int arr2[] = {-4, 5};
  // int n2 = 1;
  // int arr3[] = {3, 0, 1};
  // int n3 = 2;
  int n1, n2, n3;
  int *arr1 = llenarArray(n1, "primer");
  int *arr2 = llenarArray(n2, "segundo");
  int *arr3 = llenarArray(n3, "tercer");
  Polinomio *p1 = crearPolinomio(arr1, n1);
  Polinomio *p2 = crearPolinomio(arr2, n2);
  Polinomio *p3 = crearPolinomio(arr3, n3);

  cout << "\n" << endl;

  cout << "Polinomio 1: ";
  escribirPol(p1);
  cout << "Polinomio 2: ";
  escribirPol(p2);
  cout << "Polinomio 3: ";
  escribirPol(p3);

  cout << endl;
  sumar3polinomios(p1, p2, p3);
  mult3polinomios(p1, p2, p3);

  liberarMemoria(p1);
  liberarMemoria(p2);
  liberarMemoria(p3);
  liberarMemoriaArray(arr1);
  liberarMemoriaArray(arr2);
  liberarMemoriaArray(arr3);
  return 0;
}

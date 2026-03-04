#include <cmath>
#include <iostream>
using namespace std;

struct Termino {
  double coeficiente;
  int exponente;
};

struct Polinomio {
  Termino *terminos;
  int cantidadTerminos;
};

void crearPolinomio(Polinomio &p, int n) {
  p.cantidadTerminos = n;
  p.terminos = new Termino[n];
}
void leerPolinomio(Polinomio &p) {
  cout << "Ingrese los grados y exponentes: \n";
  for (int i = 0; i < p.cantidadTerminos; i++) {
    cout << "Coeficiente " << i + 1 << ": ";
    cin >> p.terminos[i].coeficiente;
    cout << "Exponente " << i + 1 << ": ";
    cin >> p.terminos[i].exponente;
  }
}
void mostrarPolinomio(const Polinomio &p) {
  for (int i = 0; i < p.cantidadTerminos; i++) {
    cout << p.terminos[i].coeficiente;
    cout << "x^";
    cout << p.terminos[i].exponente;
    if (i != p.cantidadTerminos - 1) {
      cout << " + ";
    }
  }
  cout << endl;
}
double evaluarPolinomio(const Polinomio &p, double x) {
  double res = 0.;
  for (int i = 0; i < p.cantidadTerminos; i++) {
    res += p.terminos[i].coeficiente * pow(x, p.terminos[i].exponente);
  }
  return res;
}
void derivarPolinomio(const Polinomio &p, Polinomio &der) {
  int terminosNoNulos = 0;
  for (int i = 0; i < p.cantidadTerminos; i++) {
    if (p.terminos[i].exponente != 0) {
      terminosNoNulos++;
    }
  }
  crearPolinomio(der, terminosNoNulos);
  int j = 0;
  for (int i = 0; i < p.cantidadTerminos; i++) {
    if (p.terminos[i].exponente != 0) {
      der.terminos[j].exponente = p.terminos[i].exponente - 1;
      der.terminos[j].coeficiente =
          p.terminos[i].exponente * p.terminos[i].coeficiente;
      j++;
    }
  }
}

void insertionsort(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 and arr[j] > key) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
}

void reducirPolinomio(const Polinomio &p, Polinomio &pout) {
  // [2,5,3,6,2,4,3,2]
  // Eliminar los terminos repetidos -> [2,5,3,6,4]
  // [2], [3]
  int contador = 0;
  int *gradosEncontrados = new int[p.cantidadTerminos];
  int *gradosUnicos = new int[p.cantidadTerminos];
  for (int i = 0; i < p.cantidadTerminos; i++) {
    gradosEncontrados[i] = p.terminos[i].exponente;
  }
  insertionsort(gradosEncontrados, p.cantidadTerminos);
  for (int i = 0; i < p.cantidadTerminos - 1; i++) {
    if ((gradosEncontrados[i] != gradosEncontrados[i + 1]) or
        (gradosEncontrados[i] == gradosEncontrados[i + 1] and
         i + 1 == p.cantidadTerminos - 1)) {
      gradosUnicos[contador] = gradosEncontrados[i];
      contador++;
    }
  }
  crearPolinomio(pout, contador);
  for (int i = 0; i < contador; i++) {
    pout.terminos[i].exponente = gradosUnicos[i];
    cout << pout.terminos[i].exponente << " ";
  }
  delete[] gradosEncontrados;
  delete[] gradosUnicos;
  cout << endl;
  cout << contador << endl;
  // primero se ordena la lista
}

// Suma de dos polinomios
void sumarPolinomios(const Polinomio &p1, const Polinomio &p2,
                     Polinomio &pSuma) {
  int gradoSuma = 0;
  // 1x2 + 3x + 2 , 4x + 5x3 + 3 + 1
  // Crea un polinomio con grados igual a la suma de cantidad de terminos y
  // luego los reduce reasignando a un nuevo array
  pSuma.cantidadTerminos = p1.cantidadTerminos + p2.cantidadTerminos;
  crearPolinomio(pSuma, pSuma.cantidadTerminos);
  Polinomio pTemp1;
}

void liberarPolinomio(Polinomio &p) {
  delete[] p.terminos;
  p.terminos = nullptr;
};

int main() {
  Polinomio p1, der1;
  int n1;
  cout << "Ingrese la cantidad de terminos: ";
  cin >> n1;
  crearPolinomio(p1, n1);
  leerPolinomio(p1);
  cout << "Polinomio: ";
  mostrarPolinomio(p1);
  derivarPolinomio(p1, der1);
  cout << "Derivada: ";
  mostrarPolinomio(der1);
  liberarPolinomio(p1);
  liberarPolinomio(der1);
  return 0;
}

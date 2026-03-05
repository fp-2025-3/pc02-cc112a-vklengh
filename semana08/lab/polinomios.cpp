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
  for (int i = 0; i < p.cantidadTerminos; i++) {
    if (i == p.cantidadTerminos - 1) {
      gradosUnicos[contador] = gradosEncontrados[i];
      contador++;
    } else {
      if (gradosEncontrados[i] != gradosEncontrados[i + 1]) {
        gradosUnicos[contador] = gradosEncontrados[i];
        contador++;
      }
    }
  }
  crearPolinomio(pout, contador);
  for (int i = 0; i < contador; i++) {
    pout.terminos[i].exponente = gradosUnicos[i];
    pout.terminos[i].coeficiente = 0;
    // cout << pout.terminos[i].exponente << " ";
  }
  for (int i = 0; i < p.cantidadTerminos; i++) {
    for (int j = 0; j < contador; j++) {
      if (pout.terminos[j].exponente == p.terminos[i].exponente) {
        pout.terminos[j].coeficiente += p.terminos[i].coeficiente;
      }
    }
  }
  delete[] gradosEncontrados;
  delete[] gradosUnicos;
}

void liberarPolinomio(Polinomio &p) {
  delete[] p.terminos;
  p.terminos = nullptr;
};

void asignarElementos(const Polinomio &pin1, const Polinomio &pin2,
                      Polinomio &pdest) {
  for (int i = 0; i < pdest.cantidadTerminos; i++) {
    if (i < pin1.cantidadTerminos) {
      pdest.terminos[i].coeficiente = pin1.terminos[i].coeficiente;
      pdest.terminos[i].exponente = pin1.terminos[i].exponente;
    } else {
      pdest.terminos[i].coeficiente = 0;
      pdest.terminos[i].exponente = -1; // exponente invalido
    }
  }
  int posicionFinal = pin1.cantidadTerminos;
  int inicioPol2 = 0;
  for (int i = 0; i < pin2.cantidadTerminos; i++) {
    bool exponenteEnPolinomio = false;
    for (int j = inicioPol2; j < pdest.cantidadTerminos; j++) {
      if (pdest.terminos[j].exponente == pin2.terminos[i].exponente) {
        pdest.terminos[j].coeficiente += pin2.terminos[i].coeficiente;
        exponenteEnPolinomio = true;
        inicioPol2++;
        break; // solo hay exponentes unicos
      }
    }
    if (!exponenteEnPolinomio and inicioPol2 < pin2.cantidadTerminos) {
      pdest.terminos[posicionFinal].exponente =
          pin2.terminos[inicioPol2].exponente;
      pdest.terminos[posicionFinal].coeficiente +=
          pin2.terminos[inicioPol2].coeficiente;
      inicioPol2++;
      posicionFinal++;
    }
  }
  //redimensiona el array
  if (posicionFinal != pdest.cantidadTerminos){
      Termino *termFinal = new Termino[posicionFinal];
      for (int i=0;i<posicionFinal;i++){
          termFinal[i].coeficiente = pdest.terminos[i].coeficiente;
          termFinal[i].exponente= pdest.terminos[i].exponente;
      }
      liberarPolinomio(pdest);
      pdest.cantidadTerminos = posicionFinal;
      pdest.terminos = termFinal;
  }
}

// Suma de dos polinomios
void sumarPolinomios(const Polinomio &p1, const Polinomio &p2,
                     Polinomio &pSuma) {
  // crearPolinomio(pSuma);
  // 1x2 + 3x + 2 , 4x + 5x3 + 3 + 1
  // Crea un polinomio con grados igual a la suma de cantidad de terminos y
  // luego los reduce reasignando a un nuevo array
  Polinomio pTemp1, pTemp2;
  // reduce los polinomios a exponentes unicos
  reducirPolinomio(p1, pTemp1);
  reducirPolinomio(p2, pTemp2);
  crearPolinomio(pSuma, pTemp1.cantidadTerminos + pTemp2.cantidadTerminos);
  // cout << pSuma.cantidadTerminos << endl;
  // Inicializar polinomio
  if (pTemp1.cantidadTerminos > pTemp2.cantidadTerminos) {
    asignarElementos(pTemp1, pTemp2, pSuma);
  } else {
    asignarElementos(pTemp2, pTemp1, pSuma);
  }
  liberarPolinomio(pTemp1);
  liberarPolinomio(pTemp2);
}

int main() {
  Polinomio p1, p2, der1, psuma;
  int n1, n2;
  // cout << "Ingrese la cantidad de terminos del polinomio 1: ";
  // cin >> n1;
  n1 = 4;
  crearPolinomio(p1, n1);
  p1.terminos[0].coeficiente = 1;
  p1.terminos[0].exponente = 6;
  p1.terminos[1].coeficiente = 5;
  p1.terminos[1].exponente = 6;
  p1.terminos[2].coeficiente = 7;
  p1.terminos[2].exponente = 4;
  p1.terminos[3].coeficiente = -3;
  p1.terminos[3].exponente = 2;
  // leerPolinomio(p1);
  // cout << "Ingrese la cantidad de terminos del polinomio 2: ";
  // cin >> n2;
  n2 = 4;
  crearPolinomio(p2, n2);
  p2.terminos[0].exponente = 5;
  p2.terminos[0].coeficiente = 12;
  p2.terminos[1].exponente = 1;
  p2.terminos[1].coeficiente = -5;
  p2.terminos[2].exponente = 4;
  p2.terminos[2].coeficiente = 7;
  p2.terminos[3].exponente = 3;
  p2.terminos[3].coeficiente = 3;
  // leerPolinomio(p2);
  cout << "Polinomio 1: ";
  mostrarPolinomio(p1);
  cout << "Polinomio 2: ";
  mostrarPolinomio(p2);
  derivarPolinomio(p1, der1);
  cout << "Derivada del polinomio 1: ";
  mostrarPolinomio(der1);
  sumarPolinomios(p1, p2, psuma);
  cout << "Suma de polinomios: ";
  mostrarPolinomio(psuma);
  liberarPolinomio(p1);
  liberarPolinomio(p2);
  liberarPolinomio(der1);
  liberarPolinomio(psuma);
  return 0;
}

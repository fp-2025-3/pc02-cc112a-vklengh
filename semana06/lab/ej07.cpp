#include <cmath>
#include <fstream>
#include <iostream>

using namespace std;

double arreglarNumero(double n) {
  const double limite = 0.00000001;
  if (n > 0 and n < limite) {
    return 0;
  } else if (n < 0 and n > -limite) {
    return 0;
  }
  return n;
}

void rotacion(double &xout, double &yout, double x, double y, double alpha) {
  xout = cos(alpha) * x - sin(alpha) * y;
  yout = sin(alpha) * x + cos(alpha) * y;
  xout = arreglarNumero(xout);
  yout = arreglarNumero(yout);
}

struct Poligono {
  int nv;
  double **vertices;
};

void liberarMemoria(Poligono &pol) {
  for (int i = 0; i < pol.nv; i++) {
    delete[] pol.vertices[i];
    pol.vertices[i] = nullptr;
  }
  delete[] pol.vertices;
  pol.vertices = nullptr;
}
void leerArchivo() {
  const string archivoPoligono1Dir = "inputs/poligono1.txt";
  const string archivoPoligono2Dir = "outputs/poligono2.txt";

  ifstream archivo(archivoPoligono1Dir);

  if (!archivo) {
    cout << "Error al abrir el archivo" << endl;
    return;
  }
  int nv;
  archivo >> nv;
  // crear lista dinamica de coordenadas
  double **coords = new double *[nv];
  for (int i = 0; i < nv; i++) {
    coords[i] = new double[2];
  }
  for (int i = 0; i < nv; i++) {
    double x, y;
    archivo >> x >> y;
    coords[i][0] = x;
    coords[i][1] = y;
  }
  Poligono p;
  p.vertices = coords;
  p.nv = nv;
  archivo.close();

  ofstream archivo2(archivoPoligono2Dir);

  if (!archivo2) {
    cout << "Error al abrir el archivo" << endl;
    return;
  }
  double alpha;
  cout << "Ingrese el angulo de rotacion: \n";
  cin >> alpha;
  alpha *= acos(-1.) / 180.;

  archivo2 << nv << "\n";

  for (int i = 0; i < nv; i++) {
    double x, y, xout, yout;
    x = p.vertices[i][0];
    y = p.vertices[i][1];
    rotacion(xout, yout, x, y, alpha);
    archivo2 << xout << " " << yout << "\n";
  }

  archivo2.close();
  liberarMemoria(p);
}

int main() {
  leerArchivo();
  return 0;
}

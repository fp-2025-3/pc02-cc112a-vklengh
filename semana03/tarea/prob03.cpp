#include <iostream>

using namespace std;

int longitud_palabra(const char *p);
int contar_promedios(const char **, int p);

int main() {
  const char *cad[] = {"Lesly",  "Americo", "Xingbeck", "William",    "Julio",
                       "Darwin", "Kevin",   "c++",      "Constantino"};
  int n = sizeof(cad) / sizeof(cad[0]);
  int proms = contar_promedios(cad, n);

  cout << "Cadenas mayor a la longitud promedio: " << proms << endl;

  return 0;
}

int longitud_palabra(const char *p) {
  int len = 0;
  while (*p != '\0') {
    len++;
    p++;
  }
  return len;
}

int contar_promedios(const char **p, int n) {
  double promedio = 0.0;
  int mayor_long_prom = 0;
  for (int i = 0; i < n; i++) {
    promedio += longitud_palabra(*(p + i));
  }
  promedio /= n;
  cout << "Promedio: " << promedio << endl;

  for (int i = 0; i < n; i++) {
    if (promedio < longitud_palabra(*(p + i))) {
      mayor_long_prom++;
    }
  }
  return mayor_long_prom;
}

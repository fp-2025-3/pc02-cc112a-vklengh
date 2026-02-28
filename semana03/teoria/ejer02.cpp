#include <cstring>
#include <iostream>

using namespace std;

void imprimirChars(char *p) {
  while (*p != '\0') {

    cout << *p;
    p++;
  }
  cout << endl;
}

void imprimirArregloChars(int size, char **array) {
  for (char **i = array; i < array + size; i++) {
    imprimirChars(*i);
  }
}
void ordenar_arreglo(const int size, char (*nombres)[20]) {
  char temp[20];
  for (char (*i)[20] = nombres; i < nombres + size - 1; i++) {
    for (char (*j)[20] = i + 1; j < nombres + size; j++) {
      if (strcmp(*i, *j) > 0) {
        strcpy(temp, *i);
        strcpy(*i, *j);
        strcpy(*j, temp);
      }
    }
  }
}

void ordenar_arreglo2(char **nombres, int n) {
  char temp[20];
  for (char **i = nombres; i < nombres + n - 1; i++) {
    for (char **j = i + 1; j < nombres + n; j++) {
      if (strcmp(*i, *j) > 0) {
        strcpy(temp, *i);
        strcpy(*i, *j);
        strcpy(*j, temp);
      }
    }
  }
}

int main() {

  // const char *paises[] = {"Peru", "Chile", "Brasil"};
  // char nombres[][20] = {"Lesly", "Americo", "Xingbeck", "William",
  //                       "Julio", "Darwin",  "Kevin"};
  char *nombres[] = {"Lesly", "Americo", "Xingbeck", "William",
                     "Julio", "Darwin",  "Kevin"};
  const int size = sizeof(nombres) / sizeof(nombres[0]);
  imprimirArregloChars(size, nombres);
  ordenar_arreglo2(nombres, size);
  cout << "Arreglo ordenado" << endl;
  imprimirArregloChars(size, nombres);
  return 0;
}

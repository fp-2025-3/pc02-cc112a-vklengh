#include <cstring>
#include <iostream>
#include <iomanip>

using namespace std;

int guardaDirecciones(char *texto, char **indice);
int comparar(const char *a, const char *b);
void ordenarIndice(char **indice, int n);
void imprimir(const char *texto, char **indice, int n);

int main() {
  char texto[] = "los punteros no se copian se referencian y se ordenan";
  char *indice[60];

  cout << "Entrada: " << texto << endl;
  cout << "Salida: " <<endl;
  int n = guardaDirecciones(texto, indice);
  ordenarIndice(indice, n);
  imprimir(texto, indice, n);

  return 0;
}

int guardaDirecciones(char *texto, char **indice) {
  char *temp = texto;
  int len = 0;
  int i = 0;
  bool ultima_palabra = false;
  while (!ultima_palabra) {
    if (*texto == '\0') {
      ultima_palabra = true;
    };
    if ((*texto == ' ' and len > 0) or (*texto == '\0' and len > 0)) {
      *temp = '\0';
      indice[i] = temp - len;
      // palabras[i] = temp - len;
      len = 0;
      temp = texto + 1;
      i++;
    } else {
      if (*texto != ' ') {
        *temp = *texto;
        temp++;
        len++;
      }
    }
    texto++;
  }
  return i;
}

int comparar(const char *a, const char *b) {
  if (*a > *b) {
    return 1;
  } else if (*a < *b) {
    return -1;
  } else {
    return 0;
  }
}

void my_strcpy(char **dest, char **source) {
  char *temp = *dest;
  *dest = *source;
  *source = temp;
}

void ordenarIndice(char **indice, int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (comparar(indice[i], indice[j]) > 0) {
        my_strcpy(&indice[i], &indice[j]);
      }
    }
  }
}

void imprimir(const char *texto, char **indice, int n) {
  for (char **p = indice; p < indice + n; p++) {
    cout <<left<<setw(25)<< *p <<left<<setw(5)<<""<<"(posicion " << *p - texto << ")" << endl;
    // SETW si muesta correctamente, solo que este funciona despues del primer 
    // elemento del puntero, por lo que se tiene que tiene que colocar antes
    // para que funcione correctamente y muestre una separacion uniforme
  }
}

#include <iostream>

using namespace std;
int construir_indice(char *texto, char *indice[]) {
  char *temp = texto;
  char pal[100];
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

int longitud_palabra(const char *p) {
  int len = 0;
  while (*p != '\0') {
    len++;
    p++;
  }
  return len;
}
using namespace std;
int main() {
  char texto[] = "los punteros no se copian se referencian y se ordenan";
  char *indice[100];
  construir_indice(texto, indice);
  //SIMILAR AL PROB 1
  return 0;
}

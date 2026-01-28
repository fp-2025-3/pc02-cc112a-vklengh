#include <cstring>
#include <iostream>

using namespace std;

int separar_palabras(char *texto, char *palabras[]);
int longitud_palabra(const char *p);
void clasificar(char *palabras[], int n, char *cortas[], int &nc,
                char *largas[], int &nl);
int comparar_palabras(const char *a, const char *b);
void ordenar(char *v[], int n);
void imprimir_grupo(const char *titulo, char *v[], int n);

int main() {
  char texto[300] = "Programar    en C++ requiere logica C++ exige disciplina";
  char *palabras[60];
  char *cortas[60];
  char *largas[60];

  int n = separar_palabras(texto, palabras);
  int nc = 0, nl = 0;

  cout << "Cantidad de palabras: " << n << endl;
  cout << longitud_palabra(palabras[0]) << endl;
  cout << longitud_palabra(palabras[1]) << endl;
  clasificar(palabras, n, cortas, nc, largas, nl);
  cout << "Cantidad de palabras largas: " << nl << endl;
  cout << "Cantidad de palabras cortas: " << nc << endl;
  cout << largas[0] << endl;
  cout << largas[4] << endl;
  ordenar(largas, nl);
  cout << largas[0] << endl;

  return 0;
}

int separar_palabras_strtok(char *texto, char *palabras[]) {
  char *token = strtok(texto, " ");
  while (token != nullptr) {
    cout << token << endl;
    token = strtok(nullptr, " ");
  }
}

int separar_palabras(char *texto, char *palabras[]) {
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
      palabras[i] = temp - len;
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
void clasificar(char *palabras[], int n, char *cortas[], int &nc,
                char *largas[], int &nl) {
  for (int i = 0; i < n; i++) {
    int len = longitud_palabra(palabras[i]);
    if (len <= 3) {
      cortas[nc] = palabras[i];
      nc++;
    } else {
      largas[nl] = palabras[i];
      nl++;
    }
  }
}
int comparar_palabras(const char *a, const char *b) {
  if (longitud_palabra(a) > longitud_palabra(b)) {
    return 1;
  } else if (longitud_palabra(a) < longitud_palabra(b)) {
    return -1;
  } else {
    return 0;
  }
}
void ordenar(char *v[], int n) {

  char temp[100];
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (comparar_palabras(v[i], v[j]) > 0) {
        strcpy(temp, v[i]);
        strcpy(v[i], v[j]);
        strcpy(v[j], temp);
      }
    }
  }
}

void imprimir_grupo(const char *titulo, char *v[], int n);

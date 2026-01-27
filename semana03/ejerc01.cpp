#include <iostream>
using namespace std;

void tablaASCII() {
  for (int i = 0; i < 128; i++) {
    cout << i << " le corresponde: " << (char)i << endl;
  }
}

void imprimirChars(const char *p) {
  while (*p != '\0') {

    cout << *p;
    p++;
  }
  cout << endl;
}

std::size_t my_strlen(const char *str) {
  std::size_t counter = 0;
  while (*str != '\0') {
    counter++;
    str++;
  }
  return counter;
}

char *my_strcpy(char *dest, const char *source) {
  char *inicio = dest;
  while (*source != '\0') {
    *dest = *source;
    dest++;
    source++;
  }
  *dest = '\0';
  return inicio;
}

int my_strcmp(const char *a, const char *b) {
  while (*a != '\0' and *b != '\0') {
    if (*a != *b) {
      if (*a < *b) {
        return -1;
      } else {
        return 1;
      }
    }
    a++;
    b++;
  }
  return 0;
}

char *my_strcat(char *destination, const char *source) {
  char *inicio = destination;
  ;
  while (*destination != '\0') {
    destination++;
  }
  while (*source != '\0') {
    *destination = *source;
    destination++;
    source++;
  }
  *destination = '\0';
  return inicio;
}

int main() {
  char c1 = 'A';
  char c2 = 'a';
  char c3 = '0';

  cout << (int)c1 << endl;
  cout << (int)c2 << endl;
  cout << (int)c3 << endl;
  cout << c1 << endl;
  // ARITMETICA DE CARACTERES
  c1 = c1 + 1;
  cout << c1 << endl;
  // DE MAY A MIN
  c1 = c1 + 32;
  cout << c1 << endl;
  imprimirChars("Hola mundo");

  // tablaASCII();

  char nombre[10];
  int edad;
  // cout << "Ingrese su edad: ";
  // cin >> edad;
  // // Borrar el buffer
  // cin.ignore();
  // cout << endl;
  // cout << "Ingrese su nombre: ";
  // cin.getline(nombre, 10);
  char cad[100] = "Fundamentos de ";
  cout << my_strlen(cad) << endl;
  char ncad[100] = "programacion";
  cout << "Origen: ";
  imprimirChars(ncad);
  cout << endl;
  cout << "Destino: ";
  imprimirChars(cad);
  cout << endl;
  my_strcat(cad, ncad);
  imprimirChars(cad);
  cout << "Son iguales: " << my_strcmp(cad, ncad) << endl;
  my_strcpy(ncad, cad);
  imprimirChars(ncad);
  cout << "Son iguales: " << my_strcmp(cad, ncad) << endl;
}

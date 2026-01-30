#include <iostream>

using namespace std;

int convertir_multiple_digito(int primero, int segundo) {
  return primero * 10 + segundo;
}

bool hallar_suma(int *digitos, int valor, int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (*(digitos + i) + *(digitos + j) == valor) {
        return true;
      }
    }
  }
  return false;
}

int obtener_numero(char *num, int n, int *out) {
  int cant_digitos = 0;
  int *digitos;
  bool finalizado_digitos = false;
  int temp_numero = 0;
  int cant_numeros = 0;
  for (int i = 0; i < n - 1; i++) {
    char *p = num + i;
    int numero;
    if (!(*p == ',' or *p == ' ')) {
      if (*(p + 1) == ',' or *(p + 1) == ' ' or
          *(p + 1) == '\0') { // condicion finalizacion para numero
        finalizado_digitos = true;
        cant_digitos++;
      } else if (*(p + 1) >= 48 and *(p + 1) <= 57) {
        cant_digitos++;
      }
      temp_numero = int(*p) - 48;
      if (cant_digitos > 1) {
        numero = int(*p) - 48;
        temp_numero = convertir_multiple_digito(temp_numero, numero);
      }
    }
    if (finalizado_digitos) {
      *out = temp_numero;
      out++;
      digitos = &temp_numero;
      digitos++;
      cant_numeros++;
      cant_digitos = 0;
      finalizado_digitos = false;
      temp_numero = 0;
    }
  }
  return cant_numeros;
}

void imprimir(int *digitos, int valor, int n) {
  bool resp = hallar_suma(digitos, valor, n);

  if (resp) {
    cout << "SI existen 2 números con suma " << valor << endl;
  } else {
    cout << "NO existen 2 números con suma " << valor << endl;
  }
}

int main() {
  char num[] = "1, 2, 4, 7, 11";
  int n = sizeof(num) / sizeof(num[0]);
  int digitos[100];
  // ASCII 0=48
  // ASCII 9=57

  int cant_numeros = obtener_numero(num, n, digitos);
  cout << "texto: " << num << endl;
  imprimir(digitos, 15, cant_numeros);
  imprimir(digitos, 10, cant_numeros);
  return 0;
}

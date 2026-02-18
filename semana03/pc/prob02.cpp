#include <iostream>

using namespace std;

bool detectar_vocal(const char *texto) {
  if (*(texto) == 'a' or *(texto) == 'A' or *(texto) == 'e' or
      *(texto) == 'E' or *(texto) == 'i' or *(texto) == 'I' or
      *(texto) == 'o' or *(texto) == 'O' or *(texto) == 'u' or
      *(texto) == 'U') {
    return true;
  }
  return false;
}
int contar_vocales(const char *texto) {
  int contador = 0;
  if (detectar_vocal(texto)) {
    contador++;
  }
  while (*texto != '\0') {
    if (*texto == ' ') {
      if (detectar_vocal(texto + 1)) {
        contador++;
      }
    }
    texto++;
  }
  return contador;
}

int main() {
  const char *texto = "Este es un ejemplo en C++ END";
  int num = contar_vocales(texto);
  cout << "texto: " << texto << endl;
  cout << "Número de palabras que comienzan con vocal: " << num << endl;
  return 0;
}

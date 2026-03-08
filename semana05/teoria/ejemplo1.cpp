// ESTRUCTURAS

#include <iostream>

using namespace std;

struct Fecha {
  int dia;
  int mes;
  int anio;
};

struct Estudiante {
  int codigo;
  Fecha nacimiento;
  float promedio;
  char sexo;
};

// Acceso mediante ptr a los miembros de la estructura
// PRIMERA FORMA (usandor operador flecha ->)
// cout << ptr -> codigo<<endl;
// ptr -> codigo " Equivalente " (*ptr).codigo

// Paso de estructura como parametro de una funcion
//
// No es eficiente porque se pasa un struct y se copia el contenido
void mostrar(Estudiante e) { cout << "Codigo: " << e.codigo << endl; }
// Paso por referencia mas eficiente porque no copia el struct
void aumentarPromedio(Estudiante &e) { e.promedio += 1; }

// void calcularPromedio(Estudiante e[], int n) { e.promedio += 1; }

int main() {
  Estudiante e1;
  Estudiante *ptr = &e1; //puntero a estructura
  e1.codigo = 1234;
  e1.nacimiento.dia = 2;
  e1.nacimiento.mes = 3;
  e1.nacimiento.anio = 2;
  e1.promedio = 12.3;
  e1.sexo = 'F';

  return 0;
}

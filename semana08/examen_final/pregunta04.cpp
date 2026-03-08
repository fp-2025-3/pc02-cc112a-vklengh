#include "sensor/src/sensor.h"
#include "sensor/src/sensorCircular.h"
#include "sensor/src/sensorRectangular.h"
#include "sensor/src/sistemaSensores.h"
#include <iostream>

using namespace std;

// c++ sensor/src/sensor.cpp sensor/src/sensorCircular.cpp
// sensor/src/sensorRectangular.cpp sensor/src/sistemaSensores.cpp
// pregunta04.cpp -o build/main && valgrind ./build/main

void menu() {
  bool continuar = true;
  SistemaSensores sistema;
  while (continuar) {
    cout << "======= MENU ========\n";
    cout << "1) Agregar sensor circular\n";
    cout << "2) Agregar sensor rectangular\n";
    cout << "3) Mostrar todos los sensores\n";
    cout << "4) Calcular el area total de cobertura\n";
    cout << "5) Cuantos sensores detectan un punto\n";
    cout << "6) Mostrar el sensor con mayor area de cobertura\n";
    cout << "7) Para salir del programa\n";
    int opciones;
    cout << "Ingrese la opcion: ";
    cin >> opciones;
    switch (opciones) {
    case 1: {
      string id;
      double x;
      double y;
      double radio;
      cout << "Ingrese los datos del sensor circular: \n";
      cout << "ID: ";
      cin >> id;
      cout << "Posicion X: ";
      cin >> x;
      cout << "Posicion Y: ";
      cin >> y;
      cout << "Radio: ";
      cin >> radio;
      Sensor *s = new SensorCircular{id, x, y, radio};
      sistema.agregarSensor(s);
      delete s;
      break;
    }
    case 2: {
      string id;
      double x;
      double y;
      double alto;
      double ancho;
      cout << "Ingrese los datos del sensor rectangular: \n";
      cout << "ID: ";
      cin >> id;
      cout << "Posicion X: ";
      cin >> x;
      cout << "Posicion Y: ";
      cin >> y;
      cout << "Ancho: ";
      cin >> ancho;
      cout << "Alto: ";
      cin >> alto;
      Sensor *s = new SensorRectangular{id, x, y, ancho, alto};
      sistema.agregarSensor(s);
      delete s;
      break;
    }
    case 3: {
      bool error = sistema.detectarError();
      if (error) {
        break;
      }
      cout << "Mostrando todos los sensores: \n";
      sistema.mostrarSensores();
      break;
    }
    case 4: {
      bool error = sistema.detectarError();
      if (error) {
        break;
      }
      double area = sistema.areaTotalCobertura();

      cout << "Area total de cobertura: " << area << endl;
      break;
    }
    case 5: {
      bool error = sistema.detectarError();
      if (error) {
        break;
      }
      double x, y;
      cout << "Ingrese las coordenadas del punto que quiere detectar:\n";
      cout << "X: ";
      cin >> x;
      cout << "Y: ";
      cin >> y;
      int detectan = sistema.sensoresQueDetectan(x, y);
      cout << "Cantidad de sensores que detectan el punto X: " << x
           << " Y: " << y << " es: " << detectan << endl;
      break;
    }
    case 6: {
      bool error = sistema.detectarError();
      if (error) {
        break;
      }
      cout << "El sensor con mayor cobertura es: " << endl;
      Sensor *s = sistema.sensorMayorCobertura();
      s->imprimir();
      break;
    }
    case 7: {
      continuar = false;
      cout << "Terminando el programa.\n";
      break;
    }
    default: {
      cout << "Opcion invalida, intente nuevamente.\n";
      break;
    }
    }
  }
}

int main() {
  // Sensor *s[] = {new SensorCircular{"sc1", 10, 10, 2},
  //                new SensorRectangular{"sr1", 15, 15, 6, 3}};
  // SistemaSensores sistema(s, 2, 2);
  // sistema.mostrarCapacidad();
  // Sensor *s1 = new SensorCircular{"sc1", 10, 10, 2};
  // Sensor *s2 = new SensorRectangular{"sr1", 15, 15, 6, 3};
  // sistema.agregarSensor(s1);
  // delete s1;
  // sistema.agregarSensor(s2);
  // delete s2;
  // sistema.mostrarCapacidad();
  // cout << sistema.getInfo(10, 10) << endl;
  // Sensor *s3 = sistema.sensorMayorCobertura();
  //
  // cout << "El sensor con mayor cobertura es: " << endl;
  // s3->imprimir();

  menu();
  return 0;
}

#include "sensor/src/sensor.h"
#include "sensor/src/sensorCircular.h"
#include "sensor/src/sensorRectangular.h"
#include <iostream>

// c++ sensor/src/sensor.cpp sensor/src/sensorCircular.cpp sensor/src/sensorRectangular.cpp pregunta04.cpp -o build/main


using namespace std;

int main() {
  // algo
  double *pos = new double[2];
  pos[0] = 1;
  pos[1] = 4;
  SensorCircular sc = {"sr1", 0, 0, pos, 2};
  SensorRectangular sr = {"sr1", 0, 0, pos, 2, 3};
  Sensor *s[] = {new SensorCircular{"sc1", 0, 0, pos, 2},
                 new SensorRectangular{"sr1", 0, 0, pos, 6, 3}};
  for (int i = 0; i < 2; i++) {
    s[i]->imprimir();
  }
  delete[] pos;
  return 0;
}

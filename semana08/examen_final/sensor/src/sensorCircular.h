#ifndef SENSOR_CIRCULAR_H
#define SENSOR_CIRCULAR_H
#include "sensor.h"

#include <string>

class SensorCircular : public Sensor {
private:
    double radio;

public:
  // Constructores
  SensorCircular();
  // constructor de parametros
  SensorCircular(std::string i,double x, double y, double *pos, double rad);
  // constructor de copia profunda (deep copy) vs shallow copy (el sistema lo
  // crea)
  SensorCircular(const SensorCircular &otro);
  // Redefinir el operador de asignacion
  // puntero oculto this
  SensorCircular &operator=(const SensorCircular &otro);
  virtual ~SensorCircular();
  // Metodos virtuales puros
  virtual SensorCircular *copiar();
  virtual double areaCobertura();
  virtual bool detecta(double x, double y);
  virtual void imprimir();
};

#endif

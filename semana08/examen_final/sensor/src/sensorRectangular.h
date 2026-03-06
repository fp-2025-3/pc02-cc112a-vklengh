#ifndef SENSOR_RECTANGULAR_H
#define SENSOR_RECTANGULAR_H
#include "sensor.h"

#include <string>

class SensorRectangular : public Sensor {
private:
    double ancho;
    double alto;

public:
  // Constructores
  SensorRectangular();
  // constructor de parametros
  SensorRectangular(std::string,double x, double y, double *pos, double rad);
  // constructor de copia profunda (deep copy) vs shallow copy (el sistema lo
  // crea)
  SensorRectangular(const SensorRectangular &otro);
  // Redefinir el operador de asignacion
  // puntero oculto this
  SensorRectangular &operator=(const SensorRectangular &otro);
  virtual ~SensorRectangular();
  // Metodos virtuales puros
  virtual SensorRectangular *copiar();
  virtual double areaCobertura();
  virtual bool detecta(double x, double y);
  virtual void imprimir();
};

#endif

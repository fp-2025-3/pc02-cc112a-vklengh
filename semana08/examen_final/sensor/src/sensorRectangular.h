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
  SensorRectangular(std::string i,double x, double y, double *pos, double anch, double alt);
  // constructor de copia profunda (deep copy) vs shallow copy (el sistema lo
  // crea)
  SensorRectangular(const SensorRectangular &otro);
  // Redefinir el operador de asignacion
  // puntero oculto this
  SensorRectangular &operator=(const SensorRectangular &otro);
  virtual ~SensorRectangular();
  // Metodos virtuales puros
  virtual Sensor *copiar() const override ;
  virtual double areaCobertura() const override;
  virtual bool detecta(double x, double y) const override;
  virtual void imprimir() const override;
};

#endif

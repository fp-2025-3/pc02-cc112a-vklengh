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
  SensorRectangular(std::string i, double x, double y, double anch, double alt);
  // constructor de copia profunda (deep copy) vs shallow copy (el sistema lo
  // crea)
  SensorRectangular(const SensorRectangular &otro);
  // Redefinir el operador de asignacion
  // puntero oculto this
  SensorRectangular &operator=(const SensorRectangular &otro);
  ~SensorRectangular();
  // Metodos virtuales puros
  Sensor *copiar() const override;
  double areaCobertura() const override;
  bool detecta(double x, double y) const override;
  void imprimir() const override;
  SalidaInfo getInfo(double x, double y) const override;
};

#endif

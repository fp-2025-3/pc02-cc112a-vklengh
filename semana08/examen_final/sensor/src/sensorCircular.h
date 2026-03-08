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
  SensorCircular(std::string i, double x, double y, double rad);
  // constructor de copia profunda (deep copy) vs shallow copy (el sistema lo
  // crea)
  SensorCircular(const SensorCircular &otro);
  // Redefinir el operador de asignacion
  // puntero oculto this
  SensorCircular &operator=(const SensorCircular &otro);
  ~SensorCircular();
  // Metodos virtuales puros
  Sensor *copiar() const override;
  double areaCobertura() const override;
  bool detecta(double x, double y) const override;
  void imprimir() const override;
  SalidaInfo getInfo(double x, double y) const override;
};

#endif

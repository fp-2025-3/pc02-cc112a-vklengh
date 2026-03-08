#ifndef SENSOR_H
#define SENSOR_H
#include <string>

class Sensor {
protected:
  std::string id;
  double *posicion;

public:
  // Constructores
  Sensor();
  // constructor de parametros
  Sensor(std::string i,double x, double y, double *pos);
  // constructor de copia profunda (deep copy) vs shallow copy (el sistema lo
  // crea)
  Sensor(const Sensor &otro);
  // Redefinir el operador de asignacion
  // puntero oculto this
  Sensor &operator=(const Sensor &otro);
  virtual ~Sensor();
  // Metodos virtuales puros
  virtual Sensor *copiar() const = 0;
  virtual double areaCobertura() const = 0;
  virtual bool detecta(double x, double y) const = 0;
  virtual void imprimir() const = 0;
};

#endif

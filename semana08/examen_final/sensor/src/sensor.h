#ifndef SENSOR_H
#define SENSOR_H
#include <string>

struct SalidaInfo{
    std::string info;
    double area;
    bool detecta;
};

class Sensor {
protected:
  std::string id;
  double *posicion;

public:
  // Constructores
  Sensor();
  // constructor de parametros
  Sensor(std::string i,double x, double y);
  // constructor de copia profunda (deep copy) vs shallow copy (el sistema lo
  // crea)
  Sensor(const Sensor &otro);
  // Redefinir el operador de asignacion
  // puntero oculto this
  Sensor &operator=(const Sensor &otro);
  virtual ~Sensor() = default;
  // Metodos virtuales puros
  virtual Sensor *copiar() const = 0;
  virtual double areaCobertura() const = 0;
  virtual bool detecta(double x, double y) const = 0;
  virtual void imprimir() const = 0;
  virtual SalidaInfo getInfo(double x, double y) const = 0;
};

#endif

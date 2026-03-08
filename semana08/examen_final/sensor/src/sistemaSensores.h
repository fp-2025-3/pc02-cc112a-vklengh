#ifndef SISTEMASENSORES_H
#define SISTEMASENSORES_H
#include "sensor.h"
#include <string>

class SistemaSensores {
private:
  Sensor **sensores;
  int cantidad;
  int capacidad;

public:
  SistemaSensores();
  SistemaSensores(Sensor **sens, int cant, int cap);
  SistemaSensores(SistemaSensores &otro);
  SistemaSensores &operator=(SistemaSensores &otro);
  virtual ~SistemaSensores();
  virtual void aumentarCapacidad(int cap);
  virtual void agregarSensor(Sensor *s);
  virtual void mostrarSensores() const;
  virtual void mostrarCapacidad() const;
  virtual double areaTotalCobertura() const;
  virtual int sensoresQueDetectan(double x, double y) const;
  virtual std::string getInfo(double x, double y) const;
  virtual void guardarArchivo(std::string &direccion);
  virtual Sensor* sensorMayorCobertura() const;
  bool detectarError() const;
};

#endif

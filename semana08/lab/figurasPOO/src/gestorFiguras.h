#ifndef GESTORFIGURA_H
#define GESTORFIGURA_H
#include "figura.h"
#include <ctime>
#include <string>

class GestorFiguras {
private:
  Figura **figuras;
  int cantidad;
  int capacidad;

public:
  GestorFiguras();
  GestorFiguras(Figura **fig, int cant, int cap);
  GestorFiguras(GestorFiguras &otro);
  GestorFiguras &operator=(GestorFiguras &otro);
  virtual ~GestorFiguras();
  virtual void aumentarCapacidad(int cap);
  virtual void agregarFiguras(Figura *f);
  virtual void mostrarFiguras();
  virtual void mostrarCapacidad();
  virtual double area();
  virtual double perimetro();
  virtual std::string getInfo();
  virtual void guardarArchivo(std::string &direccion);
};

#endif

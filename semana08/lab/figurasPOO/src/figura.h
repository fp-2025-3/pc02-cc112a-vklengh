#ifndef FIGURA_H
#define FIGURA_H
#include <string>

struct SalidaInfo{
    std::string info;
    double area;
    double perimetro;
};

class Figura {
protected:
  std::string nombre;
  double *colorRGB;

public:
  // Constructores
  Figura();
  // constructor de parametros
  Figura(std::string nom, double r, double g, double b);
  // constructor de copia profunda (deep copy) vs shallow copy (el sistema lo
  // crea)
  Figura(const Figura &otro);
  // Redefinir el operador de asignacion
  // puntero oculto this
  Figura &operator=(const Figura &otro);
  virtual ~Figura();
  // Metodos virtuales puros
  virtual Figura *copiar() const = 0;
  virtual double area() const = 0;
  virtual double perimetro() const = 0;
  virtual void imprimir() const = 0;
  virtual std::string getNombre() const = 0;
  virtual double* getColor() const = 0;
  virtual SalidaInfo getInfo() const = 0;
};

#endif

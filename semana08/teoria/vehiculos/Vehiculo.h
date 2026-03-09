#ifndef VEHICULO_H
#define VEHICULO_H
#include <fstream>
#include <string>

class Vehiculo {
protected:
  std::string placa;
  std::string marca;
  int anio;
  double precio;

public:
  Vehiculo();
  Vehiculo(std::string nPlaca, std::string marcaVehiculo, int anioVehiculo,
           double precioVehiculo);
  virtual void mostrarInfo() const;
  virtual void registrarVehiculo();
  virtual ~Vehiculo();
  // Clase abstracta
  virtual double calcularPrecioFinal() const = 0;
  virtual void guardar(std::ofstream &out) const = 0;
  virtual void cargar(std::ifstream &in) = 0;
};

#endif

class Automovil : public Vehiculo {
private:
  int numeroPuertas;

public:
  Automovil();
  Automovil(std::string p, std::string m, int a, double pr, int nP);
  virtual void mostrarInfo() const override;
  virtual void registrarVehiculo() override;
  virtual ~Automovil();
  virtual double calcularPrecioFinal() const override;
  virtual void guardar(std::ofstream &out) const override;
  virtual void cargar(std::ifstream &in) override;
};

class Camion : public Vehiculo {
private:
  double capacidadCarga;

public:
  Camion();
  Camion(std::string p, std::string m, int a, double pr, double cC);
  virtual void mostrarInfo() const override;
  virtual void registrarVehiculo() override;
  virtual ~Camion();
  virtual double calcularPrecioFinal() const override;
  virtual void guardar(std::ofstream &out) const override;
  virtual void cargar(std::ifstream &in) override;
};

class Motocicleta : public Vehiculo {
private:
  double potencia;

public:
  Motocicleta();
  Motocicleta(std::string p, std::string m, int a, double pr, double pot);
  virtual void mostrarInfo() const override;
  virtual void registrarVehiculo() override;
  virtual ~Motocicleta();
  virtual double calcularPrecioFinal() const override;
  virtual void guardar(std::ofstream &out) const override;
  virtual void cargar(std::ifstream &in) override;
};

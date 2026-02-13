#include <cstring>
#include <iostream>
using namespace std;

struct Item {
  char *descripcion;
  int cantidad;
  double PrecioUnitario;
};

struct Pedido {
  int numeroPedido;
  char *nombreCliente;
  Item *items;
  int cantidadItems;
};

Item crearItem(const char *descripcion, int cantidad, double precio) {
  Item item;
  item.descripcion = new char;
  strcpy(item.descripcion, descripcion);
  item.PrecioUnitario = precio;
  item.cantidad = cantidad;
  return item;
}

Pedido *crearPedido(int numero, const char *cliente, int cantidadItems) {
  Pedido *pedido = new Pedido;
  pedido->nombreCliente = new char;
  Item *item = new Item;
  char *desc;
  int cant;
  double precio;
  strcpy(pedido->nombreCliente, cliente);
  pedido->numeroPedido = numero;
  pedido->cantidadItems = cantidadItems;
  desc = "Laptop\0";
  cant = 1;
  precio = 100;
  *(*(pedido + 0)).items = crearItem(desc, cant, precio);
  desc = "Mouse\0";
  cant = 2;
  precio = 200;
  *(*(pedido + 1)).items = crearItem(desc, cant, precio);
  desc = "Teclado\0";
  cant = 3;
  precio = 300;
  *(*(pedido + 2)).items = crearItem(desc, cant, precio);
  return pedido;
}

Pedido *crearPedidoManual(int numero, const char *cliente, int cantidadItems) {
  Pedido *pedido = new Pedido;
  pedido->nombreCliente = new char;
  Item *item = new Item;
  for (int i = 0; i < cantidadItems; i++) {
    char *desc;
    int cant;
    double precio;
    cout << "Ingresar descripcion item: ";
    cin >> desc;
    cout << "Ingresar cantidad item: ";
    cin >> cant;
    cout << "Ingresar precio de item: ";
    cin >> precio;
    *(*(pedido + i)).items = crearItem(desc, cant, precio);
  }
  return pedido;
}

double calcularTotal(const Pedido *p) {
  double suma = 0.;
  for (int i = 0; i < p->cantidadItems; i++) {
    suma += ((*(p + i)).items->cantidad) * ((*(p + i)).items->PrecioUnitario);
  }
  return suma;
}

Item *itemMasCaro(Pedido *p) {
  Item *masCaro = p->items;
  for (int i = 0; i < p->cantidadItems; i++) {
    if ((*(p + i)).items->PrecioUnitario > masCaro->PrecioUnitario) {
      masCaro = (p + i)->items;
    }
  }
  return masCaro;
}

void liberarPedido(Pedido *&p) {
  for (int i = 0; i < p->cantidadItems; i++) {
    delete[] (p + i)->items;
    (p + i)->items = nullptr;
  }
  delete[] p;
  p = nullptr;
}

int main() {
  int numero = 101;
  char *cliente = "Carlos Perez";
  int cantItems = 3;
  Pedido *p = crearPedido(numero, cliente, cantItems);
  return 0;
}

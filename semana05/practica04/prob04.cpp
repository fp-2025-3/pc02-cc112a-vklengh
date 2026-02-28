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
  // Item *item = new Item;
  Item item;
  item.PrecioUnitario = precio;
  item.cantidad = cantidad;
  item.descripcion = new char[strlen(descripcion) + 1];
  strcpy(item.descripcion, descripcion);
  return item;
}

Pedido *crearPedido(int numero, const char *cliente, int cantidadItems) {
  Pedido *pedido = new Pedido;
  pedido->nombreCliente = new char[strlen(cliente) + 1];
  strcpy(pedido->nombreCliente, cliente);
  pedido->numeroPedido = numero;
  pedido->cantidadItems = cantidadItems;

  pedido->items = new Item[cantidadItems];
  pedido->items[0] = crearItem("Laptop", 1, 100);
  pedido->items[1] = crearItem("Mouse", 2, 200);
  pedido->items[2] = crearItem("Teclado", 3, 300);
  return pedido;
}

Pedido *crearPedidoManual(int numero, const char *cliente, int cantidadItems) {
  Pedido *pedido = new Pedido;
  pedido->nombreCliente = new char[strlen(cliente) + 1];
  strcpy(pedido->nombreCliente, cliente);
  pedido->numeroPedido = numero;
  pedido->cantidadItems = cantidadItems;

  pedido->items = new Item[cantidadItems];
  for (int i = 0; i < cantidadItems; i++) {
    char *descripcion;
    string temp;
    int cantidad;
    double precio;
    cout << "Ingrese datos del item: " << endl;
    cout << "Descripcion: ";
    getline(cin, temp);
    descripcion = &temp[0];
    cout << "Cantidad: ";
    cin >> cantidad;
    cin.ignore();
    cout << "Precio: ";
    cin >> precio;
    cin.ignore();
    pedido->items[i] = crearItem(descripcion, cantidad, precio);
  }
  return pedido;
}

double calcularTotal(const Pedido *p) {
  double suma = 0.;
  for (int i = 0; i < p->cantidadItems; i++) {
    suma += (p->items[i].cantidad) * (p->items[i].PrecioUnitario);
  }
  return suma;
}

Item *itemMasCaro(Pedido *p) {
  Item *masCaro = p->items;
  for (int i = 1; i < p->cantidadItems; i++) {
    if (p->items[i].PrecioUnitario > masCaro->PrecioUnitario) {
      masCaro = &p->items[i]; // consultar este error, si es puntero por
                              // copia corrompe la memoria
    }
  }
  return masCaro;
}

void liberarPedido(Pedido *&p) {
  for (int i = 0; i < p->cantidadItems; i++) {
    delete[] p->items[i].descripcion;
    p->items[i].descripcion = nullptr;
  }
  delete[] p->items;
  delete[] p->nombreCliente;
  p->nombreCliente = nullptr;
  p->items = nullptr;
  delete p;
  p = nullptr;
}

void imprimir(Pedido *pedido) {
  cout << "Pedido: N°: " << pedido->numeroPedido << endl;
  cout << "Cliente: " << pedido->nombreCliente << "\n" << endl;
  cout << "Items:" << endl;
  for (int i = 0; i < pedido->cantidadItems; i++) {
    cout << "- " << pedido->items[i].descripcion
         << " | Cant: " << pedido->items[i].cantidad
         << " | Precio: " << pedido->items[i].PrecioUnitario << endl;
  }
  cout << endl;
  double total = calcularTotal(pedido);
  Item *masCaro = itemMasCaro(pedido);
  cout << "Total: " << total << "\n" << endl;
  cout << "Item mas caro: " << masCaro->descripcion
       << " | Precio: " << masCaro->PrecioUnitario << endl;
}

int main() {
  // Pedido *p = crearPedido(101, "Carlos Perez", 3);
  int nItems;
  char *nombre;
  string temp;
  int codigo;
  cout << "Ingrese el codigo del pedido: "<<endl;
  cin >> codigo;
  cin.ignore();
  cout << "Ingrese el nombre del cliente: "<<endl;
  getline(cin, temp);
  nombre = &temp[0];
  cout << "Ingrese el numero de items: "<<endl;
  cin>>nItems;
  cin.ignore();

  Pedido *p = crearPedidoManual(codigo, nombre, nItems);
  imprimir(p);
  liberarPedido(p);
  return 0;
}

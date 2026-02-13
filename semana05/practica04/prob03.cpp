#include <cstring>
#include <iostream>

using namespace std;

struct Producto {
  int codigo;
  char *nombre;
  double precio;
  int stock;
};

Producto crearProducto(int codigo, const char *nombre, double precio,
                       int stock) {
  Producto prod;
  prod.codigo = codigo;
  char *tempNombre = new char;
  strcpy(tempNombre, nombre);
  prod.nombre = tempNombre;
  prod.precio = precio;
  prod.stock = stock;
  return prod;
}

Producto *crearInventario(int n) {
  Producto *inventario = new Producto[n];
  int codigo;
  char *nombre;
  double precio;
  int stock;
  codigo = 100;
  nombre = "Teclado";
  precio = 10.5;
  stock = 5;
  *(inventario) = crearProducto(codigo, nombre, precio, stock);
  codigo = 101;
  nombre = "Mouse";
  precio = 21;
  stock = 10;
  *(inventario + 1) = crearProducto(codigo, nombre, precio, stock);
  codigo = 102;
  nombre = "Monitor";
  precio = 31.5;
  stock = 15;
  *(inventario + 2) = crearProducto(codigo, nombre, precio, stock);
  codigo = 102;
  nombre = "Laptop";
  precio = 42;
  stock = 20;
  *(inventario + 3) = crearProducto(codigo, nombre, precio, stock);
  codigo = 104;
  nombre = "Impresora";
  precio = 52.5;
  stock = 25;
  *(inventario + 4) = crearProducto(codigo, nombre, precio, stock);
  return inventario;
}

// Producto *crearInventarioManual(int n) {
//   Producto *inventario = new Producto[n];
//   for (int i = 0; i < n; i++) {
//     int codigo;
//     char *nombre;
//     double precio;
//     int stock;
//     cout << "Ingrese datos del producto: " << endl;
//     cout << "Codigo: ";
//     cin >> codigo;
//     cin.ignore();
//     cout << "Nombre: ";
//     cin >> nombre;
//     cout << "Precio: ";
//     cin >> precio;
//     cout << "Stock: ";
//     cin >> stock;
//     *(inventario + i) = crearProducto(codigo, nombre, precio, stock);
//   }
//   return inventario;
// }

void mostrarInventario(Producto *inventario, int n) {
  for (int i = 0; i < n; i++) {
    cout << "Codigo: " << (*(inventario + i)).codigo << " | ";
    cout << "Nombre: " << (*(inventario + i)).nombre << " | ";
    cout << "Precio: " << (*(inventario + i)).precio << " | ";
    cout << "Stock: " << (*(inventario + i)).stock << endl;
  }
}

Producto *buscarProducto(Producto *inventario, int n, int codigoBuscado) {
  cout << "Buscando producto con codigo " << codigoBuscado << "..." << endl;
  for (int i = 0; i < n; i++) {
    if ((*(inventario + i)).codigo == codigoBuscado) {
      cout << "Producto encontrado: " << (*(inventario + i)).nombre << " | "
           << "Precio: " << (*(inventario + i)).precio << endl;
      return inventario + i;
    }
  }
  cout << "Producto no encontrado." << endl;
  return nullptr;
}

void liberarInventario(Producto *&inventario, int n) {
  for (int i = 0; i < n; i++) {
    delete inventario[i].nombre;
    inventario[i].nombre = nullptr;
  }
  delete[] inventario;
  inventario = nullptr;
}

int main() {
  int n = 5;
  Producto *inventario = crearInventario(n);
  mostrarInventario(inventario, n);
  int codigo = 102;
  buscarProducto(inventario, 5, codigo);
  liberarInventario(inventario, n);
  return 0;
}

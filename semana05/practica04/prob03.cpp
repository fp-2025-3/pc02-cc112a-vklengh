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
  prod.nombre = new char[strlen(nombre)+1];
  strcpy(prod.nombre, nombre);
  prod.precio = precio;
  prod.stock = stock;
  return prod;
}

Producto *crearInventario(int n) {
  Producto *inventario = new Producto[n];
  *(inventario) = crearProducto(100, "Teclado", 10.5, 5);
  *(inventario + 1) = crearProducto(101, "Mouse", 21, 10);
  *(inventario + 2) = crearProducto(102, "Monitor", 31.5, 15);
  *(inventario + 3) = crearProducto(103, "Laptop", 42, 20);
  *(inventario + 4) = crearProducto(104, "Impresora", 52.5, 25);
  return inventario;
}

Producto *crearInventarioManual(int n) {
  Producto *inventario = new Producto[n];
  for (int i = 0; i < n; i++) {
    int codigo;
    string temp;
    char *nombre;
    double precio;
    int stock;
    cout << "Ingrese datos del producto: " << endl;
    cout << "Codigo: ";
    cin >> codigo;
    cin.ignore();
    cout << "Nombre: ";
    getline(cin,temp);
    nombre = &temp[0];
    cout << "Precio: ";
    cin >> precio;
    cin.ignore();
    cout << "Stock: ";
    cin >> stock;
    cin.ignore();
    *(inventario + i) = crearProducto(codigo, nombre, precio, stock);
  }
  return inventario;
}

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
    delete [] inventario[i].nombre;
    inventario[i].nombre = nullptr;
  }
  delete[] inventario;
  inventario = nullptr;
}

int main() {
  int n;
  int codigo;
  cout << "Ingrese la cantidad de productos a agregar al inventario: ";
  cin >> n;
  // Producto *inventario = crearInventario(5);
  // buscarProducto(inventario, 5, 102);
  // liberarInventario(inventario, 5);
  Producto *inventario = crearInventarioManual(n);
  mostrarInventario(inventario, n);
  cout << "Ingrese el codigo del producto que quiere buscar: ";
  cin >> codigo;
  buscarProducto(inventario, n, codigo);
  liberarInventario(inventario, n);
  return 0;
}

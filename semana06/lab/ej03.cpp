#include <fstream> // para manejar archivos
#include <iostream>
using namespace std;

struct Producto {
  int id;          // Identificador único
  char nombre[30]; // Nombre del producto
  double precio;   // Precio unitario
  int stock;       // Cantidad disponible
  bool activo;     // true = activo, false = eliminado lógicamente
};

// [P1][P2][P3].....[Pn]

int buscarProductoID(const char *nombreArchivo, int Idbuscar) {
  // Como vamos a buscar un producto en un archivo binario instanciamos la clase
  // ifstream
  ifstream archivo(nombreArchivo, ios::binary);

  if (!archivo) {
    cout << "Error al abrir el archivo" << endl;
    return -1;
  }

  Producto p;

  int posicion = 0;

  while (archivo.read((char *)&p, sizeof(Producto))) {
    if (p.id == Idbuscar) {
      archivo.close();
      return posicion;
    }
    posicion++;
  }

  archivo.close();
  return -1;
}

// a) funcion para registrar un producto
void registrarProducto(const char *nombreArchivo) {
  Producto p; // en C struct Producto p;

  cout << "Ingrese ID: ";
  cin >> p.id;

  // No debe permitir IDs repetidos.
  if (buscarProductoID(nombreArchivo, p.id) != -1) {
    cerr << "ERROR, el ID ya existe" << endl;
    return;
  }

  cin.ignore(); // limpiamos el buffer
  cout << "Ingrese el nombre: ";
  cin.getline(p.nombre, 30);

  cout << "Ingrese el precio: ";
  cin >> p.precio;

  if (p.precio <= 0) {
    cout << "Precio invalido" << endl;
    return;
  }

  cout << "Ingrese stock: ";
  cin >> p.stock;

  if (p.stock < 0) {
    cout << "Stock invalido" << endl;
    return;
  }

  p.activo = true;

  // USAMOS ARCHIVOS ARCHIVOS

  // Paso 1: instanciar un objeto de la clase ofstream y activar el modo binario
  ofstream archivo(nombreArchivo, ios::binary | ios::app);

  if (!archivo) {
    cout << "Error al abrir el archivo" << endl;
    return;
  }

  // Paso 2: Escribir en el archivo binario
  archivo.write(
      (char *)&p,
      sizeof(
          Producto)); // archivo.write(reinterpret_cast<char*>(&p),sizeof(Producto))

  archivo.close();

  cout << "Producto registrado correctamente" << endl;
}

void modificarPrecio(const char *nombreArchivo, int id, double nuevoPrecio) {
  fstream archivo(nombreArchivo, ios::binary | ios::in | ios::out);

  if (!archivo) {
    cout << "Error al abrir el archivo" << endl;
    return;
  }
  int posicion = buscarProductoID(nombreArchivo, id);
  if (posicion == -1) {
    cerr << "Producto no encontrado\n";
    archivo.close();
    return;
  }
  // PARTE DE ACCESO ALEATORIO
  // MOVER EL PUNTERO DE LECTURA: seekg();

  Producto p;
  archivo.seekg(posicion * sizeof(Producto), ios::beg);

  // leer el producto en posicion
  archivo.read((char *)&p, sizeof(Producto));
  p.precio = nuevoPrecio;

  // regresar el puntero al inicio
  archivo.seekp(posicion * sizeof(Producto), ios::beg);
  // escribir el struct producto en el binario
  archivo.write((char *)&p, sizeof(Producto));
  archivo.close();
  clog << "Se modifico el precio correctamente\n";
}

void mostrarProductos(const char *nombreArchivo) {
  fstream archivo(nombreArchivo, ios::binary | ios::in);

  if (!archivo) {
    cout << "Error al abrir el archivo" << endl;
    return;
  }
  Producto p;
  archivo.seekg(0, ios::beg);

  while (archivo.read((char *)&p, sizeof(Producto))) {
    if (p.activo) {
      cout << "Producto: " << p.nombre << " posicion: " << archivo.tellg()
           << endl;
    }
  }
  archivo.close();
}

void eliminarProducto(const char *nombreArchivo, int id) {
  fstream archivo(nombreArchivo, ios::binary | ios::in | ios::out);

  if (!archivo) {
    cout << "Error al abrir el archivo" << endl;
    return;
  }
  int posicion = buscarProductoID(nombreArchivo, id);
  if (posicion == -1) {
    cerr << "Producto no encontrado\n";
    archivo.close();
    return;
  }
  // PARTE DE ACCESO ALEATORIO
  // MOVER EL PUNTERO DE LECTURA: seekg();

  Producto p;
  archivo.seekg(posicion * sizeof(Producto), ios::beg);

  // leer el producto en posicion
  archivo.read((char *)&p, sizeof(Producto));
  p.activo = false;

  // regresar el puntero al inicio
  archivo.seekp(posicion * sizeof(Producto), ios::beg);
  // escribir el struct producto en el binario
  archivo.write((char *)&p, sizeof(Producto));
  archivo.close();
  clog << "Se cambió el estado a falso correctamente\n";
}

double calcularValorInventario(const char *nombreArchivo) {
  fstream archivo(nombreArchivo, ios::binary | ios::in);

  if (!archivo) {
    cerr << "Error al abrir el archivo" << endl;
    return -1;
  }
  Producto p;
  archivo.seekg(0, ios::beg);

  double total = 0.;
  while (archivo.read((char *)&p, sizeof(Producto))) {
    if (p.activo) {
      total += p.precio * p.stock;
    }
  }
  archivo.close();
  return total;
}

void menu() {
  bool terminado = false;
  const char *nombreArchivo = "inputs/inventario.dat";
  while (!terminado) {
    int opcion;
    cout << "MENU\n";
    cout << "--------------------------------------\n";
    cout << "Presione 1 para registrar producto\n";
    cout << "Presione 2 para mostrar productos\n";
    cout << "Presione 3 para buscar producto\n";
    cout << "Presione 4 para modificar precio\n";
    cout << "Presione 5 para eliminar producto\n";
    cout << "Presione 6 para calcular valor total\n";
    cout << "Presione 7 para salir del programa\n";
    cin >> opcion;
    switch (opcion) {
    case 1: {
      registrarProducto(nombreArchivo);
      break;
    }
    case 2: {
      mostrarProductos(nombreArchivo);
      break;
    }
    case 3: {
      int id, busqueda;
      cout << "Ingrese el id a buscar\n";
      cin >> id;
      busqueda = buscarProductoID(nombreArchivo, id);
      cout << "Se encontro producto en la posicion: " << busqueda << endl;
      break;
    }
    case 4: {
      int id;
      double nuevoPrecio;
      cout << "Ingrese el id del producto\n";
      cin >> id;
      cout << "Ingrese el nuevo precio\n";
      cin >> nuevoPrecio;
      modificarPrecio(nombreArchivo, id, nuevoPrecio);
      break;
    }
    case 5: {
      int id;
      cout << "Ingrese el id del producto a eliminar\n";
      cin >> id;
      eliminarProducto(nombreArchivo, id);
      break;
    }
    case 6: {
      double total = calcularValorInventario(nombreArchivo);
      cout << "Valor total inventario: " << total << endl;
      break;
    }
    case 7:
      terminado = true;
      cout << "Se termino el programa\n";
      break;
    default:
      cout << "Opcion invalida, intentelo nuevamente\n";
      break;
    }
  }
}

int main() {
  menu();
  return 0;
}

#include <fstream>
#include <iostream>

using namespace std;

struct Venta {
  int idVenta;
  int idVendedor;
  int idProducto;
  int cantidad;
  double precioUnitario;
};

struct Vendedor {
  int id;
  double ventaTotal;
};

struct Producto {
  int id;
  int cantidadVendida;
};

void leerVenta() {
  Venta v;
  const string path = "entradas/ventas.dat";
  ifstream archivo(path, ios::binary);

  if (!archivo) {
    cout << "Error al abrir el archivo" << endl;
    return;
  }

  int totalRegistros;
  archivo.read((char *)&totalRegistros, sizeof(int));
  Vendedor *vendedor = new Vendedor[totalRegistros];
  Producto *productos = new Producto[totalRegistros];
  Venta *ventaSospechosa = new Venta[totalRegistros];
  double montoTotalVendido = 0.;
  int n = 0;
  int iVendedor = 0;
  int iProducto = 0;
  int iVentaSospechosa = 0;

  while (archivo.read((char *)&v, sizeof(Venta))) {
    // archivoSalida << "ID venta: " << v.idVenta << " | ID vendedor: " <<
    // v.idVendedor
    //      << " | ID Producto: " << v.idProducto << " | Cantidad: " <<
    //      v.cantidad
    //      << " | Precio Unidad: " << v.precioUnitario << endl;
    montoTotalVendido += v.precioUnitario * v.cantidad;

    // VENDEDORES
    if (iVendedor == 0) {
      // vendedorArray[iVendedor] = v.idVendedor;
      vendedor[0].id = v.idVendedor;
      vendedor[0].ventaTotal = v.cantidad * v.precioUnitario;
      iVendedor++;
    } else {
      bool vendedorEnLista = false;
      for (int i = 0; i < iVendedor; i++) {
        if (vendedor[i].id == v.idVendedor) {
          vendedorEnLista = true;
          vendedor[i].ventaTotal += v.cantidad * v.precioUnitario;
          // son id unicos, no hace falta leer mas
          break;
        }
      }
      if (!vendedorEnLista) {
        vendedor[iVendedor].id = v.idVendedor;
        vendedor[iVendedor].ventaTotal = v.cantidad * v.precioUnitario;
        iVendedor++;
      }
    }

    // PRODUCTOS
    if (iProducto == 0) {
      productos[0].id = v.idProducto;
      productos[0].cantidadVendida = v.cantidad;
      iProducto++;
    } else {
      bool productoEnLista = false;
      for (int i = 0; i < iProducto; i++) {
        if (productos[i].id == v.idProducto) {
          productoEnLista = true;
          productos[i].cantidadVendida += v.cantidad;
          break;
        }
      }
      if (!productoEnLista) {
        productos[iProducto].id = v.idProducto;
        productos[iProducto].cantidadVendida = v.cantidad;
        iProducto++;
      }
    }

    // VENTAS SOSPECHOSAS
    if (v.cantidad > 100) {
      ventaSospechosa[iVentaSospechosa] = v;
      iVentaSospechosa++;
    }
    n++;
  }
  archivo.close();

  Vendedor vendedorMaximo = vendedor[0];
  for (int i = 0; i < iVendedor; i++) {
    if (vendedorMaximo.ventaTotal < vendedor[i].ventaTotal) {
      vendedorMaximo = vendedor[i];
    }
  }
  Producto productoMasVendido = productos[0];
  for (int i = 0; i < iProducto; i++) {
    if (productoMasVendido.cantidadVendida < productos[i].cantidadVendida) {
      productoMasVendido = productos[i];
    }
  }

  // GUARDAR EN ARCHIVO
  ofstream archivoSalida;
  const string archivoDir = "./salidas/reporte.txt";

  archivoSalida.open(archivoDir);
  if (!archivoSalida) {
    cerr << "No se pudo abrir el archivo de reporte.\n";
  }

  archivoSalida << "--- REPORTE GENERAL DE VENTAS ----" << endl;
  archivoSalida << endl;
  archivoSalida << "Total de registros: " << totalRegistros << endl;
  archivoSalida << endl;
  archivoSalida << "MONTO TOTAL VENDIDO:\n";
  archivoSalida << "S/." << montoTotalVendido << endl;
  archivoSalida << endl;

  archivoSalida << "---------------------------------------\n";
  archivoSalida << "VENDEDOR CON MAYOR RECAUDACIÓN:\n";
  archivoSalida << "ID Vendedor: " << vendedorMaximo.id << endl;
  archivoSalida << "Total vendido: S/." << vendedorMaximo.ventaTotal << endl;
  archivoSalida << endl;

  archivoSalida << "---------------------------------------\n";
  archivoSalida << "PRODUCTO MÁS VENDIDO: \n"
                << "ID Producto: " << productoMasVendido.id << endl
                << "Total Unidades: " << productoMasVendido.cantidadVendida
                << endl;
  archivoSalida << endl;

  archivoSalida << "---------------------------------------\n";
  archivoSalida << "VENTAS SOSPECHOSAS (cantidad > 100):" << endl;
  archivoSalida << endl;
  int cantidadVentasSospechosas = 0;
  for (int i = 0; i < iVentaSospechosa; i++) {
    cantidadVentasSospechosas++;
    archivoSalida << "ID venta: " << ventaSospechosa[i].idVenta
                  << " | Vendedor: " << ventaSospechosa[i].idVendedor
                  << " | Producto: " << ventaSospechosa[i].idProducto
                  << " | Cantidad: " << ventaSospechosa[i].cantidad << endl;
  }

  archivoSalida.close();
  delete[] vendedor;
  delete[] productos;
  delete[] ventaSospechosa;
}

int main() {
  leerVenta();
  return 0;
}

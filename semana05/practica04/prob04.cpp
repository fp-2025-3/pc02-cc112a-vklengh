#include <iostream>
#include <cstring>
using namespace std;

struct Item{
    char *descripcion;
    int cantidad;
    double PrecioUnitario;
};

struct Pedido{
    int numeroPedido;
    char *nombreCliente;
    Item* items;
    int cantidadItems;
};

Item crearItem(const char* descripcion, int cantidad, double precio){
    Item item;
    item.descripcion = new char;
    strcpy(item.descripcion, descripcion);
    item.PrecioUnitario = precio;
    item.cantidad = cantidad;
    return item;
}

Pedido *crearPedido(int numero, const char* cliente, int cantidadItems){
    Pedido *pedido = new Pedido;
    pedido->nombreCliente = new char;
    Item *item = new Item;
    char *desc;
    int cant;
    double precio;
    pedido->items = crearItem(desc, cant, precio);

}


int main() {

  return 0;
}



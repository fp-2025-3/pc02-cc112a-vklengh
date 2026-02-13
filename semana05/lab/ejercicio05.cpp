#include <iostream>
using namespace std;

// Estructura autoreferenciada
struct ListaProcesos {
  int ID;
  string nombre;
  int memUsada;
  ListaProcesos *sig;
};

void llenarLista(ListaProcesos *&nuevo) {
  cout << "Ingrese ID: ";
  cin >> nuevo->ID;
  cin.ignore();
  cout << "Ingrese nombre: ";
  getline(cin, nuevo->nombre);
  cout << "Ingrese consumo de memoria en MB: ";
  cin >> nuevo->memUsada;
  cin.ignore();
}

void crearListaProcesos(ListaProcesos *&cabeza, int n) {
  // Iniciaiza la lista
  for (int i = 0; i < n; i++) {
    ListaProcesos *nuevo = new ListaProcesos;
    nuevo->sig = cabeza;
    nuevo->ID = 0;
    nuevo->nombre = "";
    nuevo->memUsada = 0;
    cabeza = nuevo;
  }
}

void insertarAlInicio(ListaProcesos *&cabeza) {
  ListaProcesos *nuevo = new ListaProcesos;
  cout << "Ingrese los datos del proceso que se va a agrgar al inicio de la "
          "lista."
       << endl;
  llenarLista(nuevo);
  nuevo->sig = cabeza;
  cabeza = nuevo;
}

void insertarAlFinal(ListaProcesos *&cabeza) {
  ListaProcesos *nuevo = new ListaProcesos;
  cout << "Ingrese los datos del proceso que se va a agrgar al final de la "
          "lista."
       << endl;
  llenarLista(nuevo);
  nuevo->sig = nullptr;
  if (cabeza == nullptr) {
    cabeza = nuevo;
    return;
  }
  ListaProcesos *temp = cabeza;
  while (temp->sig != nullptr) {
    temp = temp->sig;
  }
  temp->sig = nuevo;
}

void imprimirElementos(ListaProcesos *cabeza) {
  cout << "Mostrando todos los procesos:" << endl;
  while (cabeza != nullptr) {
    if (cabeza->nombre != "") {
      cout << "ID: " << cabeza->ID << endl;
      cout << "Nombre: " << cabeza->nombre << endl;
      cout << "Consumo de memoria :" << cabeza->memUsada << "MB" << endl;
    }
    cabeza = cabeza->sig;
  }
}

void contarProcesos(ListaProcesos *cabeza) {
  int contador = 0;
  while (cabeza != nullptr) {
    if (cabeza->nombre != "") {
      contador++;
    }
    cabeza = cabeza->sig;
  }
  cout << "El numero de procesos es:" << contador << endl;
}

void buscarID(ListaProcesos *cabeza, int ID) {
  while (cabeza != nullptr) {
    if (cabeza->ID == ID) {
      cout << "Se encontro el proceso con ID: " << ID << endl;
      return;
    }
    cabeza = cabeza->sig;
  }
  cout << "No se encontro el proceso con ID: " << ID << endl;
}

void eliminarProceso(ListaProcesos *&cabeza, int ID) {
  ListaProcesos *actual = cabeza;
  ListaProcesos *anterior = nullptr;

  // Caso donde el proceso esta en la cabeza
  if (actual != nullptr and actual->ID == ID) {
    cabeza = actual->sig;
    delete actual;
    return;
  }

  // Caso donde el proceso esta en el medio
  while (actual != nullptr and actual->ID != ID) {
    anterior = actual;
    actual = actual->sig;
  }

  // Caso donde el proceso no existe
  if (actual == nullptr) {
    cout << "El ID no existe" << endl;
    return;
  }

  // Desvincular el puntero
  anterior->sig = actual->sig;

  // Liberar memoria del nodo eliminado
  delete actual;
}

ListaProcesos *insertarOrdenado(ListaProcesos *nuevo, ListaProcesos *ordenado) {
}
void ordenarProcesos(ListaProcesos *&cabeza) {}

void limpiarMemoria(ListaProcesos *&cabeza) {
  // Limpia la memoria
  while (cabeza != nullptr) {
    ListaProcesos *temp = cabeza;
    cabeza = cabeza->sig;
    delete temp;
  }
  delete cabeza;
}

int main() {
  int ID;
  ListaProcesos *cabeza = nullptr;
  int n = 1;
  int alInicio = 3;
  int alFinal = 2;
  crearListaProcesos(cabeza, n);
  for (int i = 0; i < alInicio; i++) {
    insertarAlInicio(cabeza);
  }
  for (int i = 0; i < alFinal; i++) {
    insertarAlFinal(cabeza);
  }
  imprimirElementos(cabeza);
  for (int i = 0; i < 2; i++) {
    cout << "Ingrese el ID del proceso que quiere buscar: ";
    cin >> ID;
    buscarID(cabeza, ID);
  }
  for (int i = 0; i < 4; i++) {
    cout << "Ingrese el ID del proceso que quiere eliminar: ";
    cin >> ID;
    eliminarProceso(cabeza, ID);
  }
  imprimirElementos(cabeza);
  contarProcesos(cabeza);
  limpiarMemoria(cabeza);

  return 0;
}

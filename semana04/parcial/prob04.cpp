#include <iomanip>
#include <iostream>
using namespace std;

const char texto1[] = "Codigo";
const char texto2[] = "Promedio";

void inicializar_estudiantes(int *&codigo, float *&promedio, int n,
                             int inicial) {
  int *temp_cod = new int[n];
  float *temp_prom = new float[n];
  for (int i = 0; i < n; i++) {
    if (i < inicial) {
      cout << texto1 << " : ";
      cin >> temp_cod[i];
      cout << texto2 << " : ";
      cin >> temp_prom[i];
    }
  }
  codigo = temp_cod;
  promedio = temp_prom;
}

void agregar_estudiantes(int *&codigo, float *&promedio, int &n, int inicial,
                         int adicional) {
  if (inicial + adicional >= n) {
    n *= 2;
    int *temp_cod = new int[n];
    float *temp_prom = new float[n];
    for (int i = 0; i < inicial; i++) {
      temp_cod[i] = codigo[i];
      temp_prom[i] = promedio[i];
    }
    for (int i = inicial; i < inicial + adicional; i++) {
      cout << texto1 << " : ";
      cin >> temp_cod[i];
      cout << texto2 << " : ";
      cin >> temp_prom[i];
    }
    delete[] codigo;
    delete[] promedio;
    codigo = nullptr;
    promedio = nullptr;
    codigo = temp_cod;
    promedio = temp_prom;
  } else {
    for (int i = inicial; i < inicial + adicional; i++) {
      cout << texto1 << " : ";
      cin >> codigo[i];
      cout << texto2 << " : ";
      cin >> promedio[i];
    }
  }
}
void EliminarMemoria(int *&codigo, float *&promedio) {
  delete[] codigo;
  delete[] promedio;
  codigo = nullptr;
  promedio = nullptr;
}

int eliminarEstudiantes(int *&codigo, float *&promedio, int final) {
  int contador = 0;
  int *idx_list = new int[final];
  // Un bucle para determinar la cantidad de elementos que el
  // array debe tener y otro para hacer las asignaciones
  for (int i = 0; i < final; i++) {
    if (promedio[i] >= 10) {
      *(idx_list + contador) = i;
      contador++;
    }
  }
  int *temp_cod = new int[contador];
  float *temp_prom = new float[contador];
  int idx = 0;
  while (idx < contador) {
    temp_cod[idx] = codigo[idx_list[idx]];
    temp_prom[idx] = promedio[idx_list[idx]];
    idx++;
  }
  delete[] idx_list;
  delete[] codigo;
  delete[] promedio;
  idx_list = nullptr;
  codigo = nullptr;
  promedio = nullptr;
  codigo = temp_cod;
  promedio = temp_prom;
  return contador;
}

void imprimir(int *codigo, float *promedio, int inicial, int adicional) {
  for (int i = 0; i < inicial + adicional; i++) {
    cout << "Codigo: " << codigo[i] << " Promedio: " << fixed << setprecision(1)
         << promedio[i] << endl;
  }
}

int main() {
  int n; // tamano de arreglo
  int n_inicial, n_extra;
  int n1, n2, nf;
  cout << "Ingrese el tamanio del arreglo: ";
  cin >> n;
  cout << "Ingrese la cantidad de estudiantes a registrar: ";
  cin >> n_inicial;
  int *codigo;
  float *promedio;
  n1 = n;
  inicializar_estudiantes(codigo, promedio, n, n_inicial);
  imprimir(codigo, promedio, n_inicial, 0);
  cout << "Ingrese la cantidad de estudiantes que quiere agregar: ";
  cin >> n_extra;
  agregar_estudiantes(codigo, promedio, n, n_inicial, n_extra);
  n2 = n;
  cout << "Estudiantes registrados:" << endl;
  imprimir(codigo, promedio, n_inicial, n_extra);
  n = eliminarEstudiantes(codigo, promedio, n_inicial + n_extra);
  nf = n;
  cout << "\n" << endl;
  cout << "Filtrando a estudiantes desaprobados..." << endl;
  cout << "\n" << endl;
  cout << "Estudiantes aprobados:" << endl;
  imprimir(codigo, promedio, n, 0);
  EliminarMemoria(codigo, promedio);
  cout << "===============================" << endl;
  cout << "Informacion adicional para monitorear como cambian los tamanios del "
          "array."
       << endl;
  cout << "Tamanio del array inicial: " << n1 << endl;
  cout << "Tamanio del array con los datos agregados: " << n2 << endl;
  cout << "Tamanio del array con los datos filtrados: " << nf << endl;
  return 0;
}

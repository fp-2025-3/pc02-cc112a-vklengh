#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int key) {
  int low = 0, high = n - 1;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (arr[mid] == key) {
      return mid;
    } else if (arr[mid] < key) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  return -1;
}

int main() {

  int arr[] = {2, 4, 5, 7, 9, 11, 13, 15, 17, 19};

  int n = sizeof(arr) / sizeof(arr[0]);

  int key = 4;

  int resultado = binarySearch(arr, n, key);

  if (resultado == -1) {
    cout << "El elemento no se encuentra en el arreglo" << endl;
  } else {
    cout << "Elemento encontrado en el indice " << resultado << endl;
  }

  return 0;
}

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

void printarray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int nuevo_pivote(int arr[], int menor, int mayor) {
  int pivote = arr[mayor];
  int i = menor - 1;
  for (int j = menor; j <= mayor - 1; j++) {
    if (arr[j] < pivote) {
      i++;
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i + 1], arr[mayor]);
  return i + 1;
}

int rand_pivote(int arr[], int menor, int mayor) {
  srand(time(0));
  int random = menor + rand() % (mayor - menor);
  swap(arr[random], arr[mayor]);
  return nuevo_pivote(arr, menor, mayor);
}

void quicksort(int arr[], int menor, int mayor) {
  if (menor < mayor) {
    int pivote = rand_pivote(arr, menor, mayor);
    quicksort(arr, menor, pivote - 1);
    quicksort(arr, pivote + 1, mayor);
  }
}

int main() {
  int array[] = {10, 5, 42, 3, 12, 9, 8, 6};
  int n = sizeof(array) / sizeof(array[0]);
  printarray(array, n);
  quicksort(array, 0, n - 1);
  printarray(array, n);
  return 0;
}

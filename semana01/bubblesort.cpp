#include <iostream>
using namespace std;

void printarray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

void bubblesort(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
      }
    }
  }
}

int main() {
  int array[] = {10, 5, 42, 3, 12, 9, 8, 6};
  int n = sizeof(array) / sizeof(array[0]);
  printarray(array, n);
  bubblesort(array, n);
  printarray(array, n);
  return 0;
}

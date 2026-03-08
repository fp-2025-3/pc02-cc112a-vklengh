#include <iostream>
using namespace std;

void printarray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

void selectionsort(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    int min_idx = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[min_idx]) {
        min_idx = j;
      }
    }
    swap(arr[i], arr[min_idx]);
  }
}

int main() {
  int array[] = {10, 5, 42, 3, 12, 9, 8, 6};
  int n = sizeof(array) / sizeof(array[0]);
  printarray(array, n);
  selectionsort(array, n);
  printarray(array, n);
  return 0;
}

#include <iostream>
using namespace std;

void printarray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

void merge(int arr[], int l, int med, int r) {
  int n1 = med - l + 1;
  int n2 = r - med;
  int L[100], R[100];

  for (int i = 0; i < n1; i++) {
    L[i] = arr[l + i];
  }
  for (int i = 0; i < n2; i++) {
    R[i] = arr[med + 1 + i];
  }
  int i = 0, j = 0;
  int k = l;

  while (i < n1 and j < n2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }
  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }
}

void mergesort(int arr[], int l, int r) {
  if (l >= r) {
    return;
  }
  int med = l + (r - l) / 2;
  mergesort(arr, l, med);
  mergesort(arr, med + 1, r);
  merge(arr, l, med, r);
}

int main() {
  int array[] = {10, 5, 42, -5, 6, 3, 12, 9, 8, 6};
  int n = sizeof(array) / sizeof(array[0]);
  printarray(array, n);
  mergesort(array, 0, n - 1);
  printarray(array, n);
  return 0;
}

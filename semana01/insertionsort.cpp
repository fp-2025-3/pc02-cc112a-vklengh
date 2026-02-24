#include <iostream>
using namespace std;

void printarray(int arr[], int n){
    for (int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertionsort(int arr[], int n) {
  for (int i = 0; i < n; i++) {
      int key = arr[i];
      int j = i-1;
      while (j>=0 and arr[j] > key){
          arr[j+1] = arr[j];
          j = j-1;
      }
      arr[j+1]=key;
  }
}

int main() {
  int array[] = {10, 5, 42, 3, 12, 9, 8, 6};
  int n = sizeof(array) / sizeof(array[0]);
  printarray(array, n);
  insertionsort(array, n);
  printarray(array, n);
  return 0;
}

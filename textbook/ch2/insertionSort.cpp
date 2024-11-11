#include <iostream>
using std::cout;

void print(int arr[], int size) {
  for (int i=0; i < size; i++) {
    if (i == 0) cout << "[";
    cout << arr[i];
    if (i == size - 1) cout << "]";
    else cout << ", ";
  }
  cout << std::endl;
};

/** Complexity
 * Time:
 *  best - O(n), already sorted
 *  average - ?
 *  worst - O(n^2), reverse sorted
 * Space: O(n)
 */
void insertionSort(int* arr, int size) {
  for (int i=1; i < size; i++) {
    int cur = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > cur) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = cur;
  }  
}

int main() {
  int foo [5] = {8, 2, 7, 9, 1};
  insertionSort(foo, 5);
  print(foo, 5);
}
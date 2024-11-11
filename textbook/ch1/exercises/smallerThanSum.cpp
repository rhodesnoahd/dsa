#include <iostream>

// function returns the sum of all positive integers smaller than n
int smallerThanSum(int n) {
  if (n <= 0) {return 0;}
  int ans = 0;
  while (n - 1 > 0) {
    ans += n - 1;
    n--;
  }
  return ans;
}

int main() {
  int res = smallerThanSum(5); // 4 + 3 + 2 + 1 = 10
  std::cout << res << std::endl;
}
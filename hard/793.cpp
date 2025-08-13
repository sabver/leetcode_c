#include <algorithm>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  int preimageSizeFZF(int k) { return (int)right_bound(k) - left_bound(k) + 1; }
  long left_bound(int target) {
    long left = 0, right = LONG_MAX;
    while (left <= right) {
      long mid = left + (right - left) / 2;
      long zeros = trailingZeroes(mid);
      if (zeros == target) {
        // lock left bound
        right = mid - 1;
      } else if (zeros > target) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return left;
  }
  long right_bound(int target) {
    long left = 0, right = LONG_MAX;
    while (left <= right) {
      long mid = left + (right - left) / 2;
      long zeros = trailingZeroes(mid);
      if (zeros == target) {
        // lock right bound
        left = mid + 1;
      } else if (zeros > target) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return right;
  }
  long trailingZeroes(long n) {
    long ans = 0, divisor = 5;
    while (n >= divisor) {
      n /= divisor;
      ans += n;
    }
    return ans;
  }
};

int main() { Solution solution; }
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
  int nthUglyNumber(int n, int a, int b, int c) {
    int left = 1, right = 2e9;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      long r = f(mid, a, b, c);
      if (r < n) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return left;
  }
  // calculate how many numbers between [1..num] can be divided by a or b or c
  long f(int num, int a, int b, int c) {
    // set theory theorem: A + B + C - A ∩ B - A ∩ C - B ∩ C + A ∩ B ∩ C
    long setA = num / a, setB = num / b, setC = num / c;
    long setAB = num / lcm(a, b);
    long setAC = num / lcm(a, c);
    long setBC = num / lcm(b, c);
    long setABC = num / lcm(lcm(a, b), c);
    return setA + setB + setC - setAB - setAC - setBC + setABC;
  }
  // greatest common divisor(Euclidean algorithm)
  // ensure a > b
  long gcd(long a, long b) {
    if (a < b) {
      return gcd(b, a);
    }
    if (b == 0) {
      return a;
    }
    return gcd(b, a % b);
  }
  // least common multiple
  long lcm(long a, long b) { return a * b / gcd(a, b); }
};

int main() { Solution solution; }
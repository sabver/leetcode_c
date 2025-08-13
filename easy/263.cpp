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
  bool isUgly(int n) {
    if (n <= 1) {
      return false;
    }
    while (n % 2 == 0) {
      n /= 2;
    }
    while (n % 3 == 0) {
      n /= 3;
    }
    while (n % 5 == 0) {
      n /= 5;
    }
    return n == 1;
  }
};

int main() { Solution solution; }
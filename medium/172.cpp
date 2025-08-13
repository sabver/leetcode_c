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
  int trailingZeroes(int n) {
    int ans = 0, divisor = 5;
    while (n >= divisor) {
      n /= divisor;
      ans += n;
    }
    return ans;
  }
};

int main() { Solution solution; }
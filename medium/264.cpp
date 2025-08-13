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
  int nthUglyNumber(int n) {
    vector<int> ugly(n + 1);
    int p2 = 1, p3 = 1, p5 = 1, p = 1, product2 = 1, product3 = 1, product5 = 1;
    while (p <= n) {
      int min = std::min({product2, product3, product5});
      ugly[p] = min;
      p++;

      if (min == product2) {
        product2 = 2 * ugly[p2];
        p2++;
      }
      if (min == product3) {
        product3 = 3 * ugly[p3];
        p3++;
      }
      if (min == product5) {
        product5 = 5 * ugly[p5];
        p5++;
      }
    }
    return ugly[n];
  }
};

int main() { Solution solution; }
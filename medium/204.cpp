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
  int countPrimes(int n) {
    vector<bool> isPrime(n, true);
    for (int i = 2; i * i < n; i++) {
      if (isPrime[i]) {
        for (int j = i * i; j < n; j += i) {
          isPrime[j] = false;
        }
      }
    }
    int count = 0;
    for (int i = 2; i < n; i++) {
      if (isPrime[i]) {
        count++;
      }
    }
    return count;
  }
};

int main() { Solution solution; }
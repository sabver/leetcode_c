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
  int nthSuperUglyNumber(int n, vector<int> &primes) {
    auto cmp = [](const vector<long long> &a, const vector<long long> &b) {
      return a[0] > b[0];
    };
    priority_queue<vector<long long>, vector<vector<long long>>, decltype(cmp)>
        pq(cmp);
    for (int i = 0; i < primes.size(); i++) {
      // triplets int[] {product, prime, pi}
      pq.push({1, primes[i], 1});
    }
    vector<long long> ugly(n + 1);
    int p = 1;
    while (p <= n) {
      vector<long long> pair = pq.top();
      pq.pop();
      long long product = pair[0];
      long long prime = pair[1];
      long long index = pair[2];

      // Avoid duplicate elements in the result linked list
      if (product != ugly[p - 1]) {
        ugly[p] = product;
        p++;
      }

      vector<long long> nextPair = {ugly[index] * prime, prime, index + 1};
      pq.push(nextPair);
    }
    return static_cast<int>(ugly[n]);
  }
};

int main() { Solution solution; }
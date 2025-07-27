#include <algorithm>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <list>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k) {
    // shift k times
    // j->( j + k ) mod n
    // if ( j + 1 ) mod n == 0 then ( i + 1 ) mod m
    // c -> i should move c times
    // ( i + c ) mod m
    // how to calculate c ？=> c = floor(( j + k ) / m)
    int n = grid.size(), m = grid[0].size(), ni = 0, nj = 0, c = 0;
    vector<vector<int>> res(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        c = std::floor((j + k) / m);
        ni = (i + c) % n;
        nj = (j + k) % m;
        res[ni][nj] = grid[i][j];
      }
    }
    return res;
  }
};

int main() { Solution solution; }
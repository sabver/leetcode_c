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
  vector<vector<int>> diagonalSort(vector<vector<int>> &mat) {
    int m = mat.size(), n = mat[0].size();

    std::unordered_map<int, std::list<int>> diagonals;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        int id = i - j;
        diagonals[id].push_back(mat[i][j]);
      }
    }

    for (auto &[key, vec] : diagonals) {
      vec.sort(std::greater<int>());
    }

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        int id = i - j;
        auto &vec = diagonals[id];
        mat[i][j] = vec.back();
        vec.pop_back();
      }
    }
    return mat;
  }
};

int main() { Solution solution; }
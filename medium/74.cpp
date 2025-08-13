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
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    int left = 0, right = getIndex(m - 1, n - 1, n);
    while (left <= right) {
      int mid = left + (right - left) / 2;
      vector<int> pair = reverseIndex(mid, n);
      if (matrix[pair[0]][pair[1]] == target) {
        return true;
      } else if (matrix[pair[0]][pair[1]] > target) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return false;
  }
  int getIndex(int row, int col, int n) {
    // (m - 1) * n + n - 1 = mn - 1
    return row * n + col;
  }
  vector<int> reverseIndex(int index, int n) {
    vector<int> res;
    int row = index / n, col = index % n;
    res.push_back(row);
    res.push_back(col);
    return res;
  }
};

int main() { Solution solution; }
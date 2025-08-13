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
    int row = matrix.size(), column = matrix[0].size(), top = 0,
        bottom = row - 1, left = 0, right = column - 1;
    return searchMatrix(matrix, target, left, right, top, bottom, row, column);
  }
  bool searchMatrix(vector<vector<int>> &matrix, int target, int left,
                    int right, int top, int bottom, int row, int column) {
    if (left > right || top > bottom) {
      return false;
    }
    if (target < matrix[top][left] || target > matrix[bottom][right]) {
      return false;
    }
    int midRow = top + (bottom - top) / 2;
    int midCol = left + (right - left) / 2;
    int midVal = matrix[midRow][midCol];

    if (midVal == target) {
      return true;
    } else if (midVal > target) {
      // Search top-left, top-right, bottom-left
      return searchMatrix(matrix, target, left, midCol - 1, top, midRow - 1,
                          row, column) || // top-left
             searchMatrix(matrix, target, midCol, right, top, midRow - 1, row,
                          column) || // top-right
             searchMatrix(matrix, target, left, midCol - 1, midRow, bottom, row,
                          column); // bottom-left

    } else {
      // Search bottom-right, bottom-left, top-right
      // Search bottom-right, bottom-left, top-right
      return searchMatrix(matrix, target, midCol + 1, right, midRow + 1, bottom,
                          row, column) || // bottom-right
             searchMatrix(matrix, target, left, midCol, midRow + 1, bottom, row,
                          column) || // bottom-left
             searchMatrix(matrix, target, midCol + 1, right, top, midRow, row,
                          column);
    }
  }
};

int main() { Solution solution; }
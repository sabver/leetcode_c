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
  int searchInsert(vector<int> &nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] >= target) {
        right = mid - 1;
      } else {
        // nums[mid] < target
        left = mid + 1;
      }
    }
    return left;
  }
};

int main() { Solution solution; }
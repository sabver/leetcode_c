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
  bool search(vector<int> &nums, int target) {
    int peedIndex = findPivot(nums);
    if (target == nums[0]) {
      return true;
    }
    bool result = binarySearch(nums, 0, peedIndex, target);
    if (result) {
      return result;
    }
    return binarySearch(nums, peedIndex + 1, nums.size() - 1, target);
  }
  bool binarySearch(vector<int> &nums, int left, int right, int target) {
    int l = left, r = right;
    while (l <= r) {
      int mid = l + (r - l) / 2;
      if (target == nums[mid]) {
        return true;
      } else if (target > nums[mid]) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    return false;
  }
  int findPivot(vector<int> &nums) {
    int n = nums.size(), left = 0, right = n - 1, index = n - 1;
    while (index - 1 >= 0 && nums[index] == nums[index - 1]) {
      index--;
    }
    right = index - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] == nums[index]) {
        left = mid + 1;
      } else if (nums[mid] > nums[index]) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return left - 1;
  }
};

int main() { Solution solution; }
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
  int search(vector<int> &nums, int target) {
    int peedIndex = findPivot(nums);
    if (target == nums[0]) {
      return 0;
    }
    int result = binarySearch(nums, 0, peedIndex, target);
    if (result != -1) {
      return result;
    }
    return binarySearch(nums, peedIndex + 1, nums.size() - 1, target);
  }
  int binarySearch(vector<int> &nums, int left, int right, int target) {
    int result = -1, l = left, r = right;
    while (l <= r) {
      int mid = l + (r - l) / 2;
      if (target == nums[mid]) {
        return mid;
      } else if (target > nums[mid]) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    return result;
  }
  int findPivot(vector<int> &nums) {
    int n = nums.size(), left = 0, right = n - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] > nums[n - 1]) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return left - 1;
  }
};

int main() { Solution solution; }
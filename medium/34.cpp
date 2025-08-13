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
  vector<int> searchRange(vector<int> &nums, int target) {
    vector<int> res;
    res.push_back(left_bound(nums, target));
    res.push_back(right_bound(nums, target));
    return res;
  }
  int left_bound(vector<int> &nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] == target) {
        // lock left bound
        right = mid - 1;
      } else if (nums[mid] > target) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return left < 0 || left >= nums.size() || nums[left] != target ? -1 : left;
  }
  int right_bound(vector<int> &nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] == target) {
        // lock right bound
        left = mid + 1;
      } else if (nums[mid] > target) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return right < 0 || right >= nums.size() || nums[right] != target ? -1
                                                                      : right;
  }
};

int main() { Solution solution; }
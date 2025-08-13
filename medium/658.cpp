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
  vector<int> findClosestElements(vector<int> &arr, int k, int x) {
    vector<int> res;
    int p = left_bound(arr, x);
    //(left, right)
    int left = p - 1, right = p;
    while (right - left - 1 < k) {
      if (left == -1) {
        right++;
      } else if (right == arr.size()) {
        left--;
      } else if (x - arr[left] > arr[right] - x) {
        right++;
      } else {
        left--;
      }
    }
    for (int i = left + 1; i < right; i++) {
      res.push_back(arr[i]);
    }
    return res;
  }
  int left_bound(vector<int> &nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] == target) {
        // lock left bound left half
        right = mid - 1;
      } else if (nums[mid] < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return left;
  }
};

int main() { Solution solution; }
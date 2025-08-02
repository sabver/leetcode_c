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
  int numSubarrayProductLessThanK(vector<int> &nums, int k) {
    int n = nums.size(), windowProduct = 1, left = 0, right = 0, res = 0;

    while (right < n) {
      int c = nums[right];
      right++;

      windowProduct *= c;

      while (windowProduct >= k && left < right) {
        int d = nums[left];
        left++;

        windowProduct /= d;
      }

      res += right - left;
    }

    return res;
  }
};

int main() { Solution solution; }
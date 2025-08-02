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
  int minSubArrayLen(int target, vector<int> &nums) {
    int left = 0, right = 0, window = 0, res = INT_MAX;
    while (right < nums.size()) {
      int d = nums[right];
      right++;

      window += d;

      while (window >= target) {
        if (window >= target) {
          res = min(res, right - left);
        }
        int c = nums[left];
        left++;

        window -= c;
      }
    }
    return res == INT_MAX ? 0 : res;
  }
};

int main() { Solution solution; }
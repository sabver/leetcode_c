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
  int minOperations(vector<int> &nums, int x) {
    int n = nums.size(), sum = 0;
    for (int i = 0; i < n; i++) {
      sum += nums[i];
    }
    int target = sum - x;
    int left = 0, right = 0;
    int windowSum = 0;
    int maxLen = INT_MIN;
    while (right < n) {
      windowSum += nums[right];
      right++;

      while (windowSum > target && left < right) {
        windowSum -= nums[left];
        left++;
      }
      if (windowSum == target) {
        maxLen = max(maxLen, right - left);
      }
    }
    return maxLen == INT_MIN ? -1 : n - maxLen;
  }
};

int main() { Solution solution; }
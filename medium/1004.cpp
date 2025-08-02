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
  int longestOnes(vector<int> &nums, int k) {
    int left = 0, right = 0, count = 0, len = INT_MIN, n = nums.size();
    while (right < n) {
      int c = nums[right];
      right++;

      if (c == 0) {
        count++;
      }
      if (count <= k) {
        len = max(len, right - left);
      }

      while (right > left && count > k) {
        int d = nums[left];
        left++;

        if (d == 0) {
          count--;
        }
      }
    }
    return len == INT_MIN ? 0 : len;
  }
};

int main() { Solution solution; }
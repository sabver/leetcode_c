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
  int findPeakElement(vector<int> &nums) {
    int left = 0, right = nums.size() - 1;
    while (left < right) {
      int mid = left + (right - left) / 2;
      // mid maybe a peek element
      if (nums[mid] > nums[mid + 1]) {
        right = mid;
      } else {
        // nums[mid] < nums[mid + 1]
        // mid is impossible a peek element
        left = mid + 1;
      }
    }
    return left;
  }
};

int main() { Solution solution; }
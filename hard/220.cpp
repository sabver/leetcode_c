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
  bool containsNearbyAlmostDuplicate(vector<int> &nums, int indexDiff,
                                     int valueDiff) {
    set<long> window;
    int left = 0, right = 0;
    while (right < nums.size()) {
      int d = nums[right];

      auto ceiling = window.lower_bound((long)d);
      if (ceiling != window.end() && *ceiling - d <= valueDiff) {
        return true;
      }

      if (ceiling != window.begin()) {
        auto floor = prev(ceiling);
        if ((long)d - *floor <= valueDiff) {
          return true;
        }
      }

      window.insert(d);
      right++;

      while (right - left > indexDiff) {
        int c = nums[left];
        left++;
        window.erase((long)c);
      }
    }
    return false;
  }
};

int main() { Solution solution; }
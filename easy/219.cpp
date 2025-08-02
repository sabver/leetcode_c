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
  bool containsNearbyDuplicate(vector<int> &nums, int k) {
    unordered_map<int, int> indexmap;
    indexmap[nums[0]] = 0;
    for (int i = 1; i < nums.size(); i++) {
      int d = nums[i];
      if (indexmap.count(d) > 0) {
        if (i - indexmap[d] <= k) {
          return true;
        }
      }
      indexmap[d] = i;
    }
    return false;
  }
};

int main() { Solution solution; }
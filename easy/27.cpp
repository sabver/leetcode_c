#include <vector>
using namespace std;

class Solution {
public:
  int removeElement(vector<int> &nums, int val) {
    int n = nums.size();
    if (n == 0) {
      return 0;
    }
    // [0, left] => element not equal to val
    int left = -1, right = 0;
    while (right < n) {
      if (nums[right] == val) {
        right++;
      } else {
        left++;
        nums[left] = nums[right];
        right++;
      }
    }
    return left + 1;
  }
};
#include <vector>
using namespace std;

class Solution {
public:
  void moveZeroes(vector<int> &nums) {
    int n = nums.size();
    if (n == 0) {
      return;
    }
    // [-, left]=>elements not-zero
    int left = -1, right = 0;
    while (right < n) {
      if (nums[right] == 0) {
        right++;
      } else {
        left++;
        nums[left] = nums[right];
        right++;
      }
    }
    for (int i = left + 1; i < n; i++) {
      nums[i] = 0;
    }
  }
};
#include <vector>
using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    int n = nums.size();
    if (n <= 1) {
      return n;
    }
    // [0, left]->unique array
    int left = 0, right = 0;
    while (right < n) {
      if (nums[right] == nums[left]) {
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
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    int n = nums.size();
    if (n <= 2) {
      return n;
    }
    // [0, left]->array removed duplicates, [left+1, right]->should be handled
    // [right+1, n - 1]->next to check
    int left = 0, right = 1, count = 1, duplicate = nums[0];
    while (right < n) {
      // record
      if (duplicate == nums[right]) {
        count++;
      } else {
        duplicate = nums[right];
        count = 1;
      }
      std::cout << "duplicate:" << duplicate << std::endl;
      std::cout << "count:" << count << std::endl;
      if (count <= 2) {
        left++;
        nums[left] = nums[right];
      }
      right++;
    }
    return left + 1;
  }
};
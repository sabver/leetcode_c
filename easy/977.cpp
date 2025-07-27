#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> sortedSquares(vector<int> &nums) {
    int n = nums.size(), left = 0, right = n - 1, i = n - 1;
    vector<int> result(n);

    while (left <= right) {
      if (std::abs(nums[left]) <= std::abs(nums[right])) {
        result[i] = std::pow(nums[right], 2);
        right--;
      } else {
        result[i] = std::pow(nums[left], 2);
        left++;
      }
      i--;
    }
    return result;
  }
};

int main() { Solution solution; }
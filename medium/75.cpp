#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  void sortColors(vector<int> &nums) {
    // [0, p0) => for element 0
    // (p2, n - 1]
    int n = nums.size(), p0 = 0, p2 = n - 1, p = 0;
    while (p <= p2) {
      if (nums[p] == 0) {
        swap(nums, p0, p);
        p0++;
      } else if (nums[p] == 2) {
        swap(nums, p2, p);
        p2--;
      } else {
        p++;
      }
      if (p < p0) {
        p = p0;
      }
    }
  }
  void swap(vector<int> &nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
  }
};

int main() { Solution solution; }
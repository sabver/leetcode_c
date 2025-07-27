#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    int total = nums1.size(), i = m - 1, j = n - 1, k = total - 1;
    while (i >= 0 && j >= 0) {
      if (nums1[i] <= nums2[j]) {
        nums1[k] = nums2[j];
        j--;
        k--;
      } else {
        nums1[k] = nums1[i];
        i--;
        k--;
      }
    }
    if (j >= 0) {
      while (j >= 0 && k >= 0) {
        nums1[k] = nums2[j];
        j--;
        k--;
      }
    }
  }
};

int main() { Solution solution; }
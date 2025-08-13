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
  int peakIndexInMountainArray(vector<int> &arr) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (arr[mid] < arr[mid + 1]) {
        left = mid + 1;
      } else {
        // arr[mid] > arr[mid+1]
        right = mid - 1;
      }
    }
    return left;
  }
};

int main() { Solution solution; }
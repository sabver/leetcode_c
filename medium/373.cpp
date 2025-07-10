#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2,
                                     int k) {
    vector<vector<int>> result;
    auto cmp = [](const vector<int> &a, const vector<int> &b) {
      return a[0] + a[1] > b[0] + b[1];
    };
    std::priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)>
        minHeap;
    int n1 = nums1.size(), n2 = nums2.size();
    for (int i = 0; i < n1; i++) {
      minHeap.push({nums1[i], nums2[0], 0});
    }
    int count = 0;
    while (count < k) {
      auto top = minHeap.top();
      minHeap.pop();
      int nextIndex = top[2] + 1;
      if (nextIndex < n2) {
        minHeap.push({top[0], nums2[nextIndex], nextIndex});
      }
      result.push_back({top[0], top[1]});
      count++;
    }
    return result;
  }
};

int main() {
  Solution solution;

  std::cout << "test" << std::endl;
}
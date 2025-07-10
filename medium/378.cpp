#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
  int val;
  int index;
};
class Solution {
public:
  int kthSmallest(vector<vector<int>> &matrix, int k) {
    int count = 0, n = matrix.size();
    auto cmp = [](const Node &a, const Node &b) { return a.val > b.val; };
    std::priority_queue<Node, std::vector<Node>, decltype(cmp)> minHeap;
    vector<int> curIndexLists(n);
    for (int i = 0; i < n; i++) {
      if (matrix[i].size() > 0) {
        minHeap.push({matrix[i][0], i});
        curIndexLists[i] = 0;
      } else {
        curIndexLists[i] = -1;
      }
    }
    while (count <= k) {
      Node top = minHeap.top();
      minHeap.pop();
      int index = top.index;
      // next
      if (curIndexLists[index] + 1 < n) {
        curIndexLists[index]++;
        minHeap.push({matrix[index][curIndexLists[index]], index});
      } else {
        curIndexLists[index]++;
      }
      count++;
      if (count == k) {
        return top.val;
      }
    }
    return 0;
  }
};

int main() {
  Solution solution;

  std::cout << "test" << std::endl;
}
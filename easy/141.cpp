#include <iostream>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
  bool hasCycle(ListNode *head) { return true; }
};

int main() {
  Solution solution;
  ListNode *head = nullptr;
  bool result = solution.hasCycle(head);
  std::cout << "Has Cycle? " << std::boolalpha << result << std::endl;
}
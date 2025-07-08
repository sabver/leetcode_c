#include <iostream>
#include <unordered_set>

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
  void print(ListNode *head) {
    int maxCut = 10, count = 0;
    ListNode *curr = head;
    while (curr != nullptr) {
      std::cout << curr->val << std::endl;
      curr = curr->next;
      count++;
      if (count > maxCut) {
        break;
      }
    }
  }
  ListNode *detectCycle(ListNode *head) {
    std::unordered_set<ListNode *> nodesSeen;
    ListNode *curr = head;
    while (curr != nullptr) {
      if (nodesSeen.find(curr) != nodesSeen.end()) {
        return curr;
      }
      nodesSeen.insert(curr);
      curr = curr->next;
    }
    return nullptr;
  }
};

int main() {
  Solution solution;
  ListNode *node1 = new ListNode(3);
  ListNode *node2 = new ListNode(2);
  ListNode *node3 = new ListNode(0);
  ListNode *node4 = new ListNode(-4);

  ListNode *head = node1;
  head->next = node2;
  head->next->next = node3;
  head->next->next->next = node4;
  head->next->next->next->next = node2;
  solution.print(head);
  ListNode *result = solution.detectCycle(head);
  std::cout << "detect result:" << result->val << std::endl;
}
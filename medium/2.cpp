#include <iostream>
#include <vector>
using namespace std;

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
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
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
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *dummy = new ListNode(), *head = new ListNode();
    int lastTotal = 0, total = 0;
    dummy->next = head;
    while (l1 != nullptr && l2 != nullptr) {
      total = l1->val + l2->val + (lastTotal > 9 ? 1 : 0);
      if (total > 9) {
        head->next = new ListNode(total - 10);
      } else {
        head->next = new ListNode(total);
      }
      lastTotal = total;
      l1 = l1->next;
      l2 = l2->next;
      head = head->next;
    }
    ListNode *rest = l1 == nullptr ? l2 : l1;
    while (rest != nullptr) {
      total = rest->val + (lastTotal > 9 ? 1 : 0);
      if (total > 9) {
        head->next = new ListNode(total - 10);
      } else {
        head->next = new ListNode(total);
      }
      lastTotal = total;
      rest = rest->next;
      head = head->next;
    }
    if (lastTotal > 9) {
      head->next = new ListNode(1);
    }
    return dummy->next->next;
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
}
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
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (headA == nullptr || headB == nullptr) {
      return nullptr;
    }
    if (headA == headB) {
      return headA;
    }
    int countA = 0, countB = 0;
    ListNode *currA = headA, *currB = headB;
    while (currA != nullptr) {
      currA = currA->next;
      countA++;
    }
    while (currB != nullptr) {
      currB = currB->next;
      countB++;
    }
    ListNode *shortHead = countA <= countB ? headA : headB;
    ListNode *longHead = countA > countB ? headA : headB;
    int count = 0;
    while (longHead != nullptr) {
      if (count == std::abs(countA - countB)) {
        break;
      }
      longHead = longHead->next;
      count++;
    }
    while (longHead != nullptr) {
      if (longHead == shortHead) {
        return longHead;
      }
      longHead = longHead->next;
      shortHead = shortHead->next;
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
}
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

  ListNode *reverseBetween(ListNode *head, int left, int right) {
    if (head == nullptr) {
      return nullptr;
    }
    if (head->next == nullptr || left == right) {
      return head;
    }
    int index = 0;
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *pre = dummy, *leftNode = head, *rightNode = head, *curr = head,
             *leftPrev = dummy, *next = head->next, *rightNext = head->next;
    while (curr != nullptr) {
      if (index == left - 1) {
        // found leftNode and pre
        leftNode = curr;
        leftPrev = pre;
      }
      if (index >= left - 1 && index <= right - 1) {
        // reverse
        curr->next = pre;
      }
      // move forward
      pre = curr;
      curr = next;
      if (next != nullptr) {
        next = next->next;
      }
      if (index == right - 1) {
        rightNode = pre;
        rightNext = curr;
        break;
      }

      index++;
    }
    leftPrev->next = rightNode;
    leftNode->next = rightNext;
    return dummy->next;
  }

  int main() {
    Solution solution;
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(4);

    ListNode *head = node1;
    head->next = node2;
    head->next->next = node3;
    head->next->next->next = node4;
    // solution.print(head);
  }
};
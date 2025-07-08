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
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode *dummy = new ListNode(0);
    ListNode *result = dummy;
    while (list1 != nullptr || list2 != nullptr) {
      if (list1 != nullptr && list2 != nullptr) {
        if (list1->val <= list2->val) {
          dummy->next = list1;
          list1 = list1->next;
        } else {
          dummy->next = list2;
          list2 = list2->next;
        }
      } else if (list1 != nullptr) {
        dummy->next = list1;
        list1 = list1->next;
      } else {
        dummy->next = list2;
        list2 = list2->next;
      }
      dummy = dummy->next;
    }
    return result->next;
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
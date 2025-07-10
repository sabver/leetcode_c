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
  ListNode *partition(ListNode *head, int x) {
    if (head == nullptr) {
      return nullptr;
    }
    ListNode *less = new ListNode(-1), *greater = new ListNode(-1);
    ListNode *dummy = less, *greaterHead = greater;
    while (head != nullptr) {
      if (head->val < x) {
        less->next = head;
        less = less->next;
      } else {
        greater->next = head;
        greater = greater->next;
      }
      head = head->next;
    }
    // ?
    greater->next = nullptr;
    less->next = greaterHead->next;
    return dummy->next;
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
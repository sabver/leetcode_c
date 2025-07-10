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
  ListNode *deleteDuplicates(ListNode *head) {
    if (head == nullptr) {
      return nullptr;
    }
    ListNode *dummy = new ListNode(101);
    dummy->next = head;
    ListNode *before = dummy, *curr = head;
    bool flag = false;
    while (curr != nullptr) {
      flag = false;
      while (curr->next != nullptr && curr->val == curr->next->val) {
        flag = true;
        // delete
        curr->next = curr->next->next;
      }
      if (flag) {
        // delete
        before->next = curr->next;
        curr = before->next;
      } else {
        before = before->next;
        curr = curr->next;
      }
    }
    return dummy->next;
  }
};

int main() {
  Solution solution;
  ListNode *node1 = new ListNode(1);
  ListNode *node2 = new ListNode(2);
  ListNode *node3 = new ListNode(3);
  ListNode *node4 = new ListNode(4);
  ListNode *node5 = new ListNode(5);
  std::cout << "test" << std::endl;
  ListNode *head = node1;
  head->next = node2;
  head->next->next = node3;
  head->next->next->next = node4;
  head->next->next->next->next = node5;
}
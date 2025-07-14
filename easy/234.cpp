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
  bool result = true;
  ListNode *left;
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
  bool isPalindrome2(ListNode *head) {
    left = head;
    ListNode *right = head;
    traverse(right);
    return result;
  }

  void traverse(ListNode *right) {
    if (right == nullptr) {
      return;
    }
    traverse(right->next);
    if (left->val != right->val) {
      result = false;
    }
    left = left->next;
  }
  bool isPalindrome(ListNode *head) {
    ListNode *slow = head, *fast = head;
    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
    }
    if (fast != nullptr) {
      slow = slow->next;
    }

    ListNode *left = head;
    ListNode *right = reverse(slow);
    while (right != nullptr) {
      if (left->val != right->val) {
        return false;
      }
      left = left->next;
      right = right->next;
    }
    return true;
  }
  ListNode *reverse(ListNode *head) {
    if (head == nullptr) {
      return nullptr;
    }
    if (head->next == nullptr) {
      return head;
    }
    // ListNode *pre = nullptr, *curr = head, *next = head->next;
    ListNode *pre, *curr, *next;
    pre = nullptr;
    curr = head;
    next = head->next;
    while (curr != nullptr) {
      curr->next = pre;
      pre = curr;
      curr = next;
      if (next != nullptr) {
        next = next->next;
      }
    }
    return pre;
  }
};

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

  ListNode *result = solution.reverse(head);
  solution.print(result);
}
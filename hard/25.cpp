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

  ListNode *reverseKGroup(ListNode *head, int k) {
    if (head == nullptr) {
      return nullptr;
    }
    if (head->next == nullptr) {
      return head;
    }
    int n = 0;
    ListNode *curr = head;
    while (curr != nullptr) {
      curr = curr->next;
      n++;
    }
    return reverseKGroupRecursive(head, k, n);
  }

  ListNode *reverseKGroupRecursive(ListNode *head, int k, int n) {
    if (n < k) {
      return head;
    }
    if (head == nullptr) {
      return nullptr;
    }
    if (head->next == nullptr) {
      return head;
    }
    ListNode *newHead = reverseK(head, k);
    head->next = reverseKGroupRecursive(head->next, k, n - k);
    return newHead;
  }

  ListNode *reverseK(ListNode *head, int k) {
    if (head == nullptr) {
      return nullptr;
    }
    if (head->next == nullptr || k <= 1) {
      return head;
    }
    ListNode *pre = nullptr, *curr = head, *nxt = head->next;
    while (curr != nullptr && k > 0) {
      // reverse
      curr->next = pre;
      // move forward
      pre = curr;
      curr = nxt;
      if (nxt != nullptr) {
        nxt = nxt->next;
      }
      k--;
    }
    // link the rest node
    head->next = curr;
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
  head = solution.reverseK(head, 4);
  solution.print(head);
}
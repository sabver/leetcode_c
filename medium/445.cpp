#include <iostream>
#include <stack>
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
    std::stack<ListNode *> s1, s2;
    ListNode *curr1 = l1, *curr2 = l2;
    vector<int> list;
    while (curr1 != nullptr) {
      s1.push(curr1);
      curr1 = curr1->next;
    }
    while (curr2 != nullptr) {
      s2.push(curr2);
      curr2 = curr2->next;
    }
    ListNode *dummy = new ListNode(), *head = new ListNode();
    int lastTotal = 0, total = 0;
    dummy->next = head;
    while (!s1.empty() || !s2.empty() || lastTotal > 9) {
      int x = s1.empty() ? 0 : s1.top()->val;
      int y = s2.empty() ? 0 : s2.top()->val;
      total = x + y + (lastTotal > 9 ? 1 : 0);
      if (total > 9) {
        list.push_back(total - 10);
      } else {
        list.push_back(total);
      }
      lastTotal = total;
      if (!s1.empty()) {
        s1.pop();
      }
      if (!s2.empty()) {
        s2.pop();
      }
    }
    for (int i = list.size() - 1; i >= 0; i--) {
      head->next = new ListNode(list[i]);
      head = head->next;
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
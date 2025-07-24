#include <vector>
using namespace std;

class Solution {
public:
  void reverseString(vector<char> &s) {
    int n = s.size();
    int left = 0, right = n - 1;
    while (left < right) {
      char temp = s[left];
      s[left] = s[right];
      s[right] = temp;
      left++;
      right--;
    }
  }
};
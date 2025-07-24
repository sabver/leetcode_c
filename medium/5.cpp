#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string longestPalindrome(string s) {
    string res = "";
    for (int i = 0; i < s.length(); i++) {
      string s1 = palindrome(s, i, i);
      string s2 = palindrome(s, i, i + 1);
      res = res.length() < s1.length() ? s1 : res;
      res = res.length() < s2.length() ? s2 : res;
    }
    return res;
  }
  string palindrome(string s, int l, int r) {
    while (l >= 0 && r < s.length() && s[l] == s[r]) {
      l--;
      r++;
    }
    return s.substr(l + 1, r - l - 1);
  }
};
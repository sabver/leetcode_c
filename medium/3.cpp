#include <algorithm>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <list>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int left = 0, right = 0, len = 0, valid = 0;
    unordered_map<char, int> window;
    while (right < s.size()) {
      char c = s[right];
      right++;

      bool repeat = false;
      if (window.count(c) && window[c] >= 1) {
        repeat = true;
      } else {
        len = max(right - left, len);
      }
      window[c]++;
      while (repeat) {
        char d = s[left];
        left++;

        if (d == c) {
          repeat = false;
        }
        window[d]--;
      }
    }
    return len;
  }
};

int main() { Solution solution; }
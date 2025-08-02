#include <algorithm>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  int longestSubstring(string s, int k) {
    int len = 0;
    for (int i = 1; i <= 26; i++) {
      len = max(len, logestKLetterSubstr(s, k, i));
    }
    return len;
  }
  int logestKLetterSubstr(string s, int k, int count) {
    int left = 0, right = 0, len = INT_MIN, windowUniqueCount = 0,
        windowValid = 0;
    unordered_map<char, int> window;
    while (right < s.length()) {
      char c = s[right];
      right++;
      if (window[c] == 0) {
        windowUniqueCount++;
      }
      window[c]++;
      if (window[c] == k) {
        windowValid++;
      }

      while (windowUniqueCount > count) {
        char d = s[left];
        left++;

        if (window[d] == k) {
          windowValid--;
        }
        window[d]--;
        if (window[d] == 0) {
          windowUniqueCount--;
        }
      }

      if (windowValid == count) {
        len = max(len, right - left);
      }
    }
    return len == INT_MIN ? 0 : len;
  }
};

int main() { Solution solution; }
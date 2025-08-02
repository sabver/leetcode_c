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
  int characterReplacement(string s, int k) {
    int left = 0, right = 0;
    vector<int> windowCharCount(26, 0);
    int windowMaxCount = 0;
    int res = 0;
    while (right < s.length()) {
      int c = s[right] - 'A';
      windowCharCount[c]++;
      right++;

      windowMaxCount = max(windowMaxCount, windowCharCount[c]);
      while (right - left - windowMaxCount > k) {
        int d = s[left] - 'A';
        left++;
        windowCharCount[d]--;
      }
      res = max(right - left, res);
    }
    return res;
  }
};

int main() { Solution solution; }
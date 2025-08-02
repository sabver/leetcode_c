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
  vector<int> findAnagrams(string s, string p) {
    unordered_map<char, int> need, window;
    for (char c : p) {
      need[c]++;
    }
    vector<int> res;
    int left = 0, right = 0, valid = 0;
    while (right < s.size()) {
      char c = s[right];
      right++;

      if (need.count(c)) {
        window[c]++;
        if (need[c] == window[c]) {
          valid++;
        }
      }

      while (right - left >= p.size()) {
        if (valid == need.size()) {
          res.push_back(left);
        }
        char d = s[left];
        left++;
        if (need.count(d)) {
          if (need[d] == window[d]) {
            valid--;
          }
          window[d]--;
        }
      }
    }
    return res;
  }
};

int main() { Solution solution; }
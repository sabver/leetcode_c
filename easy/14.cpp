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
  string longestCommonPrefix(vector<string> &strs) {
    string res = "";
    int n = strs.size(), shortLen = strs[0].length(), curLen = 0;
    bool isEqual = true;
    for (int i = 1; i < n; i++) {
      curLen = strs[i].length();
      shortLen = curLen < shortLen ? curLen : shortLen;
    }
    for (int i = 0; i < shortLen; i++) {
      isEqual = true;
      for (int j = 0; j < n; j++) {
        if (strs[j][i] != strs[0][i]) {
          isEqual = false;
          break;
        }
      }
      if (isEqual) {
        res += strs[0].at(i);
      } else {
        break;
      }
    }
    return res;
  }
};

int main() { Solution solution; }
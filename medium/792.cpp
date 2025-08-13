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

struct Node {
  string word;
  int index;
};
class Solution {
public:
  int numMatchingSubseq(string s, vector<string> &words) {
    int ans = 0;
    vector<vector<Node>> bucket(26);

    for (const string &word : words) {
      bucket[word[0] - 'a'].push_back({word, 0});
    }
    for (char c : s) {
      vector<Node> old_bucket = move(bucket[c - 'a']);
      for (Node &node : old_bucket) {
        node.index++;
        if (node.index == node.word.length()) {
          ans++;
        } else {
          bucket[node.word[node.index] - 'a'].push_back(node);
        }
      }
    }
    return ans;
  }
};

int main() { Solution solution; }
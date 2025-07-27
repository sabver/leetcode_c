#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  bool isPalindrome(string s) {
    // 97->a 122->z 65->A 90->Z
    // 0->48 9->57
    int n = s.length(), left = 0, right = n - 1, ascii_code_left = 0,
        ascii_code_right = 0;
    if (n < 2) {
      return true;
    }
    while (left < right) {
      ascii_code_left = static_cast<int>(std::tolower(s[left]));
      std::cout << s[left] << " " << ascii_code_left << std::endl;
      if (!(ascii_code_left >= 97 && ascii_code_left <= 122) &&
          !(ascii_code_left >= 48 && ascii_code_left <= 57)) {
        left++;
        continue;
      }
      ascii_code_right = static_cast<int>(std::tolower(s[right]));
      std::cout << s[right] << " " << ascii_code_right << std::endl;
      if (!(ascii_code_right >= 97 && ascii_code_right <= 122) &&
          !(ascii_code_right >= 48 && ascii_code_right <= 57)) {
        right--;
        continue;
      }
      if (ascii_code_left != ascii_code_right) {
        return false;
      }
      left++;
      right--;
    }
    return true;
  }
};

int main() {
  Solution solution;
  string s = "0P";
  bool result = solution.isPalindrome(s);
  std::cout << result << std::endl;
}
#include <algorithm>
#include <iostream>
#include <limits.h>
#include <string>

class StringSolution {
public:
  std::string addBinary(std::string a, std::string b) {
    std::string result;
    int carry = 0;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    unsigned int alen = a.size();
    unsigned int blen = b.size();
    std::string short_str = b;
    std::string long_str = a;
    if (alen < blen) {
      short_str = a;
      long_str = b;
    }
    for (size_t i = 0; i < short_str.size(); i++) {
      unsigned int acc, val;

      acc = short_str[i] + long_str[i] - 2 * '0' + carry;
      carry = acc / 2;
      val = acc % 2;
      result.insert(result.begin(), val + '0');
    }
    size_t idx = short_str.size();
    while (idx < long_str.size()) {
      unsigned int acc, val;
      acc = long_str[idx] - '0' + carry;
      carry = acc / 2;
      val = acc % 2;
      idx++;
      result.insert(result.begin(), val + '0');
    }
    if (carry) {
      result.insert(result.begin(), '1');
    }
    return result;
  }
  int myAtoi(const std::string &str) {
    auto start = str.begin();
    int result = 0;
    int sign = 1;
    while (*start == ' ' && start != str.end()) {
      start++;
    }
    if (*start == '+') {
      sign = 1;
      start++;
    } else if (*start == '-') {
      sign = -1;
      start++;
    }
    while (start != str.end()) {
      if (*start > '9' || *start < '0') {
        break;
      }
      if (result > INT_MAX / 10 ||
          (result == INT_MAX && (*start - '0') > INT_MAX % 10)) {
        return (sign == -1) ? INT_MIN : INT_MAX;
      }
      result *= 10;
      result += *start - '0';
      start++;
    }
    return result * sign;
  }
  bool isPalindrome(std::string s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    auto left = s.begin(), right = prev(s.end());
    while (left < right) {
      if (!::isalnum(*left))
        left++;
      else if (!::isalnum(*right))
        right--;
      else if (*left != *right)
        return false;
      else {
        left++;
        right--;
      }
    }
    return true;
  }
  bool isMatch(const std::string &s, const std::string &p) {
    return isMatch(s.c_str(), p.c_str());
  }

private:
  bool isMatch(const char *s, const char *p) {
    if (*p == '\0')
      return *s == '\0';
    // next char is not '*', then must match current character
    if (*(p + 1) != '*') {
      if (*p == *s || (*p == '.' && *s != '\0'))
        return isMatch(s + 1, p + 1);
      else
        return false;
    } else { // next char is '*'
      while (*p == *s || (*p == '.' && *s != '\0')) {
        if (isMatch(s, p + 2))
          return true;
        s++;
      }
      return isMatch(s, p + 2);
    }
  }
};

int main(int argc, char const *argv[]) {
  StringSolution sol;
  std::string s = "AASS,DD.****SSAA";
  std::string p = "ac*a";
  std::cout << sol.isMatch(s, p) << std::endl;
  std::cout << "is Palindrome" << std::endl;
  std::cout << sol.isPalindrome(".,") << std::endl;
  std::cout << "atoi\t" << sol.myAtoi("125") << std::endl;
  std::cout << " add Binary\t" << sol.addBinary("1010", "1011") << std::endl;
  return 0;
}

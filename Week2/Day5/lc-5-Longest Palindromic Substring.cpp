#include <string>
#include <algorithm>

using namespace std;

class Solution {
private:
    // Helper to expand around center and return the length
    int expandAroundCenter(const string& s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;
    }

public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        
        int start = 0;
        int max_len = 0;
        int n = s.length();
        
        for (int i = 0; i < n; i++) {
            // Odd length palindromes (center at i)
            int len1 = expandAroundCenter(s, i, i);
            // Even length palindromes (center between i and i+1)
            int len2 = expandAroundCenter(s, i, i + 1);
            
            int len = max(len1, len2);
            if (len > max_len) {
                max_len = len;
                start = i - (len - 1) / 2;
            }
        }
        
        return s.substr(start, max_len);
    }
};
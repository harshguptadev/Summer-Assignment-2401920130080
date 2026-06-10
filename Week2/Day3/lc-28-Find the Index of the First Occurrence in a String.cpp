include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    int strStr(string haystack, string needle) {
        int i = 0, j = 0;
        int pos = -1;
 
        while (i < (int)haystack.size()) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            } else {
                i = i - j + 1; // restart from one step after current attempt's start
                j = 0;
            }
            if (j == (int)needle.size()) {
                pos = i - j;
                break;
            }
        }
        return pos;
    }
};
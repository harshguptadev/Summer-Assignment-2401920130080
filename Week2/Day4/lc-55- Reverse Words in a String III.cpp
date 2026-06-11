#include<bits/stdc++>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        using stack
        stack<char> box;
        int i = 0;
        while (i < s.size()) {
            box.push(s[i]);
            if (s[i] == ' ') {
                box.pop();
                for (int j = i - box.size(); j < i; j++) {
                    s[j] = box.top();
                    box.pop();
                }
            }
            i++;
        }
        for (int j = i - box.size(); j < i; j++) {
            s[j] = box.top();
            box.pop();
        }return s;
    }
};
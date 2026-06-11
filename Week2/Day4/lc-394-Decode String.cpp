#include <string>
#include <stack>
#include <cctype>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<int> counts;
        stack<string> resultStack;
        string currentString = "";
        int k = 0;

        for (char ch : s) {
            if (isdigit(ch)) {
                k = k * 10 + (ch - '0');
            } else if (ch == '[') {
                counts.push(k);
                resultStack.push(currentString);
                currentString = "";
                k = 0;
            } else if (ch == ']') {
                string previousString = resultStack.top();
                resultStack.pop();
                int repeatTimes = counts.top();
                counts.pop();

                string decodedSegment = "";
                for (int i = 0; i < repeatTimes; i++) {
                    decodedSegment += currentString;
                }
                currentString = previousString + decodedSegment;
            } else {
                currentString += ch;
            }
        }

        return currentString;
    }
};
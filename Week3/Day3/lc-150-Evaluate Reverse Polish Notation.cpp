#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        
        for (const string& token : tokens) {
            // Check if the token is an operator
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                // Pop the second operand first
                int b = st.top(); st.pop();
                // Pop the first operand second
                int a = st.top(); st.pop();
                
                // Perform the operation and push the result
                if (token == "+") st.push(a + b);
                else if (token == "-") st.push(a - b);
                else if (token == "*") st.push(a * b);
                else if (token == "/") st.push(a / b); // C++ division naturally truncates toward zero
            } else {
                // It's an operand (number), convert to int and push
                st.push(stoi(token));
            }
        }
        
        // The final remaining element is the result
        return st.top();
    }
};
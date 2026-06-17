#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<int> st; // Stores the indices of the temperatures
        
        for (int i = 0; i < n; i++) {
            // Check if the current temperature is warmer than the temperature at the stack's top index
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int prevIndex = st.top();
                st.pop();
                ans[prevIndex] = i - prevIndex; // Days to wait
            }
            st.push(i); // Push current day's index
        }
        
        return ans;
    }
};
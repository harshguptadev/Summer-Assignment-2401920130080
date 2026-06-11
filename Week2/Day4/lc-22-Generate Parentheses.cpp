#include<bits/stdc++>
using namespace std;

class Solution {
public:
    vector<string>vec;
    void generate(string &s,int open ,int close){
        if((open==0)&&(close==0)){
            vec.emplace_back(s);
            return;
        }
        if(open>0){
            s.emplace_back('(');
            generate(s,open-1,close);
            s.pop_back(); // backtrack
        }
        if(close<open){
            s.emplace_back(')');
            generate(s,open,close-1);
            s.pop_back(); // backtrack
        }
    }
    vector<string>generateParenthesis(int n){
        string s="";
        generate(s,n,n);
        return vec;
    }
}
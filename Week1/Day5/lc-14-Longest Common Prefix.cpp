#include <bits/stdc++.h>
typedef long long int ll;
#define pb push_back
#define all(x) (x).begin(), (x).end()
using namespace std;

#ifndef ONLINE_JUDGE
    #define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
    #define debug(x...)
#endif
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res=""; // empty string
        
        // flow flows flew flower

        bool flag=false; // flag

        for(int i=0;i<strs[0].size();i++){ // outer loop size of the first element
            for(int j=0;j<strs.size();j++){ // inner loop checks for the entire vector
                if((strs[0][i]!=strs[j][i])||(i==strs[j].size())){
                    flag=true;
                    break;
                }
            }
            if(flag==true){
                break;
            }
            res=res+strs[0][i];
        }return res;
    }
};
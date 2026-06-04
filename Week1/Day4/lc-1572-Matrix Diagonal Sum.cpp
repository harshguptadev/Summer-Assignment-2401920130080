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
    int diagonalSum(vector<vector<int>>& mat) {
        int sum=0; // sum counter
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat.size();j++){ //nested loop for i==j
                if(i==j){
                    sum+=mat[i][j];
                }
            }
        }
        for(int i=0;i<mat.size();i++){
            sum+=mat[i][mat.size()-1-i]; //loop for adding element [i][j] and [j][i]
        }
        if((mat.size()%2)!=0){ // odd
            sum-=mat[mat.size()/2][mat.size()/2]; // subtracting the common element if it is and odd ordered matrix
        }
        return sum;
    }
};
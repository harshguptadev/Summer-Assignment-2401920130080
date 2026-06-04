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
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top = 0;
        int bottom = matrix.size() - 1;
        int l = 0;
        int r = matrix[0].size()-1;

        vector<int> res;// empty vector for storing elements

        while (true) {

            // moving left to right
            if (r < l) {
                break;
            }
            for (int i = l; i <= r; i++) {
                res.emplace_back(matrix[top][i]);
            }
            top++;

            // moving top to bottom
            if (bottom < top) {
                break;
            }
            for (int i = top; i <= bottom; i++) {
                res.emplace_back(matrix[i][r]);
            }
            r--;

            // moving right to left
            if (r < l) {
                break;
            }
            for (int i = r; i >= l; i--) {
                res.emplace_back(matrix[bottom][i]);
            }
            bottom--;

            // moving bottom to top
            if (bottom < top) {
                break;
            }
            for (int i = bottom; i >= top; i--) {
                res.emplace_back(matrix[i][l]);
            }l++;
        }
        return res;
    }
};
// g++ -o d.out d.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc174/tasks/abc174_d
// oj t -c "./d.out"
// oj s https://atcoder.jp/contests/abc174/tasks/abc174_d d.cpp

#include <bits/stdc++.h>
using namespace std;
int c[300005];
map<int, int> mp;
// long long mod = 1000000007;
// 縦軸が弁当の種類、横軸がたこ焼きの数、配列の値が鯛焼きの数
int dp[301][301][301];

using namespace std;
int n;
string s;
int main()
{
    cin >> n >> s;
    int lmao = 0;
    for(int i = 0; i < n; i++)
        if(s[i] == 'R') lmao++;
    int bruh = lmao;
    for(int i = 0; i < lmao; i++)
        if(s[i] == 'R') bruh--;
    cout << bruh << endl;
    return 0;
}

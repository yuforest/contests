// g++ -o d.out d.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc222/tasks/abc222_d
// oj t -c "./d.out"
// oj s https://atcoder.jp/contests/abc222/tasks/abc222_d d.cpp

#include <bits/stdc++.h>
using namespace std;
int n, k;
int c[300005];
map<int, int> mp;
// long long mod = 1000000007;
// 縦軸が弁当の種類、横軸がたこ焼きの数、配列の値が鯛焼きの数
#define rep(i, n) for (int i = 0; i < (n); ++i)

int dp[33][101010];
int ans[101010];

int main(void)
{
  string S;
  cin >> S;
  int N = S.size();

  rep(i, N) {
    if (S[i] == 'R') dp[0][i] = i + 1;
    else dp[0][i] = i - 1;
  }

  // ダブリング
  rep(p, 32) rep(i, N) dp[p + 1][i] = dp[p][dp[p][i]];

  rep(i, N) ans[dp[32][i]]++;
  rep(i, N) {
    if (i) printf(" ");
    printf("%d", ans[i]);
  }
  printf("\n");
}
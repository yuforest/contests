// g++ -o c.out c.cpp -std=c++11
// oj d https://atcoder.jp/contests/abc216/tasks/abc216_c
// oj t -c "./c.out"
// oj s https://atcoder.jp/contests/abc216/tasks/abc216_c c.cpp

#include <bits/stdc++.h>
using namespace std;
int n, k;
int c[300005];
map<int, int> mp;
long long mod = 1000000007;
using ll = long long;

int main(void)
{
  int S;
  cin >> S;
  vector<ll> dp(2007, 0);
  dp[3] = 1;
  dp[4] = 1;
  dp[5] = 1;
  for(int i = 6; i <= 2000; i++) {
    for(int j = 3; j <= i-3; j++) {
      dp[i] += dp[j];
      dp[i] %= mod;
    }
    dp[i]++;
    dp[i] %= mod;
  }
  cout << dp[S] << endl;
}
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
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main(void)
{
  ll N, W;
  cin >> N >> W;
  ll w[N+1], v[N+1];
  rep(i, N) {
    cin >> w[i+1] >> v[i+1];
  }
  vector<vector<ll>> dp(N+1, vector<ll>(W+1, -1));
  dp[0][0] = 0LL;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j <= W; j++) {
      // 遷移できない
      if (dp[i][j] == -1) continue;
      // 重量オーバーでなければ選べる
      if (j+w[i+1] <= W) {
        // i+1番目を選んだ場合
        dp[i+1][j+w[i+1]] = max(dp[i+1][j+w[i+1]], dp[i][j] + v[i+1]);
      };
      // i+1番目を選ばなかった場合
      dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
    }
  }
  ll ans = 0;
  for(int weight = 0; weight <= W; weight++) {
    ans = max(ans, dp[N][weight]);
  }
  cout << ans << endl;
}
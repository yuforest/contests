#include<bits/stdc++.h>

using namespace std;
long long mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main(){
  ll N, M;
  cin >> N >> M;
  ll X[N+1];
  rep(i, N) {
    cin >> X[i+1];
  }
  map<int, ll> money;
  rep(i, M) {
    ll c, y;
    cin >> c >> y;
    money[c] = y;
  }
  // コイントス回数とカウンタのdp配列
  ll dp[N+1][N+1];
  for(int i = 0; i <= N;i++) {
    for(int j = 0; j <= N;j++) {
      dp[i][j] = -1;
    }
  }
  dp[0][0] = 0;
  for(ll i = 0; i < N; i++) {
    for(ll j = 0; j < N; j++) {
      if (dp[i][j] == -1) continue;
      ll next = i+1;
      // 表が出る場合はX[i]円もらえる
      ll tmp_money = dp[i][j] + X[next];
      // 次のカウンタの連続ボーナスをもらう
      tmp_money += money[j+1];
      dp[next][j+1] = max(dp[next][j+1], tmp_money);

      // 裏が出る場合
      dp[next][0] = max(dp[next][0], dp[i][j]);
    }
  }
  ll ans = 0;
  for(ll j = 0; j <= N; j++) {
    if (dp[N][j] == -1) continue;
    ans = max(ans, dp[N][j]);
  }
  cout << ans << endl;
  return 0;
}

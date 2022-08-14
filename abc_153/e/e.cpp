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
vector<int> G[1 << 18];

#define rep(i, n) for (int i = 0; i < (n); ++i)

using namespace std;
int n;
string s;
using ll = long long;
int main()
{
  ll H, N;
  cin >> H >> N;
  ll A[N], B[N];
  rep(i, N) {
    cin >> A[i] >> B[i];
  }
  // 減らせるHPの配列
  vector<ll> dp(H+1, 1000000007);
  dp[0] = 0;
  for(ll i = 0; i < N; i++) {
    ll damage = A[i];
    ll cost = B[i];
    for(ll j = 0; j <= H; j++) {
      // cout << dp[j] << endl;
      if (j + damage <= H) {
        // 遷移先と現在から遷移するコストを比較
        dp[j+damage] = min(dp[j+damage], dp[j] + cost);
        // cout << dp[j+damage] << endl;
      } else {
        // 与えるダメージがHPより大きい場合もコストを比較する
        dp[H] = min(dp[H], dp[j] + cost);
        // cout << dp[H] << endl;
      }
    }
  }
  cout << dp[H] << endl;
  return 0;
}

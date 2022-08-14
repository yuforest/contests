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
int dp[301][301][301];
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)
vector<vector<ll>> G[1 << 18];
typedef pair<ll, ll> P;


int main(void)
{
  ll N, M, X, Y;
  cin >> N >> M >> X >> Y;
  rep(i, M) {
    ll A, B, T, K;
    cin >> A >> B >> T >> K;
    // 都市、時間、出発時刻の配列をpush(無向グラフ)
    G[A].push_back({B, T, K});
    G[B].push_back({A, T, K});
  }
  // 昇順 (デフォルトはstd::less<T>)
  priority_queue<P, vector<P>, greater<P>> que;
  vector<ll> time(N+1, LLONG_MAX);
  vector<bool> used(N+1, false);
  que.push({0, X});
  time[0] = 0;
  while(!que.empty()) {
    P info = que.top();
    ll now_time = info.first;
    ll now_place = info.second;
    que.pop();
    if(used[now_place]) continue;
    // この時点でこの都市にくるコストは一番小さいのでここから他の都市を経由して、ここに帰ってきたとしても
    // 最小になることはない、よって確定させる
    used[now_place] = true;
    for(auto to: G[now_place]) {
      ll to_place = to[0];
      ll move_time = to[1];
      ll period = to[2];
      // 訪問していない都市なら
      if (used[to_place] == false) {
        // 現在の位置から移動する時間(切り上げなので分母をdoubleにcast)
        ll to_time = ceil(now_time / (double)period) * period + move_time;
        // 現在の位置から移動する方が早ければ更新
        time[to_place] = min(time[to_place], to_time);
        que.push({to_time, to_place});
      }
    }
  }
  if(time[Y] == LLONG_MAX) {
    cout << -1 << endl;
  } else {
    cout << time[Y] << endl;
  }

}
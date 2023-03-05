// 標準ライブラリを全て読み込む
// 本書では細かく書きませんが、下記リンクが参考になります
// https://atcoder.jp/contests/apg4b/tasks/APG4b_af
#include <bits/stdc++.h>
// stdのstd::cinのような書き方ではなくcinと書けば良くなる
using namespace std;

// デバッグ用マクロ
// 本書では細かく書きませんが、下記リンクが参考になります
// https://naskya.net/post/0002/
#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

// データ構造の省略
using ll = long long;
using vi = vector<int>;
using vl = vector<long long>;
using vs = vector<string>;
using vc = vector<char>;
using vb = vector<bool>;
using vpii = vector<pair<int, int>>;
using vpll = vector<pair<long long, long long>>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<long long>>;
using vvc = vector<vector<char>>;
using vvb = vector<vector<bool>>;
using vvvi = vector<vector<vector<int>>>;
using pii = pair<int, int>;

// modの計算
long long mod1 = 1000000007;
long long mod2 = 998244353;

// 隣接グラフ(1 << 18は2^18で262144となる)
vector<ll> G[1 << 18];
// vector<ll> rG[1 << 18];

// ACL(AtCoder Library)、普段はコメントアウトしてある
#include <atcoder/all>
using namespace atcoder;

// repマクロ
// 0からn-1まで
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
// aからb−1まで
#define rep3(i,a,b) for(int i=a;i<b;i++)
// n-1から0まで
#define per(i, n) for (int i = int(n) - 1; i >= int(0); i--)
// b-1からaまで
#define per3(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
// 範囲for文の省略
#define fore(i,a) for(auto &i:a)
// sort(A.begin(), A.end())をsort(all(A))のように書けます
#define all(x) (x).begin(), (x).end()

// 最大値と最小値の更新
// 返り値は更新した場合はtrue、そうでなければfalse
template <typename T>
inline bool chmax(T &a, T b) {
  return ((a < b) ? (a = b, true) : (false));
}
template <typename T>
inline bool chmin(T &a, T b) {
  return ((a > b) ? (a = b, true) : (false));
}

// void dfs(ll cur, ll depth) {
//   if (visited[cur]) {
//     return;
//   }
//   visited[cur] = true;
//   if (depth >= 2) {
//     ans++;
//   }
//   debug(cur, depth, ans);
//   fore(v, G[cur]) {
//     dfs(v, depth + 1);
//   }
// }

ll dist[2001];
int main(){
  ll N, M;
  cin >> N >> M;
  rep(i, M) {
    ll u, v;
    cin >> u >> v;
    u--;
    v--;
    G[u].push_back(v);
  }
  ll ans = 0;
  rep(i, N) {
    // 初期化
    rep(j, 2001) {
      dist[j] = 1e9;
    }
    dist[i] = 0;
    queue<ll> que;
    que.push(i);
    while (!que.empty()) {
      ll cur = que.front();
      que.pop();
      fore(v, G[cur]) {
        if (dist[v] > dist[cur] + 1) {
          dist[v] = dist[cur] + 1;
          debug(v, dist[v]);
          if (dist[v] >= 2) {
            ans++;
          }
          que.push(v);
        }
      }
    }
  }
  cout << ans << endl;
}
// ここは競プロではサボりがちです
#include <bits/stdc++.h>
using namespace std;

// デバッグ用マクロです。詳しくは https://naskya.net/post/0002/
#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

// 節操ないですが、競プロでは便利です。
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

map<int, int> mp;
long long mod = 1000000007;
vector<ll> G[1 << 18];

// ACLです。使わない時はコメントアウトしています。導入方法はググってみてください。
#include <atcoder/all>
using namespace atcoder;
#include <atcoder/all>
using namespace atcoder;

// 競プロerはrep3マクロが大好き
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep3(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(), (x).end()

// 無くても困らない
#define INFTY (1 << 30)

// 浮動小数点の誤差を考慮した等式ですが、使わずに済むなら使わない方が確実です
#define EPS (1e-7)
#define equal(a, b) (fabs((a) - (b)) < EPS)

#define yes "Yes"
#define no "No"


// DPやlong longの最大値最小値更新で重宝します。
template <typename T>
inline bool chmax(T &a, T b) {
  return ((a < b) ? (a = b, true) : (false));
}
template <typename T>
inline bool chmin(T &a, T b) {
  return ((a > b) ? (a = b, true) : (false));
}

#define INF INT_MAX/2

int N, A[303][303];
ll d[303][303];

int main() {
  cin >> N;
  rep3(i, 0, N) rep3(j, 0, N) cin >> A[i][j];

  vector<pair<ll, pair<int, int>>> v;
  rep3(i, 0, N) rep3(j, i + 1, N) v.push_back({ -A[i][j], { i,j } });
  // 辺をコストの大きさが小さい順にソート
  sort(v.begin(), v.end());

  ll ans = 0;
  // 辺のコストの和
  rep3(i, 0, N) rep3(j, i + 1, N) ans += A[i][j];
  // コストが小さい順に取り出す
  fore(p, v) {
    ll c = -p.first;
    int a = p.second.first;
    int b = p.second.second;
    if (A[a][b] == INF) continue;

    // a,bではない経由点を全探索、経由点を通れる必要がある
    rep3(i, 0, N) if (i != a && i != b && A[a][i] != INF && A[i][b] != INF) {
      // A[a][i] + A[i][b]==A[a][b]であれば、A[a][b]の辺は消せる
      // 経由して同じになる時は他の経路経由で到達できるので、その分を差し引くことができる
      if (A[a][i] + A[i][b] == c) {
        ans -= c;
        A[a][b] = A[b][a] = INF;
        break;
      // 経由してcより小さくなる場合は条件を満たさない
      } else if (A[a][i] + A[i][b] < c) {
        printf("-1\n");
        return 0;
      }
    }
  }
  cout << ans << endl;
  return 0;
}

// 3
// 0 1 2
// 1 0 1
// 2 1 0

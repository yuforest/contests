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
// #include <atcoder/all>
// using namespace atcoder;

// 競プロerはrepマクロが大好き
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep3(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(), (x).end()

// 無くても困らない
#define INFTY (1 << 30)

// 浮動小数点の誤差を考慮した等式ですが、使わずに済むなら使わない方が確実です
#define EPS (1e-7)
#define equal(a, b) (fabs((a) - (b)) < EPS)

// DPやlong longの最大値最小値更新で重宝します。
template <typename T>
inline bool chmax(T &a, T b) {
  return ((a < b) ? (a = b, true) : (false));
}
template <typename T>
inline bool chmin(T &a, T b) {
  return ((a > b) ? (a = b, true) : (false));
}

int ans[2010];
int N, M;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int N;
  cin >> N;
  vector<pair<int, int>> A(N);
  rep(i, N) cin >> A[i].first >> A[i].second;

  // 各点をセットに挿入
  set<pair<int, int>> st;
  rep(i, N) st.insert(A[i]);

  ll ans = 0;
  // N^4だと間に合わないので二点を取得し、その二点に対して正方形を作れるような二点が
  // 存在するかということを探索する
  rep(i, N) rep(j, N) {
    if (i == j) continue;

    int dx = A[i].first - A[j].first;
    int dy = A[i].second - A[j].second;

    // iから見て正方形を作れるような座標を探索
    if (st.find({A[i].first - dy, A[i].second + dx}) == st.end()) continue;
    // jから見て正方形を作れるような座標を探索
    if (st.find({A[j].first - dy, A[j].second + dx}) == st.end()) continue;

    ll cur = ll(dx) * dx + ll(dy) * dy;
    ans = max(ans, cur);
  }
  cout << ans << "\n";
  return 0;
}
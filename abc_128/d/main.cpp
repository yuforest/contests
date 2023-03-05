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

int main() {
  ll N, K;
  cin >> N >> K;
  vl V(N);
  rep(i, N) cin >> V[i];

  int ans = 0;
  // 左からL個、右からR個を全探索
  rep(L, N + 1) rep(R, N + 1) {
    // 合計はN個以下
    if (N < L + R) continue;
    // 残り、いらない宝石を戻す回数
    int rest = K - (L + R);
    // 戻す回数が負ならダメ
    if (rest < 0) continue;

    vector<int> has;
    // 左からL個、右からR個を取り出す
    rep(i, L) has.push_back(V[i]);
    rep(i, R) has.push_back(V[N - 1 - i]);
    // 昇順にソート
    sort(all(has));

    int n = has.size();
    int sm = 0;
    // 合計計算
    fore(i, has) sm += i;
    // 最大rest回だけ、負の宝石を戻す
    rep(i, min(rest, n)) {
      if (0 < has[i]) break;
      sm -= has[i];
    }
    // 答え更新
    chmax(ans, sm);
  }
  cout << ans << endl;
}
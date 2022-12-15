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

int main() {
  ll N, M;
  cin >> N >> M;
  vl A(N);
  rep(i, N) cin >> A[i];
  vl B(M), C(M);
  vvl I(M, vl());
  rep(i, M) {
    cin >> B[i] >> C[i];
    rep(j, C[i]) {
      ll val;
      cin >> val;
      val--;
      I[i].push_back(val);
    }
  }
  debug(A);
  debug(B);
  debug(C);
  ll ans = 0;
  // bit全探索
  rep(i, (1 << N)) {
    // 今の状態数のスコア
    ll current = 0;
    // アイドルの数
    ll count = 0;
    // 今の状態数が選んでいるアイドルの基礎値を足す
    rep3(j, 0, N) {
      if (i & (1 << j)) {
        current += A[j];
        count++;
      }
    }
    if (count != 9) continue;
    debug(bitset<20>(i));
    debug(current);
    // コンボボーナスを計算する
    rep(j, M) {
      // 必要なアイドルのカウント
      ll count = 0;
      rep(k, C[j]) {
        debug(I[j][k]);
        if (i & (1 << I[j][k])) count++;
      }
      if (count >= 3) current += B[j];
    }
    chmax(ans, current);
  }
  cout << ans << endl;
  return 0;
}
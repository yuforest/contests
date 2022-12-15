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
  int n,m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  // 使える数はこの集合に入れておく
  // 使える区間の最小値を求める問題は
  // setを使って使える数を管理して、
  // 使えない数ができた時点で消す
  // 使える数が増えた時点で追加するといった操作をすることで
  // *(st.begin())などを使って使える数の最小値を定数時間で
  // 取ってくることができる
  set<int> st;
  // 0からNまでの数を入れる
  for (int i = 0; i <= n; i++) {
    st.insert(i);
  }
  int ans = n;
  vector<int> cnt(n,0);
  // 先頭からM個の数の登場回数をカウント
  for (int i = 0; i < m; i++) {
    cnt[a[i]]++;
    // 登場した数は消す
    if (cnt[a[i]] == 1) st.erase(a[i]);
  }
  // 初期状態で使える数の最小値をセット
  ans = min(ans, *(st.begin()));
  for (int i = m; i < n; i++) {
    // スライドするので現在の区間に入っている数のカウントを増減させる
    cnt[a[i]]++; cnt[a[i-m]]--;
    // 消えた数と追加された数が同じではない場合
    if (a[i] != a[i-m]) {
      // 増えた数が1になった時点で使えなくなる
      if (cnt[a[i]] == 1) st.erase(a[i]);
      // 減った数が0になった時点で使えるようになる
      if (cnt[a[i-m]] == 0) st.insert(a[i-m]);
    }
    // 現在の最小値より使える数の中の最小値が小さければ更新する
    ans = min(ans, *(st.begin()));
  }
  cout << ans << endl;
  return 0;
}
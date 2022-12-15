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
  string S;
  cin >> S;
  ll N = S.size();
  set<ll> st;
  rep3(i, 2, N-2) {
    if (S[i] == S[i+1]) {
      st.insert(i);
    }
  }
  debug(st);
  ll ans = 0;
  // 前2つの文字列が同じなら変更する
  rep3(i, 0, N-2) {
    // 切り替わるタイミングならスキップ
    if (st.find(i+1) != st.end() || st.find(i+2) != st.end()) continue;
    if (S[i] == S[i+1] && S[i+2] != S[i]) {
      S[i+2] = S[i];
      ans++;
    }
  }
  debug(S);
  debug(ans);
  vl elements;
  elements.push_back(0);
  ll tmp = 0;
  char current = '-';
  // 変更後の要素数をカウント
  for(int i = N-1; i >= 0; i--) {
    if (current != S[i]) {
      current = S[i];
      if (tmp > 1) {
        elements.push_back(tmp);
      }
      tmp = 1;
    } else {
      tmp++;
    }
  }
  if (tmp > 1) {
    elements.push_back(tmp);
  }
  debug(elements);
  // 累積和を作る
  rep3(i, 1, elements.size()) {
    elements[i] += elements[i-1];
  }
  debug(elements);
  rep(i, elements.size()-1) {
    ans += elements[i];
  }
  cout << ans << endl;

  return 0;
}

// aaerrorrccurred

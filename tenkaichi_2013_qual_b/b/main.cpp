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
using pll = pair<ll, ll>;

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
  ll Q, L;
  cin >> Q >> L;
  stack<pair<ll, ll>> st;
  ll count = 0;
  rep(i, Q) {
    string q;
    cin >> q;
    if (q == "Push") {
      ll N, M;
      cin >> N >> M;
      if (count + N > L) {
        cout << "FULL" << endl;
        return 0;
      }
      count += N;
      if (!st.empty() && st.top().first == M) {
        auto val = st.top();
        st.pop();
        val.second += N;
        st.push(val);
      } else {
        st.push({M, N});
      }
    } else if (q == "Pop") {
      ll N;
      cin >> N;
      if (count < N) {
        cout << "EMPTY" << endl;
        return 0;
      }
      while(N > 0) {
        auto val = st.top();
        st.pop();
        // Nが取り出した値以上の場合はスタックの値を捨てる
        if (N >= val.second) {
          count -= val.second;
          N -= val.second;
        } else {
          // Nが取り出した値より小さい場合はその分差し引いて再度stackにpush
          val.second -= N;
          count -= N;
          N = 0;
          st.push(val);
        }
      }
    } else if (q == "Top") {
      if (st.empty()) {
        cout << "EMPTY" << endl;
        return 0;
      }
      cout << st.top().first << endl;
    } else if (q == "Size") {
      cout << count << endl;
    }
    debug(st);
  }
  cout << "SAFE" << endl;
  return 0;
}
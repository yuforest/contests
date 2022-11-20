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
  ll N;
  cin >> N;
  ll changed = -1;
  vl A(N);
  rep(i, N) cin >> A[i];
  ll Q;
  cin >> Q;
  set<ll> st;
  vl B(N, 0);
  rep(i, Q) {
    ll query;
    cin >> query;
    ll iq, xq;
    if (query == 1) {
      cin >> xq;
      changed = xq;
      st.clear();
    } else if (query == 2) {
      cin >> iq >> xq;
      iq--;
      // この時値が既に入っている
      if (st.find(iq) != st.end()) {
        B[iq] += xq;
      } else {
        // リセットされた
        B[iq] = xq;
      }
      st.insert(iq);
    } else if (query == 3) {
      cin >> iq;
      iq--;
      if (changed == -1) {
        if (st.find(iq) != st.end()) {
          cout << A[iq] + B[iq] << endl;
        } else {
          // リセットされた
          cout << A[iq] << endl;
        }
      } else {
        if (st.find(iq) != st.end()) {
          cout << changed + B[iq] << endl;
        } else {
          // リセットされた
          cout << changed << endl;
        }
      }
    }
  }
  return 0;
}
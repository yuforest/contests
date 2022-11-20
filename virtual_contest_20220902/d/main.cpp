// ここは競プロではサボりがちです
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

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

// map<int, int> mp;
// long long mod = 1000000007;
// vector<ll> G[1 << 18];

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

template<typename T>T min(const vector<T>&v){return *min_element(v.begin(),v.end());}
template<typename T>T max(const vector<T>&v){return *max_element(v.begin(),v.end());}
template<typename T>T acc(const vector<T>&v){return accumulate(v.begin(),v.end(),T(0));};
template<typename T>T reverse(const T &v){return T(v.rbegin(),v.rend());};

// DPやlong longの最大値最小値更新で重宝します。
template <typename T>
inline bool chmax(T &a, T b) {
  return ((a < b) ? (a = b, true) : (false));
}
template <typename T>
inline bool chmin(T &a, T b) {
  return ((a > b) ? (a = b, true) : (false));
}

const ll INF = 1e18;

vector<ll>dx={1,-1,0,0,1,1,-1,-1};
vector<ll>dy={0,0,1,-1,1,-1,1,-1};

int main() {
  ll N, M;
  cin >> N >> M;
  vl A(N+1);
  vl B(M+1, -INF);
  vl C(N+M+1);
  rep(i, N+1) cin >> A[i];
  rep(i, N+M+1) cin >> C[i];
  rep(b, M+1) {
    rep(a, N+1) {
      ll c = a + b;
      if (B[b] == -INF) {
        if (A[a] == 0) continue;
        // A[a] * B[b] = C[c]
        B[b] = C[c] / A[a];
      } else {
        C[c] -= B[b] * A[a];
      }
    }
  }
  rep(i, M+1) {
    if (i) cout << " ";
    cout << B[i];
  }
  cout << endl;
}


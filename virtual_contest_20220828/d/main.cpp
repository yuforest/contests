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
  int A[M], B[M], C[M];
  rep(i, M) {
    cin >> A[i] >> B[i] >> C[i];
    A[i]--;
    B[i]--;
  }
  vector<int> v(M);
  iota(v.begin(), v.end(), 0); // v に 0, 1, ... M-1 を設定
  sort(v.begin(), v.end(), [&](int x, int y) {
    return C[x] < C[y];
  });
  // [0, 1, 2]
  // [2, 1, 0]
  atcoder::dsu uf(N);
  long long ans = 0;
  for (int i = 0; i < M; i++) {
    int current_index = v[i];
    if (uf.same(A[current_index], B[current_index]) == false) {
      uf.merge(A[current_index], B[current_index]);
      continue;
    }
    if (C[current_index] >= 0) {
      ans += C[current_index];
    }
  }
  cout << ans << endl;
}


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
#define per3(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define per(i, b) per3(i, 0, b)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(), (x).end()

// 無くても困らない
#define INFTY (1 << 30)

// 浮動小数点の誤差を考慮した等式ですが、使わずに済むなら使わない方が確実です
#define EPS (1e-7)#define equal(a, b) (fabs((a) - (b)) < EPS)

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

class union_find {
private:
  int N;
  vector<int> par;
public:
  union_find() : N(0), par() {}
  union_find(int N_) : N(N_) {
    par.resize(N);
    for (int i = 0; i < N; ++i) {
      par[i] = i;
    }
  }
  int root(int x) {
    if (x == par[x]) return x;
    return par[x] = root(par[x]);
  }
  void link(int x, int y) {
    par[root(x)] = root(y);
  }
  bool connected(int x, int y) {
    return root(x) == root(y);
  }
};
int main() {
  int N, Q;
  cin >> N >> Q;
  vector<int> T(Q), X(Q), Y(Q), V(Q);
  for (int i = 0; i < Q; ++i) {
    cin >> T[i] >> X[i] >> Y[i] >> V[i];
    --X[i], --Y[i];
  }
  // 和の値を保存しておく
  vector<int> sum(N - 1, 0);
  for (int i = 0; i < Q; ++i) {
    if (T[i] == 0) {
      sum[X[i]] = V[i];
    }
  }
  debug(sum);
  // 隣り合う要素の差を保存しておく
  vector<long long> potential(N, 0);
  for (int i = 0; i < N - 1; ++i) {
    potential[i + 1] = sum[i] - potential[i];
  }
  debug(potential);
  union_find uf(N);
  for (int i = 0; i < Q; ++i) {
    // 隣接要素をつなげる
    if (T[i] == 0) {
      uf.link(X[i], Y[i]);
    }
    if (T[i] == 1) {
      // 繋がっていなければ不定
      if (!uf.connected(X[i], Y[i])) {
        cout << "Ambiguous" << endl;
      }
      // インデックスの和が偶数なら、つまり偶数個離れていれば
      else if ((X[i] + Y[i]) % 2 == 0) {
        cout << V[i] + (potential[Y[i]] - potential[X[i]]) << endl;
      }
      // 奇数個離れていれば
      else {
        cout << (potential[X[i]] + potential[Y[i]]) - V[i] << endl;
      }
    }
  }
  return 0;
}
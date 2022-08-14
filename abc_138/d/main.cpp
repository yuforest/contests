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

int ans[200010];
int used[200010];
vector<int> add(200010, 0);

void dfs(int pos, int current) {
  current += add[pos];
  ans[pos] = current;
  used[pos] = true;
	for (int i : G[pos]) {
    if (!used[i]) dfs(i, current);
	}
}

int main() {
  int N, Q;
  cin >> N >> Q;
  int a[N-1], b[N-1], p[N-1], x[N-1];
  rep(i, N-1) {
    cin >> a[i] >> b[i];
    G[a[i]].push_back(b[i]);
    G[b[i]].push_back(a[i]);
  }

  rep(i, Q) {
    cin >> p[i] >> x[i];
    add[p[i]] += x[i];
  }

  dfs(1, 0);
  rep3(i, 1, N+1) {
    cout << ans[i];
    if (i != N) {
      cout << " ";
    } else {
      cout << endl;
    }
  }
  return 0;
}
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

int ans[2010];
int N, M;

int main() {

  int N, M;
  cin >> N >> M;
  vl P(N);
  rep(i, N) cin >> P[i];
  // 0も選べるようにする
  // これによって0,1,2,3,4の個数の和を作ることができる
  P.push_back(0);
  vl S;
  // 和を作ることで計算量をN^2まで落とす
  for (int i = 0; i < P.size(); ++i)
    for (int j = 0; j < P.size(); ++j)
      S.push_back(P[i] + P[j]);
  // O(N^2logN)
  sort(S.begin(), S.end());

  long long res = 0;
  // aを固定する
  // aを動かして行ったときの計算量：O(N^2logN)
  for (long long a : S) {
    // 初めてM-aを超えるイテレータを探す
    auto it = upper_bound(S.begin(), S.end(), M-a);
    // 最初だとそれより小さいものが存在しないということ
    if (it == S.begin()) continue;
    --it;
    // 最大値更新
    res = max(res, a + *it);
  }
  cout << res << endl;
  return 0;
}
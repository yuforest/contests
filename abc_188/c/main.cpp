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
  int N;
  cin >> N;
  vi A(pow(2, N));
  rep(i, pow(2, N)) cin >> A[i];
  debug(A);
  vi A_copy = A;
  if (N == 1) {
    if (A[0] > A[1]) {
      cout << 2 << endl;
    } else {
      cout << 1 << endl;
    }
    return 0;
  }
  while(true) {
    vi tmp;
    rep(i, A_copy.size() / 2) {
      int first = 2 * i;
      int second = 2 * i + 1;
      if (A_copy[first] > A_copy[second]) {
        tmp.push_back(A_copy[first]);
      } else {
        tmp.push_back(A_copy[second]);
      }
    }
    A_copy = tmp;
    debug(A_copy);
    if (A_copy.size() == 2) break;
  }
  int val = min(A_copy[0], A_copy[1]);
  auto itr = find(A.begin(), A.end(), val);
  int index = itr - A.begin();
  cout << index + 1 << endl;
  return 0;
}
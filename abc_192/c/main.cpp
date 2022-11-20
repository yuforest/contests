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
int N, K;

vector<int> vectorize(int N) {
  vi res;
  while(N > 0) {
    int remain = N % 10;
    res.push_back(remain);
    N /= 10;
  }
  return res;
}

int main() {
  cin >> N >> K;
  rep(i, K) {
    vi array = vectorize(N);
    // 大きい順
    sort(array.begin(), array.end(), greater<int>());
    int g1 = 0;
    for(int j = 0; j < array.size(); j++) {
      g1 *= 10;
      g1 += array[j];
    }
    debug(g1);
    // 小さい順
    sort(array.begin(), array.end());
    int g2 = 0;
    for(int j = 0; j < array.size(); j++) {
      if (j == 0 && array[j] == 0) continue;
      g2 *= 10;
      g2 += array[j];
    }
    debug(g2);
    N = g1 - g2;
  }
  cout << N << endl;

  return 0;
}

// これだけシンプルに描ける
// int N, K;
// //---------------------------------------------------------------------------------------------------
// int f(int x) {
//   string s = to_string(x);
//   sort(all(s));

//   int g2 = stoi(s);

//   sort(all(s), greater<char>());

//   int g1 = stoi(s);

//   return g1 - g2;
// }
// //---------------------------------------------------------------------------------------------------
// int main() {
//   cin >> N >> K;
//   int a = N;
//   rep3(i, 0, K) a = f(a);
//   cout << a << endl;
//   return 0
// }
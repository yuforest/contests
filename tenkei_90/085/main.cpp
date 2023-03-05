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

int main() {
  // Step #1. Input
  long long K;
  cin >> K;

  // Step #2. Enumerate Divisors
  // 約数列挙
  vector<long long> vec;
  // √Kで行うことができる
  for (long long i = 1; i * i <= K; i++) {
    if (K % i != 0LL) continue;
    vec.push_back(i);
    // 同じでなければ反対も入れる
    if (i != K / i) vec.push_back(K / i);
  }
  sort(vec.begin(), vec.end());
  debug(vec);

  // Step #3. Brute Force
  // 約数に対して工夫した全探索を行う
  // 約数^3探索すれば良いが最大6720程度あるのでTLEする
  // c = K/(a*b)なので一意にさだまる
  long long Answer = 0;
  for (int i = 0; i < vec.size(); i++) {
    // bはa以上である必要がある
    for (int j = i; j < vec.size(); j++) {
      long long a = vec[i], b = vec[j], c = 0;
      // このときa*bがkより大きいので実現不可能
      if ((K / a) < b) continue;
      // 割ったあまりが0でなければcontinue
      if (K % (a * b) != 0LL) continue;
      // cを求める
      c = K / (vec[i] * vec[j]);
      // cがb以上なら成り立つ
      if (b <= c) Answer += 1;
    }
  }

  // Step #4. Output
  cout << Answer << endl;
  return 0;
}
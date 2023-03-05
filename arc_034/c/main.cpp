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
  int a, b, m = 1000000007, i, j;
  long long ans = 1;
  map <int, int> mp;
  map <int, int>::iterator it;

  scanf("%d %d", &a, &b);
  // A!の約数であり、かつB!の倍数でもあるような数とは
  // (A!/B!)の約数にB!を掛けたものである
  // (A!/B!)の約数になるのは答えはA!を超えてはいけないからである
  // (A!/B!)の約数の数を求めるためには素因数分解をしてその組み合わせの通り数を求めれば良い
  // A!/B! = A*...B*..1/B*..*1 = A*..*(B+1)
  // この個々の数字に対して素因数分解をすればよい
  // b+1からaまで
  // ここは100程度
  for (i = b + 1; i <= a; i++) {
    int x = i;
    // xを素因数分解する,√xまで見れば十分
    // ここはO(√x)程度の計算量
    for (j = 2; j * j <= x; j++) {
      while (x % j == 0) {
        mp[j]++;
        x /= j;
      }
    }
    // 残った数字を記録
    if (x > 1) mp[x]++;
  }

  // その素数を選ぶか選ばないかで指数+1通りの組み合わせをかけて答えの通り数を計算する
  for (it = mp.begin(); it != mp.end(); it++) ans = ans * (it->second + 1) % m;
  printf("%lld\n", ans);

  return 0;
}
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

// 素因数分解して、その素因数の配列を返す
// 計算量はO(√N)
vector<int> enumPrimeOnly(int n) {
  int x = n;
  vector<int> res;
  for (int i = 2; 1LL * i * i <= n; i++) if (x % i == 0) {
    res.push_back(i);
    // 割り切れなくなるまで割る
    while (x % i == 0) x /= i;
  }
  // 最後に余ったら素数なのでそれもpush
  if (x > 1) res.push_back(x);
  return res;
}
vector<int> Era(int n) {
  vector<int> res;
  vector<bool> isprime(n, true);  // ふるい
  isprime[0] = false;
  isprime[1] = false;
  for (int i = 2; i < n; ++i) {
    if (isprime[i]) {
      res.push_back(i);
      // 調和級数
      for (int j = i*2; j < n; j += i) {
        isprime[j] = false;
      }
    }
  }
  return res;
}

int main() {
  ll N, M;
  cin >> N >> M;
  string S[N];
  rep(i, N) cin >> S[i];
  // 「二人の正解数が等しい可能性がない」ことは、「二人の解答が異なる問題が奇数個ある」ことと同値
  // 二人の解答が異なるとき、二人の 1 と解答した問題数の差の偶奇は、その問題が無かった場合から反転
  // 2人の回答が異なる場合はどちらかが1になっている
  // よって、「二人の解答が異なる問題が奇数個ある」ことは、「二人の 1 と解答した問題数の偶奇が異なる」ことと同値
  // 異なる回答が偶数回なら1と回答した問題数の偶奇は同じになるが、奇数個の場合は異なるといえる
  // したがって、「二人の正解数が等しい可能性がない」ことが、「二人の 1 と解答した問題数の偶奇が異なる」ことと同値
  // 1 と解答した問題数が奇数の生徒の人数と偶数の生徒の人数の積が答え

  ll even = 0;
  ll odd = 0;
  rep(i, N) {
    int count = 0;
    rep(j, M) {
      if (S[i][j] == '1') count++;
    }
    if (count % 2 == 0) even++;
    else odd++;
  }
  debug(even);
  debug(odd);
  cout << even * odd << endl;
  return 0;
}
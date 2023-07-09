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

int popcount(long long N)
{
  int ans = 0;
  while (N > 0) {
    ans++;
    // 最下位のbitのフラグを落とす
    N ^= (N & -N);
  }
  return ans;
}

long long solve(long long N)
{
  debug(bitset<64>(N));
  if (N < 7) return -1;

  int k = popcount(N);
  // 1が3個以上ある場合は上位から3つを残したものが答え
  if (k >= 3) {
    while (k > 3) {
      k--;
      // これで最下位のbitのフラグを落とす
      N ^= (N & -N);
    }
    return N;
    // 1がちょうど1つの場合は3つ右シフトして、最下位のbitのフラグを落とす
    // その後7を残った分だけ左シフトして、最上位より小さいところのbitを3つ立てる
  } else if (k == 1) return N / 8 * 7;
  else {
    // 1がちょうど2つの場合は、
    // 下位の1が2以下であれば、2つの1を共に0にして、上位の1の直下に1を3つ並べたものが答え(下位のbitを落として1を2つ作れないため)
    // 下位の1が4以上であれば、それを0にして直下に1を2個連続で並べたものが答え
    // (N ^ (N & -N))はNの最下位bitを落としたもの
    // (N & -N) / 4 * 3はNの最下位bitを2つ右シフトして、残った分だけ3を左シフトする
    if ((N & -N) <= 2) return N / 8 * 7;
    else return (N ^ (N & -N)) + (N & -N) / 4 * 3;
  }
}

int main()
{
  int i, j, k, l, T;
  long long N;
  scanf("%d", &T);
  while (T--) {
    scanf("%lld", &N);
    printf("%lld\n", solve(N));
  }
  fflush(stdout);
  return 0;
}
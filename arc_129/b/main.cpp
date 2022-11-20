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

int ans[2010];
int dx[4] = { 0, 1, 0, -1 }, dy[4] = { -1, 0, 1, 0 };

int main() {
  ll N;
  cin >> N;
  ll L[N], R[N];
  ll r_min = 1e9, l_max=0;
  // dist(l, r, x) = max(0, l-x, x-r)と書き直すことができる
  // よって最小化すべき関数はmax(0, L1 - x, x - R1, L2 - x, x - R2, ..., Lk - x, x - Rk)
  // ここでAk = max(L1, L2,..,Lk), Bk = min(R1, R2,..,Rk)とすると
  // 目的関数はmax(0, Ak - x, x - Bk)と書き直すことができる
  // Ak <= Bkの時はx = Akとすることで答えを0にすることができる
  rep(i, N) {
    cin >> L[i] >> R[i];
    // 右の最小値をとっておく
    chmin(r_min, R[i]);
    // 左の最大値をとっておく
    chmax(l_max, L[i]);
    // 現在までのRで最も小さいものと現在までのLで最も大きいものが、
    // 最もコストが高くなる
    // これを最小化するのはその間にある数字である
    // 二つの数字の差が偶数なら、そのまま2で割ったものがコストになり、
    // 奇数なら2で割って繰り上げればそれがコストになる(遠い方は近い方よりも1コストがかかる)
    // つまり奇数でも偶数でも1を足して2で割れば、偶数は1足す前と変わらす、奇数なら繰り上がり、
    // 解が得られる
    // 右シフトの操作は2で割って切り捨てるのと同じ
    // cout << max(0LL, (b-a+1)>>1) << endl;
    cout << max(0LL, (l_max-r_min+1)/2) << endl;
  }
  return 0;
}
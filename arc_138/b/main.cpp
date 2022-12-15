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
int dx[4] = { 0, 1, 0, -1 }, dy[4] = { -1, 0, 1, 0 };

int n, a[200010], t=0, l=1;
int main() {
  scanf("%d", &n);
  for (int i=1; i<=n; i++) scanf("%d", &a[i]);
  while (1) {
    // lとnを端から狭めていく
    // lがnを追い越したら終了
    if (l>n) break;
    debug(l);
    debug(n);
    debug(t);
    debug(a[l]^t);
    // 数列の最初には1つのみ0が存在する
    // a[n]とtが同じならnを左に動かす
    // 例えば全て0なら最後までnが減り続ける
    // 操作Bの逆操作に当たりそう
    // 最初の数回の操作では1のうち最も右にあるもののインデックスを探索する
    if (a[n]^t==0) n--;
    // a[l]とtが異なる場合達成できない
    // tは最初0
    // 反転することで0は1に、1は0に反転する
    // よってこれまで反転回数の偶奇が同じ時に0だったものは1に、
    // 1だったものは0に変化する
    // 0,2,4,6,8...と1,3,5,7...は同じグループだと言えそう
    else if (a[l]^t==1) return puts("No"), 0;
    // それ以外の時はtの値を反転させ、lを増やす
    // これが反転を表していそう
    // lとtが同じ場合
    else t^=1, l++;
  }
  puts("Yes");
  return 0;
}
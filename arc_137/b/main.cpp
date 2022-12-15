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
  int n;cin>>n;
  vi a(n);
  rep(i, n) cin >> a[i];
  // 1 の個数を最小/最大で何個にできるか，は簡単に求まる
  // 連続部分列であって，1 の個数 - 0 の個数が最小/最大になるものを求めれば良い
  // 最小と最大の間はすべて達成することができる
  // 1の個数-0の個数の最大値、最小値を求め、その区間に含まれる整数の個数を出力すればいい
  int mn=0,mx=0,cur=0,x=0,y=0;
  // curはrを固定して探索しているという認識
  // そしてlの最大値、最小値を更新しながら探索している
  // 累積和的な考え方としゃくとり的な考え方
  // rを固定してlの最大値、最小値を保持しておくことで
  // r-lの最小値(現在-過去の最大)、最大値(現在-過去の最小)を求めることができる
  // 計算量はO(N)になる
  // rとlの区間はrが右に進むほどlの取りうる範囲は増えるし、rが少ないうちはlが取りうる値は少ない
  // rを右に動かしながら、lの最大と最小を更新していくという操作が肝
  // やりたいことはシンプルで、最大のスコアと最小のスコアを求めて、
  // 最大-最小+1が取りうる値の数になるということ
  rep(i,n){
    // 最初から現在の項までの連続部分列の1の出現回数のカウント
    if(a[i]==0)cur--;
    else cur++;
    debug(cur);
    debug(x);
    debug(y);
    debug(mn);
    debug(mx);
    // xの最小値更新
    // 現在までの1の出現回数から、これまでの項までの1の最大出現回数を引いた値の最小値
    // 現在の項から1が最も多く出現している箇所までの区間は1が最も少なく出現する区間であるということ
    // 最後まで操作を終えた後のこの区間を選ぶとフリップした後の1の出現回数は一番少なくなる
    // mnが0より大きいときmnまでの区間を反転することで1の出現回数を減らすことができる
    // mnが0より小さいときmnまでの区間を反転すると、1の出現回数が増えてしまう
    // 最初から現在までで最も多く1が出現したところを記録するのがmx
    // この区間には0がたくさんあって欲しい
    // この区間にある1の個数-0の個数は小さくあって欲しい
    chmin(x,cur-mx);
    // yの最大値更新
    // 現在までの1の出現回数から、これまでの項までの1の最小出現回数を引いた値の最大値
    // 現在の項から1が最も少なく出現している箇所までの区間は1が最も多く出現する区間と同義
    // 最後まで操作を終えた後のこの区間を選ぶとフリップした後の1の出現回数は一番多くなる
    // mnが0より小さいときその区間までに0の個数の方が多いということなので、mnまでの区間を反転すると大きくなる
    // 逆に0より大きい時その区間までに1の個数の方が多いということなので、mnまでを反転するとcurより小さくなる
    // 最初から現在までで最も多く0が出現したところを記録するのがmn
    // この区間には1がたくさんあって欲しい
    // この区間にある1の個数-0の個数は大きくあって欲しい
    chmax(y,cur-mn);
    // ここでフリップするのはmn、mxまでであり
    // その操作をおこなった時のスコアの最小値、最大値を記録する変数がx、yとなっている

    // これまでの項までの1の最小出現回数更新
    // つまりlの最小値を更新
    chmin(mn,cur);
    // これまでの項までの1の最大出現回数更新
    // つまりlの最大値を更新
    chmax(mx,cur);
  }
  // 1ずつしか変化しないので最大の出現回数-最小の出現回数+1が求める答えとなる
  // xが0を反転できる最大値に等しい、yは1を反転できる最大値に等しい
  cout << y-x+1 << endl;

  return 0;
}
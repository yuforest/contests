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

int main() {
  // B の連続部分列 BL,BL+1,…,BRのうち、最大値が X, 最小値が Y となるものは何個あるか。
  // ただし B の要素は Y 以上 X 以下である。
  // つまりB の連続部分列 BL,BL+1,…,BRのうち、X,Y がともに含まれる列は何個あるか。
  // という問題を線形時間で解ければよい
  // 入力
  int N, X, Y;
  cin>>N>>X>>Y;
  vector<int> a(N);
  for(int i = 0; i < N; ++i) cin>>a[i];
  // 1. 区間[L,R]の中にX,Yがそれぞれ1つ以上存在する
  // 2. 区間[L,R]の中にY未満の要素やXより大きい要素が存在しない
  // 1. 区間[1,R]の中で最も右にあるX,Yの位置をposX,posYとしてL<=min(posX,posY)と同値
  // 2. 区間[1,R]の中で最も右にある「Y未満またはXより大きい要素」の位置をBとして、B<Lであることと同値
  int posX{-1}, posY{-1}, B{-1};
  long long res{};
  // Rごとに条件を満たすLの個数を求める
  for(int i = 0; i < N; ++i) {
    // それぞれ位置を更新
    if(a[i] == X) posX = i;
    if(a[i] == Y) posY = i;
    if(a[i] < Y || X < a[i]) B = i;
    debug(posX);
    debug(posY);
    debug(B);
    // posX,posYの小さい方がLとしての条件を満たすので1からmin(posX, posY)個までが条件1を満たす
    // その中に「Y未満またはXより大きい要素」があれば条件を満たさないので
    // 位置を保存しておいて1からBまではLとしての条件を満たさないので引く
    // Bは最初-1にしておいてmin(posX, posY)が0であってもBが-1なので1つは条件を満たす
    debug(max(0, min(posX, posY) - B));
    res += max(0, min(posX, posY) - B);
  }
  cout<<res<<endl;
  return 0;
}
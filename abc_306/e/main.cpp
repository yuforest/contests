// 標準ライブラリを全て読み込む
// 本書では細かく書きませんが、下記リンクが参考になります
// https://atcoder.jp/contests/apg4b/tasks/APG4b_af
#include <bits/stdc++.h>
// stdのstd::cinのような書き方ではなくcinと書けば良くなる
using namespace std;

// デバッグ用マクロ
// 本書では細かく書きませんが、下記リンクが参考になります
// https://naskya.net/post/0002/
#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

// データ構造の省略
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
// using pii = pair<int, int>;

// modの計算
long long mod1 = 1000000007;
long long mod2 = 998244353;

// 隣接グラフ(1 << 18は2^18で262144となる)
vector<ll> G[1 << 18];
// vector<ll> rG[1 << 18];

// ACL(AtCoder Library)、普段はコメントアウトしてある
#include <atcoder/all>
using namespace atcoder;

// repマクロ
// 0からn-1まで
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
// aからb−1まで
#define rep3(i,a,b) for(int i=a;i<b;i++)
// n-1から0まで
#define per(i, n) for (int i = int(n) - 1; i >= int(0); i--)
// b-1からaまで
#define per3(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
// 範囲for文の省略
#define fore(i,a) for(auto &i:a)
// sort(A.begin(), A.end())をsort(all(A))のように書けます
#define all(x) (x).begin(), (x).end()

// 最大値と最小値の更新
// 返り値は更新した場合はtrue、そうでなければfalse
template <typename T>
inline bool chmax(T &a, T b) {
  return ((a < b) ? (a = b, true) : (false));
}
template <typename T>
inline bool chmin(T &a, T b) {
  return ((a > b) ? (a = b, true) : (false));
}

int k;
multiset<int> x,y;
long long s;
void balance(){
  // xのサイズがk以上になるまでyの最大値をxに移動する
  while(x.size()<k){
    auto iy=y.end();iy--;
    x.insert((*iy));
    s+=(*iy);
    y.erase(iy);
  }
  // どちらも空なら何もしない
  if(x.empty() || y.empty()){return;}
  // xの最小値<yの最大値が満たされる限りこれらを交換する
  while(1){
    auto ix=x.begin();
    auto iy=y.end();iy--;
    int ex=(*ix);
    int ey=(*iy);
    if(ex >= ey){break;}
    s+=(ey-ex);
    x.erase(ix);
    y.erase(iy);
    x.insert(ey);
    y.insert(ex);
  }
}

void add(int v){
  // yに追加する
  y.insert(v);
  balance();
}

void erase(int v){
  // xの中からvを見つけたら削除、して合計から引く
  // そうでなければyの中からvを見つけて削除
  auto ix=x.find(v);
  if(ix!=x.end()){ s-=v; x.erase(ix); }
  else{ y.erase(y.find(v)); }
  balance();
}

int main(){
  int n;
  cin >> n >> k;
  vector<int> a(n,0);
  // 最初の最大K個を管理する
  for(int i=0;i<k;i++){ x.insert(0); }
  // 残りを管理する
  for(int i=k;i<n;i++){ y.insert(0); }
  s=0;

  int q;
  cin >> q;
  while(q>0){
    q--;
    int p,w;
    cin >> p >> w;
    p--;
    // wを追加してバランスする
    add(w);
    // a[p]を削除してバランスする
    erase(a[p]);
    // 配列の値を更新
    a[p]=w;
    cout << s << "\n";
  }
  return 0;
}
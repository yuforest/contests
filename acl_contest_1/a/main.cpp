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
using pii = pair<int, int>;

// modの計算
long long mod1 = 1000000007;
long long mod2 = 998244353;

// 隣接グラフ(1 << 18は2^18で262144となる)
vector<ll> G[1 << 18];

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

int main() {
  int n;
  cin>>n;
  vector<pair<pair<int,int>,int>>p(n);
  rep(i,n) {
    // x座標とy座標を入力
    cin>>p[i].first.first>>p[i].first.second;
    // 頂点の番号を入力
    p[i].second=i;
  }
  // x座標で昇順ソート
  sort(p.begin(),p.end());

  dsu uf(n);
  // 小さい順に取り出すためgreaterを指定、昇順
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
  // 最初のy座標と頂点番号を入れる
  pq.push({1e9,-1});
  // x座標が小さい順に取り出す
  rep(i,n){
    int yi=p[i].first.second;
    int id=p[i].second;
    // priority_queueの一番小さいy座標がyiより大きい場合
    // pushして次の頂点に移る
    // これはx座標は小さいがy座標が大きいため到達不可能
    if(pq.top().first>yi){
      pq.push({yi,id});
      continue;
    }
    // ここまで到達すると言うことは少なくとも一つは到達可能な頂点が存在すると言うこと
    // priority_queueから取り出す
    auto [y,v]=pq.top();
    pq.pop();
    // 連結する
    uf.merge(id,v);
    // 今のy座標より小さいy座標がpriority_queueの中にある限り取り出して連結する
    // これはx座標も,y座標も今の座標より小さいため到達可能
    while(pq.top().first<yi){
      uf.merge(pq.top().second, id);
      pq.pop();
    }
    // 到達可能な頂点のうち最もy座標が小さいものをpriority_queueに入れる
    // これにより次回以降で今の頂点から到達可能な頂点を連結していくことができる
    pq.push({y,v});
  }
  rep(i,n)cout<<uf.size(i)<<endl;
}
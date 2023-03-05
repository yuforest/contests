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
#include <atcoder/all>
using namespace atcoder;

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

int main(){
  // 入力
  int n,m,e;
  cin >> n >> m >> e;
  vector<int> u(e),v(e);
  for(int i=0;i<e;i++){
    cin >> u[i] >> v[i];
    // 0-indexed
    u[i]--;v[i]--;
  }
  // 電線が切れているかどうか
  vector<int> fl(e,1);
  int q;
  cin >> q;
  vector<int> query(q);
  for(auto &nx : query){
    cin >> nx;
    nx--;
    fl[nx]=0;
  }

  dsu uf(n+m);
  vector<int> w(n+m,0);
  // nから(n+m-1)までの箇所に1をセットしておく
  // 発電所を1にしておく
  for(int i=n;i<n+m;i++){w[i]=1;}
  int cur=0;
  // 初期状態を構築=これから切る電線が全て切れている状態を構築
  for(int i=0;i<e;i++){
    // 電線が切れていたらcontinue
    if(fl[i]==0){continue;}
    // 既に繋がっていたらcontinue
    if(uf.same(u[i],v[i])){continue;}

    // 頂点に付いた重みの連結成分についての和を管理するため
    int fu = w[uf.leader(u[i])];
    int fv = w[uf.leader(v[i])];
    // 繋ぐ連結成分の片方にだけ発電所がある場合のみ電気が通っている都市の数が増える
    // 電気が通っていない方の連結成分の数をcurに足す
    // 逆にどちらにも電気が通っていない、どちらにも電気が通っている場合は何もしない
    if(fu==0 && fv==1){cur+=uf.size(u[i]);}
    if(fu==1 && fv==0){cur+=uf.size(v[i]);}
    // 連結する
    uf.merge(u[i],v[i]);
    // 連結成分を代表する頂点に電気が通っていることを示すフラグを立てる
    // fuとfvがどちらも0でない時のみ行われる
    w[uf.leader(u[i])]=max(fu,fv);
  }

  vector<int> res;
  // クエリを逆から見る
  for(int j=q-1;j>=0;j--){
    // 何番目の電線か
    int i=query[j];
    // 先に今の値を入れる、これが電線を切った後の値になる
    res.push_back(cur);
    // 既に繋がってたら無視
    if(uf.same(u[i],v[i])){continue;}
    // 2つの連結成分の通電状況を確認
    int fu=w[uf.leader(u[i])];
    int fv=w[uf.leader(v[i])];
    // どちらかだけ電気が通っている場合
    // 片方のサイズを足す
    if(fu==0 && fv==1){cur+=uf.size(u[i]);}
    if(fu==1 && fv==0){cur+=uf.size(v[i]);}
    uf.merge(u[i],v[i]);
    // 連結後の代表に、どちらにも電気が通っていない場合を除いて
    // 電気を通す
    w[uf.leader(u[i])]=max(fu,fv);
  }

  // 逆向きになっているのをひっくり返して出力
  reverse(res.begin(),res.end());
  for(auto &nx : res){cout << nx << "\n";}
  return 0;
}
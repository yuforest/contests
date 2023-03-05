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
// vector<ll> G[1 << 18];
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

int main(){
  int n,m;
  cin >> n >> m;

  vector<vector<int>>G(n);
  // 入次数を管理する配列
  vector<int>deg(n);
  for(int i=0;i<m;i++){
    int x,y;
    cin >> x >> y;
    x--,y--;
    // xからyへの有向辺を張る
    G[x].push_back(y);
    // yの入次数を1増やす
    deg[y]++;
  }

  vector<int>ans(n);
  queue<int>q;
  int cnt=0;
  // 入次数が0の頂点をキューに入れる
  for(int i=0;i<n;i++)if(deg[i]==0)q.push(i);
  while(!q.empty()){
    // キューに入っている頂点が複数ある場合は、
    // そのグラフはトポロジカルソートできない
    if(q.size()!=1){
      cout << "No" << endl;
      return 0;
    }
    // キューから頂点を取り出す
    int v=q.front();q.pop();
    // 頂点vの番号をcntに更新する
    ans[v]=++cnt;
    // vから出ている頂点vvの入次数を1減らして、
    // 入次数が0だったらキューに入れる
    for(auto vv:G[v]) {
      deg[vv]--;
      if (deg[vv] == 0) q.push(vv);
    }
  }

  cout << "Yes" << endl;
  // 頂点の番号を出力する、i==n-1のときだけ改行する
  for(int i=0;i<n;i++)cout << ans[i] << " \n"[i==n-1];
}
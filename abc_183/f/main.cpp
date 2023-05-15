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

int main() {
  int n,q;
  cin >> n >> q;
  // 各グループのクラスの人数を管理する配列
  vector<map<int,int>> cnt(n);
  for(int i=0;i<n;i++){
    int c;
    cin >> c;
    c--;
    cnt[i][c]=1;
  }

  dsu d(n);
  while(q--){
    int t,x,y;
    cin >> t >> x >> y;
    x--,y--;
    if(t==1){
      x=d.leader(x);
      y=d.leader(y);
      // 親が違うなら併合する
      if(x!=y){
        // マージすると新たな代表元を変える
        int r=d.merge(x,y);
        // xが代表元でなければyが代表元なのでswap
        if(r!=x)swap(x,y);
        // 代表元でない方を代表元に統合する
        // 統合処理には要素数をkとしてO(klogN)かかる
        // 最悪計算量はO(NlogN)
        // しかし集団の大きさは移動ごとに2倍以上になるため、
        // 各生徒について移動が行われる回数はO(logN)回以下
        // 従ってクエリ1についての計算量の合計は高々O(N(logN)^2)になる
        for(auto temp:cnt[y])cnt[x][temp.first]+=temp.second;
      }
    }else{
      // xの代表元のyの人数を出力する
      cout << cnt[d.leader(x)][y] << endl;
    }
  }
}

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
  int N;
  cin >> N;
  map<int,pair<int,int>>mp;
  // 二次元配列
  vector<vector<pair<int,int>>>tmp(N);
  // a1,…,aN​すべての最小公倍数LとLiについて、L!=Liとなる条件を考える
  // 「ある素数pが存在して『aiのpの指数がLのpの指数に等しく、かつajのpの指数が
  // Lのpの指数に等しいようなj(!=i) が存在しない』」
  for(int i = 0; i < N; i++) {
    int m;
    cin >> m;
    // 配列サイズ変更
    tmp[i].resize(m);
    for(int j = 0; j < m; j++) {
      int p,e;
      cin >> p >> e;
      tmp[i][j] = {p,e};
      // その素数のfirstがeと同じならsecondをインクリメント
      // これは最大の指数の個数を数えている
      if(mp[p].first == e) {
        mp[p].second++;
      }
      // eの方が大きければリセットする
      else if(mp[p].first < e) {
        mp[p] = {e,1};
      }
    }
  }
  int ans = 1;
  for(int i = 0; i < N; i++) {
    bool flag = false;
    // i番目の数の素数の指数が最大の指数と一致しており、
    // それが1つしかなければ最大公約数の種類は増える
    for(int j = 0; j < tmp[i].size(); j++) {
      if(mp[tmp[i][j].first] == make_pair(tmp[i][j].second,1)) {
        flag = true;
        break;
      }
    }
    if(flag) {
      ans++;
    }
  }
  // 最大公約数の種類数はNを超えないが例えばN=1の時は超えてしまうことがあるので注意
  // L!=Liとなるiの個数cが分かればそれにL=Liの場合を加えることで
  // 答えが min(c+1,N) と求められる
  cout << min(ans, N) << endl;
}
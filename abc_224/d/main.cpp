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
// vector<ll> G[1 << 18];

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

int main() {
  int m;
  cin >> m;
  vector<int> G[10];
  int u, v;
  for(int i = 1; i <= m; i++){
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  // 9を空の頂点として扱う
  int p; string s = "999999999";
  for(int i = 1; i <= 8; i++){
    cin >> p;
    s[p-1] = i + '0';
  }
  queue<string> Q;
  Q.push(s);
  // 今のパズルの状態と、その状態になるまでの手数
  map<string, int> mp;
  mp[s] = 0;
  // 状態数は9!通りなので、BFSで探索できる(9! = 362880通り)
  // 典型的な考え方として状態数が少ない時はBFSで全探索することができる
  while(Q.size()){
    string s = Q.front(); Q.pop();
    // 9の位置を探す
    for(int i = 1; i <= 9; i++) if(s[i-1] == '9') v = i;
    // 9と隣接するマスを全探索(9は空の頂点)
    for(auto u : G[v]){
      // 9と隣接するマスを入れ替える
      string t = s;
      swap(t[u-1], t[v-1]);
      // 既に状態が出ていたらスルー
      if(mp.count(t)) continue;
      // 今の状態になるまでの手数を記録
      mp[t] = mp[s] + 1;
      // 次の探索候補
      Q.push(t);
    }
  }
  // 実現不可能なら-1を出力
  if(mp.count("123456789") == 0) cout << -1 << endl;
  else cout << mp["123456789"] << endl;
  return 0;
}
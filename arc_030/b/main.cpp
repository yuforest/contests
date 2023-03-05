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
ll h[111];
ll sz[110];

ll solve(ll cur, ll par){
  sz[cur] = h[cur];
  ll ret = 0;
  // 繋がっている頂点を探索
  rep(i, G[cur].size()) {
    // 親の時は探索しない
    if (G[cur][i] == par) continue;
    // 探索の結果を加算
    // これは繋がっている頂点以下で宝石がある
    ret += solve(G[cur][i], cur);
    // 現在の値に子の探索結果を足す、solveで入れた子のszの値を親に伝播していく
    sz[cur] += sz[G[cur][i]];
  }
  // 現在が親の時は数えない
  // 今の頂点から1つ根の方向に戻る経路を足している
  // ここでsz[cur]が0、つまり宝石がない頂点の場合は足されないので
  // その頂点を訪問するカウントをしていないのと同じことになる
  // ある頂点の子に宝石がある場合は、その頂点も訪問する必要がある
  // その判断はdfsで子を探索した時にszに入れた値を親に伝播していき
  // ここでその値が0以上であるかどうかで判断できる
  if(par != -1 && sz[cur]) ret++;
  return ret;
}
int main(){
  // 入力
  ll n, x;
  cin >> n >> x;
  rep(i, n) cin >> h[i];

  // グラフ構築(0-indexed)
  rep(i, n-1) {
    ll a,b;
    cin >> a >> b;
    a--;
    b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  x--;
  // 計算結果は片道分なので2倍すれば良い
  // 根から葉の方向に行く分だけを計算している
  // 最初は親がないので-1にしておく
  cout << solve(x,-1) * 2 << endl;
}

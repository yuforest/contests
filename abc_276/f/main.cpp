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
using mint = modint998244353;
#define M 200000

// Kが1増えた時の差分を考える
// 式に落とし込んでみると見えてくる
int main() {
  int n,x;
  mint d,s,ans;
  cin>>n;
  // ((1≤j≤K−1かつ)Aj=iであるようなjの個数)
  fenwick_tree<mint> fw1(M+1);
  // ((1≤j≤K−1かつ)Aj=iであるようなjの個数)×i
  fenwick_tree<mint> fw2(M+1);
  // K=0の時
  s=0;
  // 差分を計算しながら答えを求めていく
  // 差分の値はfenwick_treeに保存する
  for(int i=0;i<n;i++){
    cin>>x;
    // AKの話+Aiの和
    // x以下にあるもの個数*xがAKの方が大きくなる時
    // それ以上の個数*それぞれの値がAiの方が大きくなる時
    d = fw1.sum(0,x+1)*mint(x) + fw2.sum(x+1,M+1);
    // Kが1増えた時の差分を足していく
    s = s + mint(2)*d + mint(x);
    // (mint(i+1).inv().pow(2))がK^2の部分
    cout<< (s*(mint(i+1).inv().pow(2))).val() <<"\n";
    // xに1を足す
    fw1.add(x,mint(1));
    // xにxを足す
    fw2.add(x,mint(x));
  }
  return 0;
}
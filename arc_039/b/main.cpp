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

// 重複
using mint = modint1000000007;
typedef pair<int,int> P;
template<class T> void chmin(T &a, T b){if(a>b){a=b;}}
template<class T> void chmax(T &a, T b){if(a<b){a=b;}}
int main()
{
  int n,k;
  mint res=1;
  cin >> n >> k;
  // キャンディが割り振る人数よりも多い場合は
  // 均等に割り振れる分は割り振ってあまりをどのように分配数かを考えれば良い
  // つまりNC(N%K)
  if(n<=k){
    // 余りを求める
    k%=n;
    // NC(N%K)を求める
    rep(i,k){
      // NからN-(k-1)までを掛ける
      res*=n-i;
      debug(n-i);
      // 1からkまでで割る
      res/=i+1;
      debug(i+1);
    }
  }else{
    // そうでない時はどのように割り振っても0になるので
    // 重複組み合わせですべての振り分け方を求める
    // NHK = (N+K-1)C(K-1) = (N+K-1)CN
    // これはN個のボールをK-1個の仕切りでどのように分けることができるかの通り数に等しい
    // これらの並べ方は(N+K-1)!だけあるが、仕切りとボール自体は区別しないので
    // (N+K-1)!/K!(N-1) = (N+K-1)C(K-1)となる
    // この場合はキャンディが上のボールに等しいがどちらでも組み合わせの式は等しくなる
    // (N+K-1)CNを計算して解くことができる
    rep(i, k){
      // n+k-1からn+k-1-(k-1)まで掛け合わせる
      res *= n+k-1-i;
      debug(n+k-1-i);
      // 1からkまでで割る
      res /= i+1;
      debug(i+1);
    }
  }
  cout << res.val() << endl;
  return 0;
}



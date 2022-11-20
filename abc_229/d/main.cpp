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
  string s;cin>>s;
  ll k;
  cin>>k;
  ll n=s.size();
  // .の累積和を計算
  // lとrの範囲の間にあるドットをO(1)で計算できるようにするため
  vector<ll>cnt(n+1);
  for(ll i=0;i<=n-1;i++){
    if(s[i]=='.') cnt[i+1] = cnt[i] + 1;
    else cnt[i+1] = cnt[i];
  }
  debug(cnt);
  // しゃくとり法により普通にlとrを全探索するとO(N^2)かかるものがO(N)に削減できる
  // cnt[r] - cnt[l] で s[l,r) の '.' の数を表す
  ll ans = 0;
  ll r = 0;
  // lもrもn-1まで増える
  for(ll l=0; l <= n-1; l++){
    debug(l);
    debug(r);
    debug("--");
    // lとrの区間の間にある点の数がkを超えない限りrを増やしていく
    while(r <= n-1 && cnt[r+1] - cnt[l] <= k){
      r = r+1;
    }
    // 最大値更新
    ans = max(ans, r-l);
  }
  cout<<ans<<endl;
}
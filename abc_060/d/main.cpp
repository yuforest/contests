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

int n,W;
int w[1000005],v[1000005];
int main() {
  cin>>n>>W;
  map<ll, vector<ll>> mp;
  rep(i,n){
    cin>>w[i]>>v[i];
    mp[w[i]].push_back(v[i]);
  }
  for(auto &p:mp){
    sort(all(p.second),greater<ll>());
  }
  debug(mp);
  ll ans = 0;
  ll base = w[0];
  rep(i, mp[base].size()+1){
    rep(j, mp[base+1].size()+1) {
      rep(k, mp[base+2].size()+1) {
        rep(l, mp[base+3].size()+1) {
          if(i*base+j*(base+1)+k*(base+2)+l*(base+3)<=W){
            ll val = 0;
            rep(m,i) val+=mp[base][m];
            rep(m,j) val+=mp[base+1][m];
            rep(m,k) val+=mp[base+2][m];
            rep(m,l) val+=mp[base+3][m];
            debug(val);
            chmax(ans, val);
          }
        }
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}
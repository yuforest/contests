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
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep3(i,a,b) for(ll i=a;i<b;i++)
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

int N,K;
string S;
int main() {
  cin>>N>>K>>S;
  int ans=N;
  // 周期を全探索
  // 全体でO(N^2)の計算量となる
  for(int l=1;l<=N;l++)if(N%l==0) {
    int now=0;
    // スタート地点を0からl-1として全探索
    // l=1の時0からのスタートのみ探索される
    // ここは全部でO(N)の計算量となる
    for(int i=0;i<l;i++) {
      // その周期における文字の種類と数を記録する配列
      int cnt[26]={};
      // 最大の文字の出現回数を記録する配列
      int mx=0;
      // その周期の文字の種類数をカウントする
      for(int j=i;j<N;j+=l) {
        cnt[S[j]-'a']++;
        chmax(mx, cnt[S[j]-'a']);
      }
      // 周期毎の文字数はN/lとして表され、このとき変更すべき文字列数は
      // N/l-mxとなる、出現回数が最も多い文字列に合わせる
      now+=N/l-mx;
    }
    // 変更すべき回数がK以下であればれば実現可能であり
    // 答えはその周期となる
    if(now<=K)ans=min(ans,l);
  }
  cout<<ans<<endl;
}
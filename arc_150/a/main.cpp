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

int T;
int N,K;
string S;
// 3^17=129140163
int zeroc[3<<17];
int onec[3<<17];
int main() {
  cin>>T;
  for(;T--;) {
    cin>>N>>K>>S;
    // O(N)
    for(int i=0;i<N;i++) {
      // 0と1の出現回数の累積和を記録する
      zeroc[i+1]=zeroc[i];
      onec[i+1]=onec[i];
      // 1-indexed
      if(S[i]=='0')zeroc[i+1]++;
      if(S[i]=='1')onec[i+1]++;
    }
    // K個の連続した1を作れる置き方をカウントする
    int cnt=0;
    // iをi+KがNになるまで全探索(iを含まない)
    // O(N)
    for(int i=0;i+K<=N;i++) {
      // iまでの0の出現回数とi+Kまでの出現回数は同じである必要がある
      // i+1からi+Kまでは1か?のみで構成されている必要がある
      if(zeroc[i+K]!=zeroc[i])continue;
      // 1はiまでに1回も出現していてはいけない(出現していたらちょうどK個含まないため)
      // i+Kまでの1の出現回数とN文字目まで到達した時の1の累計出現回数は同じである必要がある
      // なぜならそれ以降に1が出現するとちょうどK個のiではなくなるため
      if(onec[i]!=0||onec[N]!=onec[i+K])continue;
      cnt++;
    }
    debug(cnt);
    // cntが1の時のみちょうど一通りになる
    cout<<(cnt==1?"Yes\n":"No\n");
  }
}
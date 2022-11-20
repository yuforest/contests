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
const ll INF = ll(1e18);

void dfs(int cur,vector<string> &S,vector<string> &T,int remain,string ans){

  // 残り文字が0以下になった箇所は枝切り
  if(remain<0)return;

  // Sを全て使い切った
  // ベースケース
  if(cur == S.size()) {
    // 文字数制限を違反していない&&Tの中にはない文字列
    if(ans.size() >= 3 && !binary_search(T.begin(),T.end(),ans)){
      cout << ans << endl;
      exit(0);
    }
    return;
  }

  // 必ず付けるアンスコ
  if(ans.size() > 0 && ans.back()!='_'){
    dfs(cur,S,T,remain,ans + "_");
  } else{
    dfs(cur+1,S,T,remain,ans + S[cur]);
    // 残っている文字列は1減る
    // Sが残っていない時には上で終わるのでここに戻ってこない
    if(ans.size() > 0) dfs(cur,S,T,remain-1,ans + "_");
  }
}
int main() {

  int N,M;
  cin>>N>>M;

  vector<string> S(N);
  for(int i=0;i<N;i++)cin>>S[i];
  sort(S.begin(),S.end());

  vector<string> T(M);
  for(int i=0;i<M;i++)cin>>T[i];
  sort(T.begin(),T.end());

  int remain = 16;
  for(int i=0;i<N;i++)remain -= S[i].size();
  // 残っている文字数
  remain -= N-1;

  do{
    dfs(0,S,T,remain,"");
  }
  while(next_permutation(S.begin(),S.end()));
  cout << -1 << endl;
  return 0;
}
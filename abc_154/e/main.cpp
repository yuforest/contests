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

long long mod = 1000000007;
vector<ll> G[1 << 18];

// ACLです。使わない時はコメントアウトしています。導入方法はググってみてください。
#include <atcoder/all>
using namespace atcoder;

// 競プロerはrepマクロが大好き
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep3(i,a,b) for(int i=a;i<b;i++)
#define per(i, b) per2(i, 0, b)
#define per3(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
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

string N; int K;
// dp[dgt][isless][k] := 上からdgt桁目まで確定していて、
// 現時点の桁まで見た時にN以下であるかがislessであって、(つまりこれが1の時最大値より小さいということ)
// 0でない数字がk個ある数の個数
// kの部分は4まであれば良い
ll dp[101][2][5];

int main(){
  string s;int K;
  cin>>s>>K;
  // 最初は0桁目まで見て、これが最大値であり、0でない数字は0個であるというパターンが1つある
  dp[0][0][0]=1;
  rep(i,s.size()) rep(j,2) rep(k,K+1){
    // jが0でなければ9, 0なら今の桁
    // jが0の時は現在の桁までNと一致しているので次の桁は今の数字まで見れば良い
    // jが1の時は現在の桁までNより小さいので次の桁は9まで見れば良い
    // iは0-indexedになっている(実際の桁は+1したもの)
    // jが現時点で最大より小さければ、次の下の桁は9まで遷移できる
    // 最大と同じなら、次の桁も最大まで遷移できる
    int lim = (j ? 9 : s[i]-'0');
    // 0からlimまで
    // debug(lim);
    // 例えばN=25の時、
    // t=0,1,2を動き、2の時は次はj=0に遷移する
    // 0,1の時は次はj=1に遷移する
    // そして次のiのループではj=1の時は9まで見ることができて
    // j=0の時は5まで見ることができる
    for(int t=0;t<=lim;t++){
      // tがlimより小さければ1との和を取る、同じなら0との和を取る
      // 0 or 0の時、つまりここまでが最大値で次も最大値の時のみjが0になる
      // それ以外の時は1になる
      // tが0より大きければkの値を増やす、0なら今のまま
      dp[i+1][j||t<lim][k+(t>0)] += dp[i][j][k];
      debug(dp[i][j][k]);
    }
  }
  ll ans=0;
  // iが0の時は最大1つ、これは条件を満たす数字がNと一致する時
  rep(i,2){
    ans += dp[s.size()][i][K];
    debug(dp[s.size()][i][K]);
  }
  cout<<ans<<endl;
}
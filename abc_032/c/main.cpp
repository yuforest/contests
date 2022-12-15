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
  ll n,k;
  cin>>n>>k;
  vector<ll> s(n);
  for(int i=0;i<n;i++){
    cin>>s[i];
  }
  rep(i, n) {
     // 一つでも0があれば全ての列を使える(Kは0以上)
    if(s[i]==0){
      cout<<n<<endl;
      return 0;
    }
  }
  int end=0,ans=0,cnt=0;
  ll sum=1;
  // しゃくとり法を用いて実装する
  for(int i=0;i<n;i++){
    // 右側を追加
    sum*=s[i];
    cnt++;
    // 現在の積がkより大きい時、左側を除いていく
    // その結果積がk以下になるまで、要素があれば除いていく処理
    while(sum>k&&cnt>0){
      sum/=s[end];
      // 左側を進める
      end++;
      // カウントを減らす
      cnt--;
    }
    // 最大値更新
    ans=max(ans,cnt);
  }
  cout<<ans<<endl;
  return 0;
}
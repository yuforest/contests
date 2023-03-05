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
long long mod2 = 998244353;
vector<ll> G[1 << 18];

// ACLです。使わない時はコメントアウトしています。導入方法はググってみてください。
#include <atcoder/all>
using namespace atcoder;

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
  int tc;
  cin >> tc;
  while(tc>0){
    tc--;
    int n;
    string s;
    cin >> n >> s;
    long long cres=0;
    // 争点の文字列
    string target=s;
    int p=0,q=n-1;
    while(p<q){
      // 後半の文字を前半に変更
      target[q]=target[p];
      p++;q--;
    }
    // 辞書順で争点以下の回文がいくつあるか
    // 奇数なら中央の文字まで、偶数なら前半部分
    // 2で割った時の切り捨てが最後になる
    int last=(n-1)/2;
    for(int i=0;i<=last;i++){
      // 26進数と同じ
      cres*=26;
      cres%=mod2;
      cres+=(s[i]-'A');
      cres%=mod2;
      debug(cres);
    }
    cres++;cres%=mod2;
    // 争点の方がsより大きいなら、1引く
    if(s<target){cres+=(mod2-1);cres%=mod2;}
    cout << cres << '\n';
  }
  return 0;
}
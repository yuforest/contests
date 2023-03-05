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

int main(){
  ll L,b[100005],a[100005];
  // 入力
  cin >> L;
  for(int i=1;i<=L;i++) cin >> b[i];

  a[1]=0;
  // B1 = A1 ^ A2よりA2 = A1 ^ B1
  // B2 = A2 ^ A3よりA3 = A2 ^ B2 = (A1 ^ B1) ^ B2
  // 一般にAi = A1 ^ B1 ^ B2 ^... ^ Bi-1(i >= 2)が成り立つ
  // よってA1が定まれば、A2からANまでの全ての値がB1からBN-1までの
  // 値を用いて一意に定まる
  for(int i=1;i<=L;i++){
    a[i+1]=b[i]^a[i];
  }
  // BN = AN ^ A1と矛盾する場合がある
  // AN ^ A1 = B1 ^ B2 ^ ... ^ BN-1となるので
  // BNはA1に依存せずにB1 ^ B2 ^ ... ^ BN-1に一致するはずである
  // よって矛盾したなら解は存在せず、矛盾しないならA1を任意に指定した後解が一意に定まる
  // 解が存在する場合に辞書順最小になるためにはA1が小さい方が良い
  // 今回A1=0のケースがただ一通りだけ存在するのでその1通りが辞書順最小の値になる
  // a[L+1]はA1=0の時B1 ^ B2 ^ ... ^ BN-1 ^ BNに等しい
  // BN = B1 ^ B2 ^ ... ^ BN-1なので
  // a[L+1]は0にならないと矛盾する
  if(a[L+1]!=0) cout << -1 << endl;
  else {
    for(int i=1;i<=L;i++){
      printf("%d\n",a[i]);
    }
  }
}
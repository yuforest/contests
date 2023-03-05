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

int main(void){
  int n;
  cin >> n;
  vector<int> a(n+1);

  for (int i = 1; i < n + 1; i++){
    cin >> a[i];
  }

  cout << 2*n-1 << endl;

  // 最大値の絶対値を持つ要素を探す
  int absmax = 0, id = 1;
  for (int i = 1; i < n + 1; i++){
    if (abs(absmax) < abs(a[i])){
      absmax = a[i];
      id = i;
    }
  }

  // 最大の絶対値を持つ要素を全ての要素に加算する
  // これによって全ての要素が0以上もしくは0以下になる
  for (int j = 1 ; j < n + 1; j++){
    cout << id << " " << j << endl;
  }

  // 最大値の要素が0以下の時nから2までの要素を前の要素に足す
  // 逆の累積和を作ることによって先頭に行くほど要素が小さくなる
  if (a[id] < 0){
    for (int i = n; i > 1; i--){
      cout << i << " " << i - 1 << endl;
    }
  }
  // 最大値の要素が0以上の時は1からn-1までの要素を次の要素に足す
  // つまり累積和を作る
  else{
    for (int i = 1; i < n; i++){
      cout << i << " " << i + 1 << endl;
    }
  }
  return 0;
}
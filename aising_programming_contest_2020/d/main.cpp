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
// usng namespace atcoder;

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


template<typename T>T min(const vector<T>&v){return *min_element(v.begin(),v.end());}
template<typename T>T max(const vector<T>&v){return *max_element(v.begin(),v.end());}
template<typename T>T acc(const vector<T>&v){return accumulate(v.begin(),v.end(),T(0));};
template<typename T>T reverse(const T &v){return T(v.rbegin(),v.rend());};

// DPやlong longの最大値最小値更新で重宝します。
template <typename T>
inline bool chmax(T &a, T b) {
  return ((a < b) ? (a = b, true) : (false));
}
template <typename T>
inline bool chmin(T &a, T b) {
  return ((a > b) ? (a = b, true) : (false));
}


int N;
string X;
int cnt[201010];
int main() {
  cin >> N >> X;

  // popcountの結果の最大値はNなので、1回操作を行うだけでN以下の数にすることができる
  // nが[1, 2*10^5]の場合に0にかかる時間はわかるのでDPで前計算しておく
  rep3(i, 1, 201010) {
    int pp = __builtin_popcount(i);
    // iに対して操作を行ったときに0になる回数
    // は、iをその数のpopcountで割ったあまりに対して操作を行ったときの回数に1を足したもの
    cnt[i] = cnt[i % pp] + 1;
    // debug(i, cnt[i]);
  }

  // 桁は下から見ていくのでreverseしておく
  reverse(all(X));

  int cn = 0;
  // Xのpopcountを数える
  rep(i, N) if (X[i] == '1') cn++;

  // tot1 := 数N mod (cn + 1)
  // tot2 := 数N mod (cn - 1)
  int tot1 = 0, p1 = 1;
  int tot2 = 0, p2 = 1;
  rep(i, N) {
    // フラグが立っている場合
    if (X[i] == '1') {
      // 今計算しているp1かp2を足してmodを取る
      tot1 = (tot1 + p1) % (cn + 1);
      if (2 <= cn) tot2 = (tot2 + p2) % (cn - 1);
    }

    // これはいつでもやる
    // 桁上がりを考慮してmodを取る
    p1 = (p1 * 2) % (cn + 1);
    // cnが0,1のときはtot2は計算しない(0, -1で余りを取ることになるから)
    if (2 <= cn) p2 = (p2 * 2) % (cn - 1);
  }
  debug(tot1);
  debug(tot2);

  vector<int> ans;
  p1 = 1;
  p2 = 1;
  rep(i, N) {
    // フラグが立っている場合(1->0にする場合)
    if (X[i] == '1') {
      // popcountが1のときは0になる
      if (cn == 1) {
        ans.push_back(0);
      }
      // それ以外の時は、tot2からp2を引いてcn-1でmodを取る
      else {
        int x = (tot2 - p2 + cn - 1) % (cn - 1);
        ans.push_back(cnt[x] + 1);
      }
    }
    // 立っていない場合(0->1にする場合)
    else {
      // tot1にp1を足してcn+1でmodを取る
      int x = (tot1 + p1 + cn + 1) % (cn + 1);
      ans.push_back(cnt[x] + 1);
    }

    // これはいつでもやる
    p1 = (p1 * 2) % (cn + 1);
    if (2 <= cn) p2 = (p2 * 2) % (cn - 1);
  }
  // 最後に戻す
  reverse(all(ans));
  rep(i, N) printf("%d\n", ans[i]);
}
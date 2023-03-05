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

typedef pair<int, int> i_i;
int H, W, M;
set<i_i> st;

void input() {
  cin >> H >> W >> M;
  for(int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    st.insert({a, b});
  }
}

void solve() {
  map<int, int> mph, mpw;
  int hmaxval = 0;
  int wmaxval = 0;
  vector<int> hmax, wmax;
  // mapを構築して、最大の爆破対象がある行と列を求める
  // 独立に爆破対象を求めればよい
  for(auto tmp : st) {
    mph[tmp.first]++;
    mpw[tmp.second]++;
    chmax(hmaxval, mph[tmp.first]);
    chmax(wmaxval, mpw[tmp.second]);
  }
  // 最大の行であれば、その行をhmaxに追加
  for(auto tmp : mph) {
    if(hmaxval == tmp.second) hmax.push_back(tmp.first);
  }
  // 最大の列であれば、その列をwmaxに追加
  for(auto tmp : mpw) {
    if(wmaxval == tmp.second) wmax.push_back(tmp.first);
  }
  // 爆弾をおくマスに爆破対象がある場合
  int ANS = hmaxval + wmaxval - 1;
  // RAが最大かつ CBが最大で、
  // (A,B) に爆発対象が存在しない(A,B) の組み合わせが存在するかどうかを調べる必要がある
  // 爆発対象が存在するマスは高々 M 個しか存在しないため、調べる回数は M 回以下
  // 例えば3*3で(1,1),(2,2),(3,3)のようにH*M個の探索候補がある場合でも
  // (1,2)まで調べた時点でこのマスに爆発物はないのでここを爆破して答えは2個になる
  debug(hmax);
  debug(wmax);
  for(auto h : hmax) {
    for(auto w : wmax) {
      debug(h);
      debug(w);
      // 今の行と列の組み合わせが爆発対象の座標でない場合は
      // ここまで求めた答え+1が答えになる
      if(st.find({h, w}) == st.end()) {
        ANS++;
        cout << ANS << endl;
        return;
      }
    }
  }
  cout << ANS << endl;
}

int main() {
  input();
  solve();
  return 0;
}

// 探索候補が多いがすぐに終わる場合
// 3 3 3
// 2 2
// 1 1
// 3 3

// M回探索する場合
// 3 3 3
// 1 1
// 1 2
// 1 3

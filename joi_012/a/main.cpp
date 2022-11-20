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

int ans[2010];
int N;
int lights[100008];
int light_list_size=0;
int light_list[100002];
int main() {
  scanf("%d",&N);
  for(int i=0;i<N;i++) scanf("%d",&lights[i]);
  int sequence=0;
  // 交互列を圧縮する
  // 連続する3つの交互列の真ん中を反転させることで長い交互列を作成することができ、
  // これが最大の長さとなる
  for(int i=0;i<N;i++) {
    if(sequence > 0) {
      // 前の電球と同じものが連続したらリセット
      if(lights[i] == lights[i-1]) {
        light_list[light_list_size++] = sequence;
        sequence = 0;
      }
    }
    sequence++;
  }
  // 終了した時に連続している交互列を保存
  if(sequence>0) light_list[light_list_size++] = sequence;
  int total=0;
  int max=0;
  for(int i=0;i<light_list_size;i++) {
    // 今の交互列を足す
    total+=light_list[i];
    // 3以上の時は3つ前の交互列を引く
    if(i>2) total-=light_list[i-3];
    // 最大値更新
    if(max<total) max=total;
  }
  printf("%d\n",max);
  return 0;
}
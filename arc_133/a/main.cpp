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

// int main() {
//   ll N, L, W;
//   cin >> N >> L >> W;
//   ll a[N];
//   rep(i, N) cin >> a[i];
//   ll ans = 0;
//   rep(i, N) {
//     if (i == 0) {
//       if (a[i] > 0) ans += (a[0] + W - 1) / W;
//     } else {
//       // シートがつながっているなら追加しない
//       if (a[i] - a[i-1] <= W) continue;
//       ans += (a[i] - a[i-1] - W + W - 1) / W;
//     }
//   }
//   // 最後のシートから橋の最後まで
//   if (L - a[N-1] - W > 0) {
//     debug(L - a[N-1] - W);
//     ans += (L - a[N-1] - W + W - 1) / W;
//   }
//   cout << ans << endl;
// }

int main(){
  int N;
  cin>>N;
  vi A(N);
  rep(i, N) {
    cin >> A[i];
  }
  int tmp=0;
  for(int i=0;i<N-1;i++){
    // 次の要素より大きい時tmpに代入してbreak
    if(A[i] > A[i+1]){
      tmp=i;
      break;
    }
    // そうでなければi+1したものを代入
    tmp=i+1;
  }
  for(int i=0;i<N;i++){
    if(A[i]!=A[tmp]) cout<<A[i]<<' ';
  }
  cout << endl;
}
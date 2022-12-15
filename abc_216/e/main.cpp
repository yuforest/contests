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
  int N;
  long long K;
  cin >> N >> K;
  vector<long long> A(N);
  for (int i = 0; i < N; i++){
    cin >> A[i];
  }
  long long tv = 2000000001, fv = 0;
  // 二分探索する
  // tvの値をなるべく大きい状態でK回分を賄いたい
  // そのような値を二分探索を使って見つけるというのが肝
  // 全てがtv以下の時までアトラクションに乗るという想定
  // tvは条件を満たさないギリギリの値、全ての要素がfv以下の時まで
  // アトラクションに乗れば確実に越えるがK回を超えることもある
  // そのような境界値を探索する
  // O(Nlogmax(Ai))
  while (tv - fv > 1){
    long long mid = (tv + fv) / 2;
    debug(mid);
    long long cnt = 0;
    // 数列全てがmidより小さくなるために、何回操作を行えばよいか
    for (int i = 0; i < N; i++){
      if (A[i] >= mid){
        cnt += A[i] - mid + 1;
      }
    }
    // cntがKより小さいとき、求めている値は現在より左側にある
    // 引く値をもっと小さくする必要がある
    if (cnt < K){
      tv = mid;
    } else {
      // cntがK以上の時求めている値は現在よりも右側にある
      // 引く値をもっと大きくする必要がある
      fv = mid;
    }
  }
  debug(tv);
  long long ans = 0;
  for (int i = 0; i < N; i++){
    // 求めたtv以上の要素に対して操作を行う
    if (A[i] >= tv){
      // 操作を行う回数*(初項+末項)/2
      // 等差数列の和の公式: Sn = 1/2(a1+an)n
      ans += (A[i] - tv + 1) * (A[i] + tv) / 2;
      // Kから操作を行った回数を差し引く
      K -= A[i] - tv + 1;
    }
  }
  debug(K);
  debug(ans);
  // ここで残ったKに対しては(二分探索した値-1)*Kを足してやる
  // tv-1(fv)以下のところまでアトラクションに乗れば確実に超える
  // tvの時までアトラクションに乗った後、余ったKに関しては
  // tv-1の魅力度のアトラクションが残っていることが保証される
  // 残っていなければ、つまりtv-2の魅力度アトラクションが
  // ありうるとしたらtvは現在の値ではなくtv-1となっていないと矛盾するため
  ans += K * (tv - 1);
  cout << ans << endl;
  return 0;
}
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

int main() {
  // N ^ xがNと同じになることはない(x != 0だから)
  // xを二進数表記したとき最大のbitが立っているところが0の場合N ^ x > N(Nと一致するところのbitが上がったままになる)
  // それが1の場合N ^ x < N(Nと一致するところのbitが下がる)
  // N を 2 進表記したときに 2^kの位が 1 であるようなすべての k について、(つまり全てのkを全探索する)
  // L<=x<=R であって，かつ x を 2 進表記したときに 1 になっている最大の位が 2^kであるようなxの個数を求めればよい
  // 後者の条件は2^k <= x < 2^(k+1)
  // よってxの条件はmax(L, 2^k) <= x <= min(R, 2^(k+1)-1)
  // ANDで繋がる条件は小さい方の条件でmax, 大きい方の条件でminを取れば良い(数直線の共通部分を思い浮かべると良い)
  // になり簡単に数えることができる
  long long N, L, R, ans = 0, cntR = 0, cntL = 0;
  cin >> N >> L >> R;
  // 2^63まで考えれば良い
  // xの最上位bitを全探索する
  for(int i = 63; i >= 0; i--){
    // 2^iとNでANDを取りbitが立っていれば
    if((1LL << i) & N) {
      ll start = max(1ll<<i,L);
			ll end = min((1ll<<(i+1))-1, R);
      debug(start);
      debug(end);
			if(end >= start) ans += end - start + 1;
    }
  }
  cout << ans << endl;
  return 0;
}
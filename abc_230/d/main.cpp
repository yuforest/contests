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
  using P = pair<ll, ll>;
  ll N, D, L, R;
  vector<P> LR;
  cin >> N >> D;
  for (int i = 0; i < N; i++) {
    cin >> L >> R;
    LR.emplace_back(L, R);
  }
  // Rに対して昇順にソートしていく
  // これは終了時刻が早いものから選んでいくことで
  // 後の選択肢を増やすという区間スケジューリング問題の考え方と
  // 同じものである
  sort(begin(LR), end(LR), [](P& a, P& b) { return a.second < b.second; });
  // 最初にxを非常に小さい値で初期化しておく
  // 順番に壁を見ていき、壁が破壊されていない場合は右端にパンチを放って破壊していく
  ll ans = 0, x = -(1LL << 40);
  // Rで昇順に並べている以上、次以降の壁をまとめて壊せる可能性を増やすためには
  // 今の壁のRの位置にパンチを放つことが最適となる
  // 最初の壁に対しても同じことが言えるのでRの位置にパンチを放ってその位置+D-1までに
  // 次の壁があれば壊せたと判定していくのが最適解と言える
  for (auto& [l, r] : LR) {
    // 今いる地点からD−1だけ進んだ所までの壁を破壊することができている
    // ので次の壁(今見ている壁)がそれ以上のところにあれば壁の右にパンチを放って破壊して
    // 今いる位置を更新する
    // 例えば今2の位置にいて、Dが3の時に4までパンチが届くが、lが5であればパンチは届かない
    // のでもう一回パンチを放つ必要がある
    if (x + D - 1 < l) ans++, x = r;
  }
  cout << ans << "\n";
}
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

int N, D, A, X[201010], H[201010];
ll buf[201010];

// 貪欲(左から見ていく)、しゃくとり法(爆弾の範囲を計算)、imos法(累積和、ダメージを区間に反映する)
// の組み合わせ的な問題
int main() {
  cin >> N >> D >> A;
  rep(i, N) cin >> X[i] >> H[i];

  // 左右に広がるので爆弾の範囲を2倍にする
  D *= 2;

  // 座標と体力をペアにして座標で昇順ソート
  vector<pair<int, int>> xh;
  rep(i, N) xh.push_back({X[i], H[i]});
  sort(all(xh));

  ll ans = 0;
  // 倒すモンスターを左端として爆弾を使った時に
  // どのモンスターまで爆弾が届くのかを計算するためにしゃくとり法を行う
  int R = 0;
  rep(L, N) {
    // Lが0より大きいときは、buf[L]にbuf[L-1]を足し累積和をとる
    // 先頭から操作を行いながら累積和を取ることで
    // 利用したい部分は正しい値を得ながら、区間に対する計算を行うことができる
    if (L) buf[L] += buf[L - 1];

    int x = xh[L].first;
    int h = xh[L].second;

    if (buf[L] < h) {
      chmax(R, L + 1);
      // RがNを超えずに、LとRの距離がD以下のときRを右にずらす
      // Lを固定しRをずらすことで爆弾がどのモンスターまで届くのかを計算する
      // このときRは閉区間(区間に含まれない)
      while (R < N and xh[R].first - x <= D) R++;

      // 過去に使った爆弾によるダメージ(buf[L])を引く
      ll d = h - buf[L];

      // 左側のモンスターの体力が0になる爆弾の使用回数
      ll cnt = (d + A - 1) / A;
      // imos法で爆弾の範囲にあるモンスターの体力を減らす
      // L~R-1のモンスターの体力をcnt*Aだけ減らす
      buf[L] += cnt * A;
      buf[R] -= cnt * A;
      // 爆弾の使用回数を加算
      ans += cnt;
    }
  }

  cout << ans << endl;
}
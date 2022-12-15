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
  long long N, M;
  long long cnt = 0;
  cin >> N;
  M = N;
  long long keta = 1;
  // 10桁分の計算を行う
  // 例えば12までの数字の1の位には1が2回出てくる(1,11に)
  // 10の位には3回出てくる(10,11,12)
  // よって答えは5
  // 101までの数字の1の位には1が11回出てくる(1,11,...101)
  // 10の位には1が10回出てくる(10,11..19)
  // 100の位には1が2回出てくる(100,101)、このとき100を一旦足して存在しない102~199までの98を引いている
  // よって答えは23
  for (int i = 0; i <= 9; i++) {
    // Mが0になったら抜ける
    if(M == 0) break;

    // Mの最後の桁が0の時
    if (M % 10 == 0) {
      cnt += (M / 10) * keta;
    } else {
      // そうでない時最後の桁の1を含む
      cnt += (M / 10 + 1) * keta;
    }
    debug(cnt);
    // Mが0より大きく最後が1なら
    if (M > 0 && M % 10 == 1) {
      // 足しすぎた分を差し引く
      // 例えば12の時i=0で2がcntに足され
      // i=1で10がcntに足される(1/10+1)*keta=10のため
      // しかし10の位は10,11,12しかないため最後の桁のない数字の分を引いておかないと
      // 計算が合わない
      // その帳尻合わせのためにここで引いている(例の場合13~19の分の7つ)
      // 10-(12%10)-1=7
      ll dec = keta - (N % keta) - 1;
      debug(dec);
      cnt -= dec;
    }
    // Mの最後の桁を消す
    M /= 10;
    // 桁は10倍ずつ増えていく
    keta *= 10;
  }

  cout << cnt << endl;

  return 0;
}
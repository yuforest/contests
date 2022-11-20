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


const long long INF = 1LL<<60;
int N;
long long K;
vector<int> P;
vector<long long> C;

long long solve() {
  long long res = -INF;

  // 順列を各サイクルに分解する
  vector<bool> used(N, false);
  vector<vector<long long>> ss;
  for (int i = 0; i < N; ++i) {
    if (used[i]) continue;
    int cur = i;
    vector<long long> s;
    // 現在の頂点から始まるサイクルを構成する
    while (!used[cur]) {
      used[cur] = true;
      // 得点を追加している
      s.push_back(C[cur]);
      // 次の位置を代入
      cur = P[cur];
    }
    // ネストされた配列に追加
    ss.push_back(s);
  }

  // 各サイクルごとに考える
  for (auto vec : ss) {
    // 各サイクルのサイズ
    long long M = vec.size();

    // サイクルを二週したものの累積和
    vector<long long> sum(M*2+1, 0);
    for (int i = 0; i < M*2; ++i) sum[i+1] = sum[i] + vec[i%M];

    // amari[r] := 連続するr個の総和の最大値
    // 二周しているのはサイクルのどこからでも始めることができるため
    vector<long long> amari(M, -INF);
    // iはどこから始めるか、jは何個連続するのかを表している
    for (int i = 0; i < M; ++i) {
      for (int j = 0; j < M; ++j) {
        chmax(amari[j], sum[i+j] - sum[i]);
      }
    }

    // 余りの長さで場合分け
    for (int r = 0; r < M; ++r) {
      // 余りの回数の時点でKより大きくなってしまう場合は除く
      if (r > K) continue;
      // 周回する回数
      long long q = (K - r) / M;
      // この場合最初の位置から一度も移動しないので除く
      if (r == 0 && q == 0) continue;

      // 一蹴の総和が正かどうかで場合分け
      if (sum[M] > 0) chmax(res, amari[r] + sum[M] * q);
      // 正でない場合は一回以上移動するときの余りの最大値が答え
      else if (r > 0) chmax(res, amari[r]);
    }
  }
  return res;
}

int main() {
  cin >> N >> K;
   P.resize(N); C.resize(N);
  for (int i = 0; i < N; ++i) cin >> P[i], --P[i];
  for (int i = 0; i < N; ++i) cin >> C[i];
  cout << solve() << endl;
}

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


int main() {
  // 決めてから、整合性を確認する
  int N; cin >> N;
  vector<vector<long long>> C(N, vector<long long>(N));
  for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) cin >> C[i][j];
  vector<long long> X(N), Y(N);

  auto solve = [&]() -> bool {
    long long mix = C[0][0], miy = C[0][0];
    // mixには0列目, miyには0行目の最小値が入る
    for (int i = 0; i < N; ++i) chmin(mix, C[i][0]), chmin(miy, C[0][i]);
    // X[i]にはCのi行目0列目からmixを引いたものを代入する(縦に最初の1列だけ見ていく)
    // Y[i]にはCの0行目i列目からmiyを引いたものを代入する(横に最初の1行だけ見ていく)
    for (int i = 0; i < N; ++i) X[i] = C[i][0] - mix, Y[i] = C[0][i] - miy;

    // 3
    // 4 3 5
    // 2 1 3
    // 3 2 4
    // 上記の例だとmixは2, miyは3になり
    // x = {2, 0, 1}
    // y = {1, 0, 2}
    // のようになる

    // 差分を一律に足す
    // 上の例だとC[0][0] - X[0] - Y[0] = 4 - 2 - 1 = 1となる
    // C[0][0]に対して1だけ足りないのでX[i]とy[i]のどちらかの配列要素全てに1を足せば良い
    // この時どちらに足したとしても配列要素全てに対して足すので、他の列、もしくは行は全て1増えることとなる
    // よってどちらに足しても良い
    long long dif = C[0][0] - X[0] - Y[0];
    for (int i = 0; i < N; ++i) X[i] += dif;

    // 整合性を確認する
    // 最初の行と列の整合性を満たしていても他の位置の値を満たさないことがある
    // 例えば
    // 3
    // 4 3 5
    // 2 2 3
    // 3 2 4
    // 上記のような場合mixは2, miyは3となり
    // x = {2, 0, 1}
    // y = {1, 0, 2}
    // 最初の例と同じでxに全て1を足すと
    // x = {3, 1, 2}
    // となるが、
    // C[1][1] = 2に対して
    // A[1] + B[1] = 1
    // となり整合性を満たさない
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (X[i] + Y[j] != C[i][j])
                return false;
    return true;
  };

  if (solve()) {
    cout << "Yes" << endl;
    for (int i = 0; i < N; ++i) cout << X[i] << " "; cout << endl;
    for (int i = 0; i < N; ++i) cout << Y[i] << " "; cout << endl;
  }
  else cout << "No" << endl;


  return 0;
}
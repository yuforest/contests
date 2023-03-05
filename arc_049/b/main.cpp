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

const int MAXN = 1010;
int X[MAXN], Y[MAXN], C[MAXN];
int N;

// 時間tで全ての頂点が一箇所に集まることができるかという判定問題を考える
// 時間t以内にi番目が動ける範囲は、
// Xi,Yiを中心とする一辺の長さが2*t/C[i]のx軸、y軸に平行な正方形
// この判定問題はある時間までは不可能で、ある時間以上は可能になるという単調性を持っている
bool ok(double r) {
  // 全てのiとjの組み合わせに対してiが動ける範囲と
  // jが動ける範囲に共通部分があることが必要
  for (int i = 0; i < N; i++) for (int j = i+1; j < N; j++) {
    // iとjのy座標の差の絶対値
    int dy = abs(Y[i]-Y[j]);
    // r/C[i] + r/C[j]はt秒以内に各頂点がy方向に動ける距離の合計
    // y方向のプラスかマイナスに各頂点が動いて、共通の範囲を作ることができるかどうか
    // これがdyより小さければ実現不可能
    if (dy > r/C[i] + r/C[j]) return false;
    // iとjのx座標の差の絶対値
    int dx = abs(X[i]-X[j]);
    // r/C[i] + r/C[j]はt秒以内に各頂点がx方向に動ける距離の合計
    // x方向のプラスかマイナスに各頂点が動いて、共通の範囲を作ることができるかどうか
    // これがdxより小さければ実現不可能
    if (dx > r/C[i] + r/C[j]) return false;
  }
  return true;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i] >> C[i];
    }
    double low = 0, high = 1e9;
    for (int i = 0; i < 50; i++) {
        const double med = (low+high)/2;
        // 移動可能なら答えはこれ以下の時間に存在する
        if (ok(med)) high = med;
        // 不可能なら答えはこれ以上の時間に存在する
        else low = med;
    }
    printf("%.10lf\n", high);
    return 0;
}
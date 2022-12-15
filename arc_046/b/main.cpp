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
  ll N, A, B;
  cin >> N >> A >> B;
  // 石がA個以下であれば全ての石を取れば良いので先手必勝
  if (N <= A) {
    cout << "Takahashi" << endl;
    return 0;
  }
  // 石の数が同じ時
  if (A == B) {
    // この時先手が1からAまでの中でどのように石を取っても
    // 後手は石の数をA+1で割った余りが0になるように石を取り続けることが可能
    // 最後にはA+1個になり、先手が取った後に後手が最後の石を取る
    // A=3,B=3,N=4の時
    // 先手が1つ取ったら後手は3つ取れば勝ち
    // 先手が3つ取ったら後手は1つ取れば勝ち
    if (N % (A+1) == 0) {
      cout << "Aoki" << endl;
    } else {
      // 先手がNをA+1で割った余りが0になるように取り続けることができるので先手が勝つ
      // A=3,B=3,N=5の時
      // 先手が1つ取ると4つになるので、上の後手が勝つパターンと同じ状況に持ち込むことができる
      cout << "Takahashi" << endl;
    }
    return 0;
  }
  // それ以外の時は取れる石の数が多い方が勝つ
  // 例えばN > AかつA > Bで先手が1つの石を取ったとき、後手がどのように石を取ったとしても
  // 再び先手の番が訪れる
  // N-1 > A-1 >= B
  // つまりN-1はA-1より大きく、これがB以上であることが上の式よりわかるので
  // 1つ以上石が残った状態で再び先手の番が回ってくる
  // いずれN<=A(先手が1度で取り切れる量)の盤面で先手の手番が訪れるので先手必勝
  // N > AかつA < Bに関しては後手必勝
  // 先手がどのように石を取っても後手の手番が訪れる
  // このときの残りの数をNとしてN<=BならBの勝利
  // N>Bで後手が1個の石を取ったとき、先手がどのように石を取ったとしても再び後手の手番が訪れる
  // A > Bの時と同様の論理がAの最初の手番の後に適用できる
  // N-1 > B-1 >= A
  if (A > B) cout << "Takahashi" << endl;
  else cout << "Aoki" << endl;
  return 0;
}
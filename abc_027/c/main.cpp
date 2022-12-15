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

// int main(){
//   long long n;
//   cin >> n;
//   // nより大きくなるということ
//   n += 1;
//   bool win = true;
//   while(n > 1){
//     debug(n);
//     debug(win);
//     // Takahashiは自分のターンで1になってしまったら負け
//     // 毎回winは切り替わるので、Takahashiは自分のターンでは常に
//     // 左に行こうとする
//     // n+1から見ると減らない方向に行こうとする
//     if(win){
//       n = (n+1)/2;
//     } else{
//       // 同様にAokiは常に右に行こうとする
//       // n+1から見ると減る方向に行こうとする
//       n = n/2;
//     }
//     // 勝ち負けを切り替える
//     // 例えば1回の操作で上限を超えてしまう場合はTakahashiが負ける
//     win = !win;
//   }

//   if(win){
//     cout << "Takahashi" << endl;
//   }else{
//     cout << "Aoki" << endl;
//   }

//   return 0;
// }



int main(){
  ll N;
  cin >> N;
  // 深さ
  ll depth = 0;
  // 高橋のターンから
  int turn = 1;
  // 今の値
  ll x = 1;
  // 例えばn=10の時深さ4
  for (ll n = N; n > 0; n /= 2) depth++;
  debug(depth);
  // シミュレーション
  // 境界線を跨ぐと負けてしまうので自分が負けない方向に行こうとする
  // その方向はNの深さによって変わる
  while (true){
    // Nを超えた時点で抜ける
    if (x > N) break;
    // 深さが偶数かどうかにより戦略が逆になる
    if (depth % 2){
      // 偶数なら高橋は右に行く戦略
      // 青木は左に行く戦略
      if (turn == 1) {
        x = x * 2 + 1;
      } else{
        x = x * 2;
      }
    } else{
      // 奇数なら高橋は左に行く戦略
      // 青木は右に行く戦略
      if (turn == 1){
        x = x * 2;
      } else{
        x = x * 2 + 1;
      }
    }
    // ターン切り替え
    turn *= -1;
  }

  // Nを超えた時に最後に操作していた人が負ける
  if (turn == 1) cout << "Takahashi" << endl;
  else cout << "Aoki" << endl;
  return 0;
}

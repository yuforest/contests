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

// 操作AによってPの不一致度は「2増加」「2減少」「変わらない」の三通りがある
// P_iとiの偶奇が一致しているものを良いインデックス、一致していないものを悪いインデックス
// i,i+1が共に良いインデックスのとき不一致度は2増加
// i,i+1が共に悪いインデックスのとき不一致度は2減少
// i,i+1が1つは良いインデックスでもう一つは悪いインデックスのとき不一致度は2増加
// 操作Aは少なくとも1/2*(Pの初期の不一致度)回は必要
// 操作Bによって悪いインデックスを端に集めた後に操作Aによって不一致度を0にする
// 操作 B のみを行うことで悪いインデックスを端に寄せることが可能なのは、
// 偶数の悪いインデックスの個数と奇数の悪いインデックスの個数が等しい
// その後P_i>P_i+2であるようなiを見つけてiについて操作Bを行う
int p[405];
vector<pair<char,int>> ans;
// 操作を記録するための関数
// 操作をcとしてAかBで受け取る
void f(char c,int i){
  // 1-indexedにしている
  ans.emplace_back(c,i+1);
  // c-'A'は0か1を返す
  swap(p[i],p[i+1+c-'A']);
}
int main(){
  // 入力
  int N;
  cin >> N;
  for(int i=0;i<N;i++) cin >> p[i];

  // jとj+2の偶奇が一致しておらず(本来一致しているべき)、jの値とP[j]の偶奇が一致していない時
  // jは0-indexedなので0の時1つ目の要素ということ、一致していなければ良いインデックスであるということ
  // この時にj+2にある要素をjに持ってきたい
  // N回操作を行うことで前に詰めることができる
  for(int i=0;i<N;i++) for(int j=0;j<N-2;j++) if(p[j]%2!=p[j+2]%2 && p[j]%2!=j%2) f('B',j);
  // 不一致度を0にするような操作
  // 連続する2つの要素の偶奇が揃っていなくて、悪いインデックスのときに操作を行って
  // 良いインデックスにする
  for(int i=0;i<N-1;i++)if(p[i]%2!=p[i+1] && p[i]%2==i%2) f('A',i);
  // これで全て良いインデックスになったので後はP_i>P_i+2である要素を見つけて操作Bを行う
  for(int i=0;i<N;i++) for(int j=0;j<N-2;j++) if(p[j]>p[j+2]) f('B',j);
  cout << ans.size() << endl;
  for(auto x:ans) cout << x.first << ' ' << x.second << endl;
}
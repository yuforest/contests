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

typedef struct Point_Coordinates {
    double x, y;
} point;

// 直線ABの傾きはyA-yB/xA-xB
// 直線ABの方程式はy-yA=(yA-yB/xA-xB)(x-xA)
// 式変形して(xA-xB)(y-yA)-(yA-yB)(x-xA) = 0
// よってC,Dとの領域判定を行う場合
// 上の式に(xC,yC)と(xD,yD)を代入する
// これがプラスになるということは直線よりも点が上に位置することを意味する
// これがマイナスになるということは直線よりも点が下に位置することを意味する
// s=(xA-xB)(yC-yA)-(yA-yB)(xC-xA)
// t=(xA-xB)(yD-yA)-(yA-yB)(xD-xA)
// とおくとst<0の時点C,Dは直線ABに対して別の領域に存在すると言える

// 線分の交差判定
// 直線ABに対する点C,Dの位置と
// 直線CDに対する点A,Bの位置を両方チェックすることで
// 線分の交差判定をすることができる
// 線分ab, cdが交差する場合True
// 端点が他方の線分上にある場合もTrue
// 端点が他方の線分の延長線上にある場合もTrueを返すので注意
bool Judge(point &a, point &b, point &c, point &d) {
  double s, t;
  // 直線ABに対して点C,Dがどちらにあるかチェックしている
  s = (a.x - b.x) * (c.y - a.y) - (a.y - b.y) * (c.x - a.x);
  t = (a.x - b.x) * (d.y - a.y) - (a.y - b.y) * (d.x - a.x);
  // この時同じ側に存在するので交差しない
  if (s * t > 0)
      return false;

  // 直線CDに対して点A,Bがどちらにあるかチェックしている
  s = (c.x - d.x) * (a.y - c.y) - (c.y - d.y) * (a.x - c.x);
  t = (c.x - d.x) * (b.y - c.y) - (c.y - d.y) * (b.x - c.x);
  // このとき同じ側に存在するので交差しない
  if (s * t > 0)
      return false;
  return true;
}

// 100C2=50*99=4950
int main(){
  point A, B;
  cin >> A.x >> A.y >> B.x >> B.y;
  ll N;
  cin >> N;
  vector<point> points(N);
  rep(i, N) {
    cin >> points[i].x >> points[i].y;
  }
  ll cross = 0;
  rep(i, N) {
    if (i != N-1) {
      if (Judge(A, B, points[i], points[i+1])) cross++;
    } else {
      if (Judge(A, B, points[i], points[0])) cross++;
    }
  }
  debug(cross);
  cout << cross/2+1 << endl;
}
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

int ans[2010];

int y,m,d;
// 一年間の月の日数が入っている配列
int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
char ch;

// 閏年かどうかを判定する関数
inline bool leap(int year) {
  // 4で割り切れるが100で割り切れない年、ただし400で割り切れる時は閏年
	return (!(year%4) && year%100 || !(year%400));
}

int main() {
  // scanf("%d/%d/%d", &y, &m, &d);
  cin>>y>>ch>>m>>ch>>d;
  // 今が閏年なら2月を29日に
  if(leap(y)) a[2]++;
  while(y % (d * m)) {
    ++d;
    // 日が月の日数より大きくなったら月を進めて日をリセット
    if(d > a[m]) m++,d=1;
    // 月が12より大きくなったら、年をすすめて月をリセット
    if (m>12) ++y,m=1;
  }
  // 月と日は2桁で表示するために下記のようにしている
  cout << y << '/' << m/10 << m%10 << '/' << d/10 << d%10 << endl;
  return 0;
}
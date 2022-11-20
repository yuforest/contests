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

// leftとrightの間に空席が存在するかどうかを判定する関数
bool betemp(string sleft, string sright, int left, int right) {
  // もし2つの文字が等しければ、間隔が奇数がどうかを返す
  if (sleft == sright) return (right - left) % 2 == 1;
  // もし異なれば、間隔が偶数かどうかを返す
  else return (right - left) % 2 == 0;
}

// 間隔が偶数で、両端の性別が異なる
// 間隔が奇数で、両端の性別が等しい
// という場合には必ずその間に空席が存在する
void solve(int N) {
  string vac = "Vacant";
  string sleft, sright, str;
  int left = 0, right = N/2;
  // 最初と半分の箇所にクエリを送る(0,1,2,3,4であれば0と2)
  cout << left << endl;
  cin >> sleft;
  if (sleft == vac) return;
  cout << right << endl;
  cin >> sright;
  if (sright == vac) return;

  // 空席が存在しない場合は、文字を交換し、rightからNで二分探索を行う
  // 前半分にあるか、後ろ半分にあるかを確かめている
  if (!betemp(sleft, sright, left, right)) {
    swap(sleft, sright), left = right, right = N;
  }
  // leftとrightの間隔が空いている限りループ
  while (right - left > 1) {
    int mid = (left + right) / 2;
    cout << mid << endl;
    cin >> str;
    if (str == vac) return;
    // 探索区間に空席があればrightを更新し、なければleftを更新する
    if (betemp(sleft, str, left, mid)) sright = str, right = mid;
    else sleft = str, left = mid;
  }
}

int main() {
  int N;
  while (cin >> N) solve(N);
}
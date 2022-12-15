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
// 1. まず少ない方である0に着目する
// 数が少ない方を考えると考察が進む場合がある(つまり余事象を考えるということ)

// 2. 文字列Sのa[k]文字目が0であるとすると操作は
// 整数iを選びaiの値をx(a[i] < x < a[i+1])(これはiから0111的な時)または
// 整数iを選びaiの値をx(a[i-1] < x < a[i])(これは1110で最後がiの時)に変更する
// と言い換えられる
// b1,b2..bkが0であるとすると、
// 最小何回の操作でa1..akをb1..bkに一致させることができるかという問題に置き換えられる

// 3. 自然な下界を(絶対にある回数未満にはならないという最低限の値)考える
// ここではai!=biとなっているiの個数が下界であり、その理由は1回の操作で要素の1つしか変更できないため

// 4. 下界を実現する方法を考える
// 1回の操作で、ai​=bi​となっている i (1≤i≤K) の個数が1つ減る。
// つまり、1 回の操作で、元々 ai!=biであったものを ai=biにする
// ai>biとなるiが存在する場合->この最小のiをpとするときapの値をbpに変更する
// 全てai<=biである場合-> ai<biとなる最大のiをqとする時aqの値をbqに変更

int N;
string S, T;
int main() {
  // Step #1. 入力
  cin >> N;
  cin >> S;
  cin >> T;
  // Step #2. a[i], b[i] を求める
  vector<int> a, b;
  for (int i = 0; i < N; i++) {
    if (S[i] == '0') a.push_back(i);
    if (T[i] == '0') b.push_back(i);
  }
  // Step #3. 場合分け
  if ((int)a.size() != (int)b.size()) {
    cout << "-1" << endl;
    return 0;
  }
  // Step #4. 答えを計算し、出力する
  int Answer = 0;
  for (int i = 0; i < (int)a.size(); i++) {
    if (a[i] != b[i]) Answer += 1;
  }
  cout << Answer << endl;
  return 0;
}
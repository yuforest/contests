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
vl nums;

// 等差数列の全列挙
set<long long> gen_tosasu(){
  set<long long> res;
  // 初項が1以上9以下
  for(int fir=1;fir<=9;fir++){
    // 公差が−9以上8以下
    for(int d=-9;d<=8;d++){
      string s;
      // 現在の項を初項で初期化
      int dg=fir;
      // 数列の長さは1以上18以下
      // よって最大18回ループすれば良い
      for(int i=0;i<18;i++){
        // 現在の項を文字にして追加
        s.push_back(dg+'0');
        debug(s);
        // 文字列を数字にしたものをsetに追加
        res.insert(stoll(s));
        // 現在の項に公差を足す
        dg+=d;
        // 現在の項が0以下になったり、9を超えたりしたらそれ以上は追加しない
        if(!(0<=dg && dg<=9)){break;}
      }
    }
  }
  return res;
}

int main(void)
{
  ll X;
  cin >> X;
  set<long long> st = gen_tosasu();
  cout <<(*st.lower_bound(X)) << endl;
}
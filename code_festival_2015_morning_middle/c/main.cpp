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
  // 入力
  ll n;
  cin>>n;
  deque<ll> d(n);
  // この時点でdequeに値を入れておく
  rep(i,n) cin>>d[i];

  ll sum = 0;
  // 操作はnが偶数の時も奇数の時もn/2回で終わる
  rep(i,n/2){
    // 最初を1回ひっくり返して、次の色と同じ色にして
    // その後さらに2番目も含めてひっくり返す方法と
    // 最後を1回ひっくり返して、次の色と同じ色にして
    // その後さらに最後から2番目も含めてひっくり返す方法のどちらが小さいかによって
    // 操作方法を変える
    // 黒のコマをおく操作と白のコマをおく操作はセットで行う
    if(d[0]*2+d[1] < d.back()*2+d[d.size()-2]) {
      // この時は最初を変更する
      ll v1=d.front();
      d.pop_front();
      // 2番目の方に置いたコマと、1番目のコマの数を足す
      d.front()+=v1+1;
      // ひっくり返した数を更新
      sum += v1;
      v1=d.front();
      d.pop_front();
      // 2番目に関しても同じことをする
      d.front()+=v1+1;
      // 合計数を更新
      sum += v1;
    }else{
      // この時は最後を変更する
      ll v1=d.back();d.pop_back();
      d.back()+=v1+1;
      sum += v1;
      v1=d.back();d.pop_back();
      d.back()+=v1+1;
      sum += v1;
    }
  }
  cout<<sum<<endl;
  return 0;
}
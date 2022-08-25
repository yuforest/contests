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


// 1,2,3で長さが5に等しい棒を作る問題に帰着できる
int main(){
  ll T;
  cin >> T;
  rep(i, T) {
    ll n2, n3, n4;
    cin >> n2 >> n3 >> n4;
    ll n6 = n3 / 2;
    ll ans = 0;
    // n6*1, n4*1
    ll count1 = min(n4, n6);
    ans += count1;
    n4 -= count1;
    n6 -= count1;
    debug(ans);
    // n6*1, n2*2
    ll count2 = min(n6, n2/2);
    ans += count2;
    n6 -= count2;
    n2 -= count2 * 2;
    debug(ans);
    // n4*2, n2*1
    ll count3 = min(n4/2, n2);
    ans += count3;
    n4 -=  count3 * 2;
    n2 -= count3;
    debug(ans);
    // n4*1, n2*3
    ll count4 = min(n4, n2/3);
    ans += count4;
    n4 -=  count4;
    n2 -= count4 * 3;
    debug(ans);
    // n2*5
    debug(n2);
    ll count5 = n2 / 5;
    ans += count5;
    n2 -= count5 * 5;
    cout << ans << endl;
  }
  return 0;
}

// 1
// 100 100 100
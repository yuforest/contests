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
const ll INF = ll(1e18);

// ll N_size;
// string bi_N = "";
// set<ll> ans;
// ll N;

// bool used[61];
// void dfs(ll current, ll digit) {
//   if (bi_N[digit] == '1') {
//     debug(digit);
//     ll tmp = current + powl(2, digit);
//     if (tmp <= N) ans.insert(tmp);
//     if (digit+1 < N_size) {
//       dfs(tmp, digit+1);
//     }
//   }
//   if (current <= N) ans.insert(current);
//   if (digit+1 < N_size) {
//     dfs(current, digit+1);
//   }
// }

// int main() {
//   cin >> N;

//   ll tmp_N = N;
//   while(tmp_N > 0) {
//     bi_N += to_string(tmp_N % 2);
//     tmp_N /= 2;
//   }
//   debug(bi_N);
//   N_size = bi_N.size();
//   debug(N_size);
//   dfs(0, 0);


//   fore(x, ans) {
//     cout << x << endl;
//   }
//   return 0;
// }


// bit全探索でも解ける
int main() {
  ll N;
  cin >> N;
  vl digits;
  rep(i, 61){
    if (N & (1LL << i)) {
      digits.push_back(i);
    }
  }
  debug(digits);
  int K = digits.size();
  vl ans;
  rep(msk, (1LL << K)) {
    ll tmp = 0;
    rep(i, K) {
      if (msk & (1LL << i)) {
        // tmp += (1LL << digits[i]);
        tmp += powl(2, digits[i]);
      }
    }
    ans.push_back(tmp);
  }
  rep(i, ans.size()) {
    cout << ans[i] << endl;
  }
}
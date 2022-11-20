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
ll N, M;

int main() {
  cin >> N;
  vl digits;
  while(N > 0) {
    digits.push_back(N % 10);
    N /= 10;
  }
  debug(digits);
  ll N = digits.size();
  ll ans = 0;
  rep(msk, (1 << N)) {
    debug(msk);
    vl first;
    vl second;
    rep(i, N) {
      if (msk & (1 << i)) {
        first.push_back(digits[i]);
      } else {
        second.push_back(digits[i]);
      }
    }
    sort(first.begin(), first.end());
    sort(second.begin(), second.end());
    if (first.size() == 0) continue;
    if (second.size() == 0) continue;
    if (first.size() == 1 && first[0] == 0) continue;
    if (second.size() == 1 && second[0] == 0) continue;
    if (first.size() == 2 && first[0] == 0 && first[1] == 0) continue;
    if (second.size() == 2 && second[0] == 0 && second[1] == 0) continue;
    ll first_num = 0;
    debug(first);
    debug(second);
    rep(i, first.size()) {
      first_num += first[i] * pow(10, i);
    }
    ll second_num = 0;
    rep(i, second.size()) {
      second_num += second[i] * pow(10, i);
    }
    chmax(ans, first_num * second_num);
  }
  cout << ans << endl;
  return 0;
}

// これでも解ける
// int main(){
//   string N; cin >> N;
//   sort(N.begin(),N.end());
//   int ans = 0;
//   do{
//       for(int i=1; i<N.size(); i++){
//           int l = 0, r = 0;
//           for(int j=0; j<i; j++) l = l*10+N[j]-'0';
//           for(int j=i; j<N.size(); j++) r = r*10+N[j]-'0';
//           ans = max(ans,l*r);
//       }
//   }while(next_permutation(N.begin(),N.end()));
//   cout << ans << endl;
// }
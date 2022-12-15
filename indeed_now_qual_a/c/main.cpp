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

ll N, Q;
vl s;

// 二分探索でも解ける
// bool ok(ll point, ll limit) {
//   auto index = lower_bound(s.begin(), s.end(), point) - s.begin();
//   debug(s.size() - index);
//   debug(limit);
//   debug(point);
//   return (s.size() - index <= limit);
// }

// int main() {
//   cin >> N;
//   rep(i, N) {
//     ll val;
//     cin >> val;
//     if (val != 0) s.push_back(val);
//   }
//   sort(s.begin(), s.end());

//   debug(s);
//   cin >> Q;
//   vl k(Q);
//   rep(i, Q) {
//     cin >> k[i];
//     ll l = -1, r = 1000002;
//     while(r-l != 1) {
//       ll mid = (l + r) / 2;
//       if (ok(mid, k[i])) r = mid;
//       else l = mid;
//     }
//     debug(l);
//     debug(r);
//     cout << r << endl;
//   }
// }

// 二分探索でなくても解ける
bool solve(){
  int n;
  cin >> n;
  vector<int> score(n);
  rep(i, n) cin >> score[i];
  sort(score.begin(), score.end(), greater<int>());
  while(size(score) and score.back() == 0) score.pop_back();
  int q;
  cin >> q;
  rep(_, q){
    int k;
    cin >> k;
    // k人を合格にする最小のボーダー
    if(k < score.size()){
      // 配列の0~k-1番目までの人を合格にしたので
      // k番目の人は受からない
      // よってscore[k]+1を出力すれば良い
      cout << score[k]+1 << endl;
    }else{
      // 全員合格になる時はボーダーは0点で良い
      cout << 0 << endl;
    }
  }
  return true;
}
signed main(){
  solve();
  return 0;
}
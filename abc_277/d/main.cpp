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


ll s[200005];
int main() {
  ll n, m, a, sum = 0;
  map<ll, ll> mp;

  cin >> n >> m;
  for(int i = 1; i <= n; i++){
    cin >> a;
    mp[a]++;
    sum += a;
  }
  vector<pair<ll, ll>> vec;
  for(auto p : mp) vec.push_back(p);
  int k = vec.size();

  if(k == m){
    cout << 0 << endl;
    return 0;
  }

  int p;
  for(int i = 0; i < k; i++){
    // 次のもの(最後なら始め)と比較して+1になっていなければ探索をやめる
    if(vec[(i+1)%k].first != (vec[i].first+1)%m){
      p = i;
      break;
    }
  }
  debug(vec);
  // 各値を最初に選んだ時に消せる数を消して残る数を求める
  for(int i = 0; i < k; i++){
    // 最初から見てつながっているところから逆向きに見ていくことで、
    // 計算済みの値をもとに今の値を計算することができる
    int j = (p-i+k) % k;
    debug(j);
    s[j] = sum;
    // 例えば最後の数字に1足したもののmod mが最初の数字に等しければ、最初の数字のs[i]の値をコピーする
    if(vec[(j+1)%k].first == (vec[j].first+1)%m) s[j] = s[(j+1)%k];
    s[j] -= vec[j].first * vec[j].second;
  }

  ll ans = sum;
  for(int i = 0; i < k; i++) ans = min(ans, s[i]);
  cout << ans << endl;

  return 0;
}
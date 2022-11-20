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

int h, w, n, r, c, Q;
map<int, vector<int>> amp, bmp;
int main(void) {
  cin >> h >> w >> r >> c >> n;
  for(int i = 1; i <= n; i++){
    int rr, cc;
    cin >> rr >> cc;
    amp[rr].push_back(cc), bmp[cc].push_back(rr);
  }
  for(auto &p : amp) sort(p.second.begin(), p.second.end());
  for(auto &p : bmp) sort(p.second.begin(), p.second.end());

  cin >> Q;
  char d; int l;
  for(int i = 1; i <= Q; i++){
    cin >> d >> l;
    if(d == 'L'){
      auto it = amp.find(r); int lb = 0;
      if(it != amp.end()){
        vector<int> &vec = it->second;
        auto it2 = lower_bound(vec.begin(), vec.end(), c);
        if(it2 != vec.begin()) it2--, lb = *it2;
      }
      c = max(c-l, lb+1);
    }
    if(d == 'U'){
      auto it = bmp.find(c); int lb = 0;
      if(it != bmp.end()){
        vector<int> &vec = it->second;
        auto it2 = lower_bound(vec.begin(), vec.end(), r);
        if(it2 != vec.begin()) it2--, lb = *it2;
      }
      r = max(r-l, lb+1);
    }
    if(d == 'R'){
      auto it = amp.find(r); int ub = w+1;
      if(it != amp.end()){
        vector<int> &vec = it->second;
        auto it2 = upper_bound(vec.begin(), vec.end(), c);
        if(it2 != vec.end()) ub = *it2;
      }
      c = min(c+l, ub-1);
    }
    if(d == 'D'){
      auto it = bmp.find(c); int ub = h+1;
      if(it != bmp.end()){
        vector<int> &vec = it->second;
        auto it2 = upper_bound(vec.begin(), vec.end(), r);
        if(it2 != vec.end()) ub = *it2;
      }
      r = min(r+l, ub-1);
    }
    cout << r << " " << c << "\n";
  }

  return 0;
}
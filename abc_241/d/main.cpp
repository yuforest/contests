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

int main() {
  // multisetを用いることで、
  // 同じ数字が複数存在する集合で二分探索を行うことができる
  multiset<long long> S;
  int q;
  cin >> q;

  rep(i, q){
    int t;
    cin>>t;
    if(t==1){
      long long x;
      cin>>x;
      S.insert(x);
    } else{
      long long x,k;
      cin>>x>>k;
      if(t==2){
        auto it=  S.upper_bound(x);
        long long ans = 0;
        rep(i,k){
          // これからデクリメントするのに既に最初にいたらデクリメントできないので
          // 必要な要素数がないということになる
          if(it==S.begin()){
            ans = -1;
          }
          else it--;
        }
        if(ans!=-1) ans = (*it);
        cout<<ans<<endl;
      } else{
        auto it = S.lower_bound(x);
        long long ans = 0;
        // この時点でendにいたらx以上の値はないということ
        if(it==S.end())ans = -1;
        else{
          rep(i,k-1){
            it++;
            // インクリメントした後にendにいたら、
            // そのような値はないということなので-1になる
            if(it==S.end()) {
              ans = -1;
            }
          }
        }
        if(ans!=-1)ans = (*it);
        cout<<ans<<endl;
      }
    }
  }
  return 0;
}
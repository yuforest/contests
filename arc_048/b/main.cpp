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

// map<int, int> mp;
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



ll mp[125252][3];
ll bumpu[125252];
ll r[125252],h[125252];


// レーティングの累積和を計算しておく
// またレーティングとじゃんけんの手を記録する二次元配列に
// レーティングと手を記録しておくことで
// 自分と同じレーティングの人のじゃんけんの手がわかるので
// 人数を計算することができる
int main(){
  ll n;
  cin>>n;
  rep(i,n){
    cin>>r[i]>>h[i];
    // じゃんけんの手はデクリメント
    // これでグーが0,チョキが1,パーが2となる
    h[i]--;
    // レーティングとじゃんけんの手を記録
    mp[r[i]][h[i]]++;
    // レーティングの人数の分布
    bumpu[r[i]]++;
  }
  // 累積和の計算
  rep3(i, 1, 125252){
    bumpu[i] += bumpu[i-1];
  }
  rep(i,n){
    ll w,l,d;
    w=l=d=0;
    ll rate = r[i], hand = h[i];
    // 自分より小さいレーティングの人には確実に勝っている
    w += bumpu[rate-1];
    // 自分よりレーティングが高い人には確実に負けている
    l += bumpu[125251] - bumpu[rate];

    // レーティングが同じだった場合の勝敗を計算
    // 例えば自分の手がグー(0)だった場合、勝つのは同じレーティングで尚且つチョキ(1)の人
    // 例えば自分の手がチョキ(1)だった場合、勝つのは同じレーティングで尚且つパー(2)の人
    // 例えば自分の手がパー(2)だった場合、勝つのは同じレーティングで尚且つグー(0)の人
    // 自分の手+1の相手に勝つことができるが、自分の手がパーの場合はそれが3になってしまうので
    // 3であまりを取っている
    w += mp[rate][(hand+1)%3];
    // 例えば自分の手がグー(0)だった場合、負けるのはパー(2)の人
    // 例えば自分の手がチョキ(1)だった場合、負けるのはグー(0)の人
    // 例えば自分の手がパー(2)だった場合、負けるのはチョキ(1)の人
    // よって2足して3であまりを取れば良い
    l += mp[rate][(hand+2)%3];
    // ここは単にhandとしていても問題ない
    // d += mp[rate][(hand+3)%3];
    d += mp[rate][hand];

    // 引き分けには自分のデータも入ってしまっているので差し引く
    --d;
    printf("%d %d %d\n",w,l,d);
  }
  return 0;
}
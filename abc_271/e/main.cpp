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


int send(int A, int B, int C, int D) {
  cout << "? " << A << " " << B << " " << C << " " << D << endl;
  cin >> A;
  return A;
}


int n;
long long k;
long long a[200010];

// m周した時に食べるリンゴの数は簡単に求められる
int f(long long m){
	long long s=0;
  // m周した時に食べるリンゴの数
	for(int i=0;i<n;i++) s += min(m,a[i]);
  // これがkより小さいか
	return s<=k;
}
int main() {
  cin >> n >> k;

  rep(i, n) cin >> a[i];
  long long l=0,r=1e12+2;//l ok, r ng
  // 差が1になるまで二分探索
  while(r-l>1) {
    long long m=(l+r)/2;
    // okなら左の境界を真ん中にずらす(この時のmより右側にokとngの境界がある)
    // ngなら右の境界を真ん中にずらす(この時のmより左側にokとngの境界がある)
    if(f(m))l=m;
    else r=m;
  }

  // m周分まとめて食べる
  for(int i=0;i<n;i++){
    // 食べるりんごはlとa[i]の小さい方
    long long d = min(l,a[i]);
    a[i]-=d;
    k-=d;
  }
  // kはNより小さくなっているので、単純にループしてカゴの中にリンゴがあれば食べる
  for(int i=0;k>0;i++)if(a[i]){
    a[i]--;
    k--;
  }
  rep(i, n) {
    if (i) cout << " ";
    cout << a[i];
  }
  cout << endl;
  return 0;
}
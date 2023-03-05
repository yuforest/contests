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
const ll INF = ll(1e18);

int idx[100000];
int a[100000];


int main(){
  cin.tie(0);
  int n,c;
  cin>>n>>c;
  // 0からc-1までの整数に変更
  rep(i,n)cin>>a[i],a[i]--;
  vl ans(n, 0);

  // 4 2
  // 1 2 2 1
  // の例を考える
  // 上で1引いているので
  // 0 1 1 0
  // となっている
  // まず0が出てきて、左側の選び方が1通り
  // 右側の選び方が4通りあるのでこの時点でans[0] = 4となる
  // 次に1が出てきて、左側の選び方が2通り(0 or 1)
  // 右側の選び方が3通りあるのでans[1] = 2 * 3 = 6となる
  // 次に1が出てきて、左側の選び方が1通り(その前に出てきた1を使う部分列は既に答えに含まれている)
  // 右側の選び方が2通りあるのでans[1] = 6 + 2 = 8となる
  // 次に0が出てきて、左側の選び方が3通り、右側の選び方が1通りあるので
  // ans[0] = 4 + 3 = 7となる
  // 既に数え上げたインデックスを除いて、左側の候補数をどのように導くかがキモ
  // 右側は今のインデックスを含む右側全ての数で良い
  rep(i,n){
    // 今のインデックスから前に出てきたところ+1までの部分列の長さ * 残りの数列の長さ
    ans[a[i]] += (long long)(i-idx[a[i]]+1) * (n-i);

    // 今の数字が出てきた次のインデックスに更新
    idx[a[i]] = i+1;
    debug(ans);
  }
  rep(i,c){
    cout << ans[i] << endl;
  }
  return 0;
}
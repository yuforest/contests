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

// 競プロerはrepマクロが大好き
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep3(i,a,b) for(int i=a;i<b;i++)
#define all(x) (x).begin(), (x).end()
#define rrep(i,a,b) for(int i=a;i>=b;i--)

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

vector<ll>dx={1,-1,0,0,1,1,-1,-1};
vector<ll>dy={0,0,1,-1,1,-1,1,-1};

using mint=modint998244353;

int main() {
  long long N;
	cin >> N;
	mint ans=mint(N)*(N+1)/2;
	if(N>=10)ans-=mint(9)*(N-9);
	if(N>=100)ans-=mint(90)*(N-99);
	if(N>=1000)ans-=mint(900)*(N-999);
	if(N>=10000)ans-=mint(9000)*(N-9999);
	if(N>=100000)ans-=mint(90000)*(N-99999);
	if(N>=1000000)ans-=mint(900000)*(N-999999);
	if(N>=10000000)ans-=mint(9000000)*(N-9999999);
	if(N>=100000000)ans-=mint(90000000)*(N-99999999);
	if(N>=1000000000)ans-=mint(900000000)*(N-999999999);
	if(N>=10000000000)ans-=mint(9000000000)*(N-9999999999);
	if(N>=100000000000)ans-=mint(90000000000)*(N-99999999999);
	if(N>=1000000000000)ans-=mint(900000000000)*(N-999999999999);
	if(N>=10000000000000)ans-=mint(9000000000000)*(N-9999999999999);
	if(N>=100000000000000)ans-=mint(90000000000000)*(N-99999999999999);
	if(N>=1000000000000000)ans-=mint(900000000000000)*(N-999999999999999);
	if(N>=10000000000000000)ans-=mint(9000000000000000)*(N-9999999999999999);
	if(N>=100000000000000000)ans-=mint(90000000000000000)*(N-99999999999999999);
	if(N>=1000000000000000000)ans-=mint(900000000000000000)*(N-999999999999999999);
	cout << ans.val();
}
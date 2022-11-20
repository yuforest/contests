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
	int N, M, X, Y;
	cin >> N >> M >> X >> Y;
	vi x(N);
	vi y(M);
	rep(i, N) cin >> x[i];
	rep(i, M) cin >> y[i];
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());
	int x_last = x[N-1];
	int y_first = y[0];
	string ans = "War";
	rep3(i, x_last+1, y_first+1) {
		if (i > X && i <= Y) ans = "No War";
	}
	cout << ans << endl;

	return 0;

}

// X+1からYまでを全探索すれば良い
// int N, M, X, Y, x[101], y[101];
// //---------------------------------------------------------------------------------------------------
// void _main() {
//   cin >> N >> M >> X >> Y;
//   rep3(i, 0, N) cin >> x[i];
//   rep3(i, 0, M) cin >> y[i];
//   rep3(Z, X + 1, Y + 1) {
//     int ok = 1;
//     rep3(i, 0, N) if (x[i] >= Z) ok = 0;
//     rep3(i, 0, M) if (y[i] < Z) ok = 0;
//     if (ok) {
//       printf("No War\n");
//       return;
//     }
//   }

//   printf("War\n");
// }

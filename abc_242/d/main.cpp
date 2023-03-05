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

// 文字の変化には規則性があり、0番目に着目すると
// A,B,C...
// B,C,A...
// C,A,B...
// のように変化している
int main(){
	string S; cin >> S;
	int Q; cin >> Q;
  // 今の文字からadd分だけ進んで3であまりを取ったもの
	auto g = [&](char s, ll add){
		return char('A'+(s-'A'+add)%3);
	};
	std::function<char(ll,ll)> f = [&](ll t, ll k){
    // このときSのk文字目
		if(t == 0) return S[k];
    // S から t 進んだ文字
		if(k == 0) return g(S[0],t);
    // t,k>0の時
    // 前の回のk/2の値から
    // kが偶数であれば1つ進んだ文字
    // kが奇数であれば2つ進んだ文字
    // となっている
    // A->BC, B->CA, C->AB
    // のようになるので
    // これは再帰的に呼び出され、log(k)回で終了するので高速
		return g(f(t-1, k/2), k%2+1);
	};
	while(Q--){
		ll t,k; cin >> t >> k;
    // 0-indexed
		cout << f(t,k-1) << endl;
	}
}
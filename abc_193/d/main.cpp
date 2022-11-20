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

ll score(string S){
  vector<ll> cnt(10);
  iota(cnt.begin(), cnt.end(), 0);
  for(char c : S) cnt[c - '0'] *= 10;
  return accumulate(cnt.begin(), cnt.end(), 0);
}
int main(){
    ll K;
    string S, T;
    cin >> K >> S >> T;
    vector<ll> cnt(10, K);
    debug(cnt);
    for(char c : S + T) {
      cnt[c - '0']--;
      debug(c);
    }
    debug(cnt);
    ll win = 0;
    // 81通りを全て試す
    for(ll x = 1; x <= 9; x++) for(ll y = 1; y <= 9; y++){
      // 最後の文字を変更する
        S.back() = '0' + x;
        T.back() = '0' + y;
        // Sのスコアが低ければcontinue
        if(score(S) <= score(T)) continue;
        // 残っている数の場合の数を計算する(x==yの時は-1した値をかけている)
        win += cnt[x] * (cnt[y] - (x == y));
    }
    // 残っているカードの数
    const ll rem = 9 * K - 8;
    // 全ての配り方は(9K-8)*(9K-9)であり、勝つ場合の数を全ての配り方で割れば良い
    cout << fixed << setprecision(18) << double(win) / rem / (rem - 1) << endl;
}
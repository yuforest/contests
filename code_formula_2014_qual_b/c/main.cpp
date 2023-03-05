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
const ll INF = ll(1e18);

// cはスワップする回数
// 6文字で最大スワップ回数が3回であればスワップする箇所を全探索すれば良い、
// 最大15*3=45回程度
bool dfs(string &a, string &b, int c){
  // カウントが0になった時にaとbが同じ文字になっているか
  if(c == 0) return a == b;

  // iとi文字以下をスワップ
  rep(i, a.size()) rep(j, i){
    // スワップしてから
    swap(a[i], a[j]);
    // 再起的に探索して
    if(dfs(a, b, c - 1)) return true;
    // もとに戻す
    swap(a[i], a[j]);
  }
  // 全部試してもうまくいかなければfalse
  return false;
}

int main(){
  string a, b; cin >> a >> b;
  const int n = a.size();

  string c, d;
  map<char, int> m;
  bool same = false;
  rep(i,n){
    // 異なる文字をc,dに追加していく
    if(a[i] != b[i]){
      c += a[i];
      d += b[i];
    }else{
      // 文字をカウントして同じ文字が2つ以上あればsameをtrueに
      if(++m[a[i]] >= 2) same = true;
    }
  }

  bool ans = false;
  // 6文字以下で3回で揃えることができるか
  ans |= (int)c.size() <= 6 && dfs(c, d, 3);
  // 4文字以下が異なり、同じ文字が2つ以上あり、2回で揃えることができるか
  ans |= same && (int)c.size() <= 4 && dfs(c, d, 2);
  // 2文字以下が異なり、同じ文字が2つ以上あり、1回で揃えることができるか
  ans |= same && (int)c.size() <= 2 && dfs(c, d, 1);
  // 全く同じ文字列で、同じ文字が2つ以上あれば問題ない
  ans |= same && (int)c.size() <= 0;
  puts(ans ? "YES" : "NO");

  return 0;
}
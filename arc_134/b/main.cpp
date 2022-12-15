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
#define per(i, b) per2(i, 0, b)
#define per2(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
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
  int N;
  string s;
  cin >> N >> s;

  vector<int> cnt(26);
  // 文字の出現回数をカウント
  for (auto c : s) {
      cnt[c - 'a']++;
  }
  // rを最後のインデックスに初期化
  int r = N - 1;

  // 貪欲法で解くことができる
  // 左側から探索していく
  rep(i, N) {
    // iがr以上になったらループを抜ける
    if (i >= r) break;
    // 現在のアルファベット
    int x = s[i] - 'a';
    // 適当な値で初期化
    int mn = 30;
    // 25からデクリメントしていき、値が存在する最も小さい値を探す
    per(c, 26) if (cnt[c]) { mn = c; }
    // 最小の値と現在の値が等しければ、
    // カウントから除いて次のループに移動
    // 今のxの値はもう探索範囲に含まれなくなるため
    if (mn == x) {
      cnt[x]--;
      continue;
    }
    // 異なる場合その最小値が見つかるまで、
    // 途中の値をカウントから除きながら移動する
    while (s[r] - 'a' != mn) {
      cnt[s[r] - 'a']--;
      r--;
    }
    // 見つけた最小値と現在の値を交換する
    swap(s[i], s[r]);
    // 現在の値と最小の値をカウントから除く
    cnt[x]--;
    cnt[mn]--;
    // 右側の探索位置を1つ左に移動する
    r--;
  }
  cout << s << endl;
  return 0;
}
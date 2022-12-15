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
  int N;
  cin >> N;
  vector<int> P(N), pos(N), ans;
  rep(i, N) cin >> P[i];
  // 0-indexedに
  rep(i, N) P[i]--;
  // 現在のiがどの位置にあるかを記録
  rep(i, N) pos[P[i]] = i;
  debug(pos);

  set<int> st;
  // 0からN-1まで探索
  // Pi=1となるiについて真っ先に
  // P[i-1]とP[i]を入れ替える->P[i-2]とP[i-1]を入れ替える->...->P[1]とP[2]を入れ替える
  // という操作をしなければ最終的にP[1]=1とすることができない
  // この操作を行ったあと、 P1​,P2,…Pi−1の値はその時点で確定する
  // よってこの中に Pj!=j なる j があれば、答えは -1
  // Pi以降の部分にも同様の議論を適用していけばよい
  // 計算量O(N)
  rep(i, N) {
    // 既に同じ場合はcontinue
    if(pos[i] == i) continue;
    // iのある位置がiより小さければその時点でbreak
    // この時は操作によって昇順にすることができない
    if(pos[i] < i) break;
    // iの位置がiと同じになるまで操作を行う
    while(pos[i] != i) {
      // 既にiの一つ前の要素との交換が行われている場合はbreak
      if(st.count(pos[i] - 1)) break;
      // iの一つ前にある要素を取得
      int prev = P[pos[i] - 1];
      // iと一つ前の要素の交換を記録
      st.insert(pos[i] - 1);
      // 操作を答えのvectorに記録、1-indexedにしている
      ans.push_back(pos[i] - 1 + 1);
      // iとその一つ前の要素を交換
      swap(P[pos[prev]], P[pos[i]]);
      // ポジションを記録する配列の方も交換
      swap(pos[prev], pos[i]);
    }
  }

  bool sorted = true;
  // i == P[i]にソートされていなければ実現不可能
  rep(i, N) if(P[i] != i) sorted = false;
  // N-1回の操作を行なっていない場合実現不可
  if((int)st.size() != N - 1) sorted = false;
  // ソートされているかどうかによって答えを出し分ける
  if(!sorted) cout << -1 << endl;
  else rep(i, N - 1) cout << ans[i] << endl;

  return 0;
}
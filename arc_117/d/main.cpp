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


// vector<int> works[1 << 18];
int main(){
  int N, M;
  cin >> N >> M;
  int A[N], B[N];
  vvi works(M+1);
  rep(i, N) {
    cin >> A[i] >> B[i];
    // もらえる日がM日より大きければM日までに報酬を受け取れない
    if (A[i] > M) continue;
    works[A[i]].push_back(B[i]);
  }
  ll ans = 0;
  priority_queue<long long> que;
  // M日目まで貪欲的に求める
  for (int i = M-1; i >= 0; --i) {
    // 例えばM-1日目の時は1日で報酬が払われるものをpushする
    for (auto B : works[M-i]) que.push(B);
    // それがなければcontinue
    if (que.empty()) continue;
    // 例えばM-1日時点では1日で報酬が支払われるもの、iがM-3の時には1,2,3日で報酬が支払われるもののうち
    // これまで使われなかった値が入っている
    ans += que.top(); // キューの最大値を足す
    que.pop(); // キューの最大要素を削除
  }
  cout << ans << endl;

  return 0;
}
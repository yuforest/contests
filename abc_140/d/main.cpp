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

// ランレングス圧縮を行う関数
vector<pair<char, int>> runLengthEncoding(string S) {
  int N = S.length();

  vector<pair<char, int>> res;

  for(int i = 0; i < N;) {
    int j = i;
    while(j < N && S[i] == S[j]) j++;
    int count = j - i;
    res.push_back({ S[i], count });
    i = j;
  }
	return res;
}

int main() {
  int N, K;
  string S;
  cin >> N >> K >> S;
  auto rl = runLengthEncoding(S);
  // 区間の数
  int gr = rl.size();
  // 1 回操作するごとに、何らかの値が規則的に変化していく
  // なんらかの意味で Greedy に、順にやっていくとよい
  rep3(k, 0, K) {
    // 3つのグループを1つのグループにできる
    if(3 <= gr)
      gr -= 2;
    // 2つの場合は1つになる
    else if(gr == 2)
      gr = 1;
  }
  // 幸福人数はN-(LかRのグループ数)となる
  // 各グループで1人は幸福でないため
  int ans = N - gr;
  cout << ans << endl;
  return 0;
}


// int main() {
//   int N, K;
//   string S;
//   cin >> N >> K >> S;
//   int a = 0;
//   // グループの切れ目を数える
//   for (int i = 0; i + 1 < N; ++i) if (S[i] != S[i+1]) ++a;
//   // 切れ目はフリップするごとに2つずつ消えていく
//   // 例えば切れ目の数が1の時は2グループあり2人不幸な人がいるので「N-1-切れ目の数」となる
//   cout << N - 1 - max(a - K*2, 0) << endl;
// }
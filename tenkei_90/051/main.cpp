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
#define per3(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define per(i, b) per3(i, 0, b)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(), (x).end()

// 無くても困らない
#define INFTY (1 << 30)

// 浮動小数点の誤差を考慮した等式ですが、使わずに済むなら使わない方が確実です
#define EPS (1e-7)#define equal(a, b) (fabs((a) - (b)) < EPS)

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

long long N, K, P, Answer = 0;
long long A[100];
vector<long long> vec1[100], vec2[100];

int main() {
  // Step #1. 入力
  cin >> N >> K >> P;
  for (int i = 0; i < N; i++) cin >> A[i];

  // Step #2. 半分全列挙
  int mid = N / 2;
  // 0からmid-1までのbit全探索
  for (int i = 0; i < (1 << mid); i++) {
    // cnt1は今の状態数の商品の値段の合計、cnt2は今の状態数の商品の個数
    long long cnt1 = 0, cnt2 = 0;
    for (int j = 0; j < mid; j++) {
      if ((i & (1 << j)) != 0) { cnt1 += A[j]; cnt2 += 1; }
    }
    // 選んだ個数ごとに値段の合計を保存
    vec1[cnt2].push_back(cnt1);
  }
  // midからN-1までのbit全探索
  for (int i = 0; i < (1 << (N - mid)); i++) {
    long long cnt1 = 0, cnt2 = 0;
    for (int j = 0; j < N - mid; j++) {
      if ((i & (1 << j)) != 0) { cnt1 += A[mid + j]; cnt2 += 1; }
    }
    vec2[cnt2].push_back(cnt1);
  }

  // Step #3. 答えを求める
  for (int i = 0; i <= N; i++) {
    // 個数ごとの値段の合計をソートする
    sort(vec1[i].begin(), vec1[i].end());
    sort(vec2[i].begin(), vec2[i].end());
  }
  // 個数をKまでの個数を全探索
  for (int h = 0; h <= K; h++) {
    // vec1を全探索する、2^(N/2)通りの組み合わせがある
    for (int i = 0; i < (int)vec1[h].size(); i++) {
      // vec2の値段の合計がP - vec1[h][i]以下となる商品の個数を二分探索で求める
      // 見つかったインデックスは、0-indexedなので、それを足すと、その値段以下の商品の個数となる
      int pos1 = lower_bound(vec2[K - h].begin(), vec2[K - h].end(), P - vec1[h][i] + 1) - vec2[K - h].begin();
      Answer += (long long)pos1;
    }
  }

  // Step #4. 出力
  cout << Answer << endl;
  return 0;
}
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


// 探索範囲を絞る解法
// int main() {
//   int X, Y, Z, K; cin >> X >> Y >> Z >> K;
//   vector<long long> A(X), B(Y), C(Z);
//   for (int i = 0; i < X; ++i) cin >> A[i];
//   for (int i = 0; i < Y; ++i) cin >> B[i];
//   for (int i = 0; i < Z; ++i) cin >> C[i];

//   // A + B の上位 K 個
//   vector<long long> AB;
//   for (int i = 0; i < X; ++i) for (int j = 0; j < Y; ++j) AB.push_back(A[i] + B[j]);
//   // 大きい順にソート
//   sort(AB.begin(), AB.end(), greater<long long>());
//   // K個だけに絞っている、AとBの前列挙のうち上位K個に入らないものは、合計した後に上位K個以内に入ることはあり得ない
//   AB.resize(K);

//   // AB と C
//   vector<long long> ABC;
//   for (int i = 0; i < AB.size(); ++i) for (int j = 0; j < Z; ++j) ABC.push_back(AB[i] + C[j]);
//   sort(ABC.begin(), ABC.end(), greater<long long>());

//   // 出力
//   for (int k = 0; k < K; ++k) cout << ABC[k] << endl;
// }

// priority queueで解く
using Data = pair<long long, vector<int> >;
int main() {
  vector<long long> N(3);
  int K;
  for (int i = 0; i < 3; ++i) cin >> N[i]; cin >> K;
  vector<vector<long long> > v(3);
  for (int iter = 0; iter < 3; ++iter) {
    v[iter].resize(N[iter]);
    for (int i = 0; i < N[iter]; ++i) cin >> v[iter][i];
    // 降順ソート
    sort(v[iter].begin(), v[iter].end(), greater<long long>());
  }
  priority_queue<Data> que;
  // 既にpush済みのものを記録する
  set<Data> se;
  // まず最大のものをpush
  que.push(Data(v[0][0] + v[1][0] + v[2][0], vector<int>({0, 0, 0})));
  // K回出力する
  for (int k = 0; k < K; ++k) {
    // 最大値が大きいものを取ってくる
    auto c = que.top();
    que.pop();
    cout << c.first << endl;

    // 次の三候補
    for (int iter = 0; iter < 3; ++iter) {
      // 各個数制限に引っかからない限り続ける
      if (c.second[iter] + 1 < N[iter]) {
        // 現在の数字から、今の数字のケーキの美味しさをひいて、次の美味しさをプラス
        long long sum = c.first - v[iter][c.second[iter]] + v[iter][c.second[iter] + 1];
        // イテレータを進める
        auto num = c.second;
        num[iter]++;
        auto d = Data(sum, num);

        // すでに push されたもの以外、同じ組み合わせが何回も出てくる可能性があるため
        if (!se.count(d)) se.insert(d), que.push(d);
      }
    }
  }
}

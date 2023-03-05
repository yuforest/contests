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

int H, W;
int P[19][10009];

// Rの配列の中で同じ数字が最大の数を返す
int maximum_same(vector<int> R) {
  map<int, int> Map; int ret = 0;
  for (int i = 0; i < R.size(); i++) {
    Map[R[i]] += 1;
    ret = max(ret, Map[R[i]]);
  }
  return ret;
}

int main() {
  // Step #1. “ü—Í
  cin >> H >> W;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) cin >> P[i][j];
  }

  // Step #2. ‘S’Tõ
  int Answer = 0;
  // 高さ(行)をbit全探索
  for (int i = 1; i < (1 << H); i++) {
    vector<int> R;
    // 列を全探索、縦に見ていく
    for (int j = 0; j < W; j++) {
      int idx = -1; bool flag = false;
      // 列ごとに行を見ていく
      for (int k = 0; k < H; k++) {
        // 選んだ行でなければcontinue
        if ((i & (1 << k)) == 0) continue;
        // 最初だけセットする
        if (idx == -1) idx = P[k][j];
        // もしも縦に見ている途中で異なる数字があればその数字は選べない
        else if (idx != P[k][j]) flag = true;
      }
      if (flag == false) R.push_back(idx);
    }

    int cntH = 0, cntW = maximum_same(R);
    for (int j = 0; j < H; j++) {
      if ((i & (1 << j)) != 0) cntH += 1;
    }
    // 最大値更新、選んでいる行*選べる中で最も大きい列の数がグリッドに含まれる数字の数
    Answer = max(Answer, cntH * cntW);
  }
  cout << Answer << endl;
  return 0;
}
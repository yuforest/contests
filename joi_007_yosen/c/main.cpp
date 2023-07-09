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

int ans[2010];
int N, M;

int main() {
  ll N;
  cin >> N;
  vl A(N);
  rep(i, N) cin >> A[i];
  sort(all(A));
  vl B;
  rep3(i, 1, 2*N+1) {
    if (!binary_search(all(A), i)) B.push_back(i);
  }
  debug(A);
  debug(B);
  ll ans = 0;
  vl used(2*N+1);
  used[0] = true;
  ll turn = 0;
  ll cur = 0;
  ll a_count = N;
  ll b_count = N;
  while(true) {
    if (a_count == 0 || b_count == 0) {
      break;
    }
    if (turn == 0) {
      ll idx = 0;
      while (true) {
        if (idx == A.size()) break;
        if (used[A[idx]]) {
          idx++;
          continue;
        }
        if (A[idx] <= cur) {
          idx++;
          continue;
        }
        break;
      }
      if (idx == A.size()) {
        cur = 0;
      } else {
        cur = A[idx];
        used[cur] = true;
        a_count--;
      }
    } else {
      ll idx = 0;
      while (true) {
        if (idx == B.size()) break;
        if (used[B[idx]]) {
          idx++;
          continue;
        }
        if (B[idx] <= cur) {
          idx++;
          continue;
        }
        break;
      }
      if (idx == B.size()) {
        cur = 0;
      } else {
        cur = B[idx];
        used[cur] = true;
        b_count--;
      }
    }
    debug(cur);
    debug(used);
    turn = 1 - turn;
  }
  cout << b_count << endl;
  cout << a_count << endl;
}
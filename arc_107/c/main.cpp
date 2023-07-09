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


using mint = modint998244353;
const long long MOD = 998244353;
long long fact(int x){
  long long ans = 1;
  for (int i = 1; i <= x; i++){
    ans = ans * i % MOD;
  }
  return ans;
}

int main(){
  int N, K;
  cin >> N >> K;
  vector<vector<int>> a(N, vector<int>(N));
  for (int i = 0; i < N; i++){
    for (int j = 0; j < N; j++){
      cin >> a[i][j];
    }
  }
  long long ans = 1;
  // 行swapしかできない場合の答え*列swapしかできない場合の答えが答えとなる
  // 列swapをしても行swapの条件には一切影響がない
  for (int d = 0; d < 2; d++){
    vector<vector<int>> E(N);
    for (int i = 0; i < N; i++){
      for (int j = i + 1; j < N; j++){
        bool ok = true;
        // ある列か行に対して、要素の和がKを超えていたらダメ
        for (int k = 0; k < N; k++){
          if (a[i][k] + a[j][k] > K){
            ok = false;
          }
        }
        // 双方向に辺を張る
        // このときスワップ可能なので、重複を避けるためにi < jとしている
        if (ok){
          E[i].push_back(j);
          E[j].push_back(i);
        }
      }
    }
    vector<bool> used(N, false);
    for (int i = 0; i < N; i++){
      if (!used[i]){
        used[i] = true;
        int cnt = 1;
        // BFSで連結成分のサイズを求める
        queue<int> Q;
        Q.push(i);
        while (!Q.empty()){
          int v = Q.front();
          Q.pop();
          // 隣接する頂点を見ていく
          for (int w : E[v]){
            if (!used[w]){
              used[w] = true;
              cnt++;
              Q.push(w);
            }
          }
        }
        // 連結成分のサイズの階乗をかける
        ans *= fact(cnt);
        ans %= MOD;
      }
    }
    // 行と列を入れ替えて同じことを行う
    for (int i = 0; i < N; i++){
      for (int j = i + 1; j < N; j++){
        swap(a[i][j], a[j][i]);
      }
    }
  }
  cout << ans << endl;
}
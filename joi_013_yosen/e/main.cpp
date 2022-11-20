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

int in() {
  int a;
  scanf("%d", &a);
  return a;
}

typedef vector<int> vint;
typedef pair<int, int> pint;
typedef vector<pint> vpint;

const int INF = 1001001001;

#define pb push_back
#define mp make_pair

struct Taxi {
  int C, R;
  vint edges, edges2;
  bool flag;
  int ans;
  Taxi () : flag(false), ans(INF) {
  }
}
taxis[5010];

int main() {
  int N, K;
  N = in();
  K = in();

  for (int i = 0; i < N; i++) {
    taxis[i].C = in();
    taxis[i].R = in();
  }
  for (int i = 0; i < K; i++) {
    int to, from;
    to = in() - 1;
    from = in() - 1;
    taxis[to].edges.pb(from);
    taxis[from].edges.pb(to);
  }

  // make a graph
  // 最初の街から全探索
  // 町 i から町 j までタクシーを途中で乗り換えることなく行けるかどうかを調べる
  rep(i, N) {
    queue<int> q;
    q.push(i);
    // 現在の街のタクシーの移動可能範囲分だけループ
    rep(k, taxis[i].R) {
      queue<int> q2;
      while (!q.empty()) {
        int n = q.front();
        q.pop();
        // 現在の街からいける街を全探索
        rep(j, taxis[n].edges.size()) {
          int to = taxis[n].edges[j];
          // 訪問済みでなければ訪問済みにしてq2にpush
          if (!taxis[to].flag) {
            taxis[to].flag = true;
            // q2にpushしているのでqから直接いける街のフラグが変わるだけ
            q2.push(to);
          }
        }
      }
      // 現在の街が次の探索のスタートとなる
      q = q2;
    }
    // iの街から1つのタクシーでいける範囲をedge2に追加する
    rep(k, N) {
      if (i != k && taxis[k].flag) {
        // iから乗り継ぎなしでいける街
        taxis[i].edges2.pb(k);
      }
      // フラグを未訪問に戻しておく
      taxis[k].flag = false;
    }
  }

  // Dijkstra
  priority_queue<pint> pq;
  pq.push(mp(0, 0));
  while (pq.size()) {
    pint a = pq.top();
    pq.pop();
    // コストに-をかけて、正の数字に戻す
    int cost = - a.first;
    int n = a.second;
    // 現在の街にくるための最小コストが既存の最小コストより小さければ更新
    if (cost < taxis[n].ans) {
      taxis[n].ans = cost;
      // 目的地ならbreak
      if (n == N - 1) {
        break;
      }
      // edge2(乗り換えなしでいける街)を全探索
      for (vint::iterator iter = taxis[n].edges2.begin(); iter != taxis[n].edges2.end(); ++iter) {
        // 確定済みでない街なら、コストと頂点をpush
        if (taxis[*iter].ans == INF) {
          // 降順なので-をかけておく、今までのコストにこの街のタクシー料金を追加
          pq.push(mp(- (cost + taxis[n].C), *iter));
        }
      }
    }
  }

  cout << taxis[N - 1].ans << endl;
  return 0;
}

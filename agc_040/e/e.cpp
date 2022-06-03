// g++ -o c.out c.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc233/tasks/abc233_c
// oj t -c "./c.out"
// oj s https://atcoder.jp/contests/abc233/tasks/abc233_c c.cpp


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
long long minimum_time = 0;
vector<bool> used(200007, false);
vector<vector<int>> G1(10, vector<int>());
vector<vector<int>> G2(10, vector<int>());
long long K[200007];
long long T[200007];
#include <bits/stdc++.h>
using namespace std;

#define MAX_V 200007
#define INF 10000000

struct edge {
  int from; //出発点
  int to;   //到達点
  int cost; //移動コスト
};

int main()
{
  long long N, M;
  cin >> N >> M;
  long long H[N+1];
  rep1(i, N) {
    cin >> H[i];
  }
  long long U[M+1];
  long long V[M+1];
  rep1(i, M) {
    cin >> U[i] >> V[i];
  }
  vector<edge> edges; //移動の情報を保存する
  int d[N+1]; //始点から添え字の頂点に行くのにかかるコスト

    // int V; //頂点の数
    // int side; //辺の数
    // int S; //始点
    // int G; //終点
  fill(d, d+N+1, INF); //すべての頂点をINFにする
  d[1] = 0; //始点を0にする

  for (int i = 1; i <= M; i++) {
    struct edge add1;
    add1.from = U[i];
    add1.to = V[i];
    // 高い時
    if (H[U[i]] >= H[V[i]]) {
      add1.cost = -1LL * (H[U[i]] - H[V[i]]);
  } else {
      add1.cost = 2 * (H[V[i]] - H[U[i]]);
    }
    edges.push_back(add1);
    struct edge add2;
    add2.from = V[i];
    add2.to = U[i];
    // 高い時
    if (H[V[i]] >= U[V[i]]) {
      add2.cost = -1LL * (H[V[i]] - H[U[i]]);
    } else {
      add2.cost = 2 * (H[U[i]] - H[V[i]]);
    }
    edges.push_back(add2);
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < (int)edges.size(); j++) {

        struct edge e = edges[j];

        if (d[e.to] > d[e.from] + e.cost) {  //移動した後のコストが小さいと、頂点のコストを更新
          d[e.to] = d[e.from] + e.cost;
          if (i == N-1) {         //頂点の数と同じ回数ループすると、負の閉路があるのでループをぬける
              // cout << "negative loop" << endl;
              break;
          }
        }
    }
  }
  long long ans = -2 * 100000000;
  for (int i = 1; i <= N; i++) {
    // cout << d[i] * -1LL << endl;
    ans = max(ans, d[i] * -1LL);
  }
  cout << ans << endl;
}
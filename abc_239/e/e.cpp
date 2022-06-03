// g++ -o c.out c.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc233/tasks/abc233_c
// oj t -c "./c.out"
// oj s https://atcoder.jp/contests/abc233/tasks/abc233_c c.cpp


#include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9+7;
using Edge = struct { int to; int cost; };

int n,q;
vector<int> x;
vector<vector<int>> g;

vector<vector<int>> memo;
vector<int> dfs(int cur, int prev) {
  vector<int> res = { x[cur] };
  for(int nv: g[cur]) {
    if (nv == prev) continue;
    for(auto t: dfs(nv, cur)) {
      res.push_back(t);
    }
  }
  sort(res.rbegin(),res.rend());
  REP(i, min((int)res.size(), 20) ) {
    memo[cur].push_back(res[i]);
  }

  return memo[cur];
}

int main() {
  cin >> n >> q;

  x.resize(n);
  REP(i,n) cin >> x[i];

  g.resize(n);
  REP(i,n-1) {
    int a,b;
    cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  memo.resize(n);
  dfs(0, -1);

  REP(i,q) {
    int v,k;
    cin >> v >> k;
    v--; k--;

    cout << memo[v][k] << endl;
  }

  return 0;
}
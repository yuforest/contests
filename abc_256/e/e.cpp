// g++ -o c.out c.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc233/tasks/abc233_c
// oj t -c "./c.out"
// oj s https://atcoder.jp/contests/abc233/tasks/abc233_c c.cpp


#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
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

int main() {
  int N;
  cin >> N;
  vector<int> X(N), C(N);
  for (auto& x : X) cin >> x, --x;
  for (auto& x : C) cin >> x;
  atcoder::dsu uf(N);
  long long ans = 0;
  for (int i = 0; i < N; i++) {
    if (uf.same(i, X[i]) == false) {
      uf.merge(i, X[i]);
      continue;
    }
    int cur = C[i], v = i;
    do {
      v = X[v];
      cur = min(cur, C[v]);
    } while (v != i);
    ans += cur;
  }
  cout << ans << "\n";
}

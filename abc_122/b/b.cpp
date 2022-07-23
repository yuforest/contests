// g++ -o b.out b.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc233/tasks/abc233_b
// oj t -c "./b.out"
// oj s https://atcoder.jp/contests/abc233/tasks/abc233_b b.cpp


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main()
{
  int N, M, C;
  cin >> N >> M >> C;
  int B[M];
  rep(i, M) {
    cin >> B[i];
  }
  int A[N][M];
  rep (i, N) {
    rep (j, M) {
      cin >> A[i][j];
    }
  }
  int ans = 0;
  rep (i, N) {
    int tmp = C;
    rep (j, M) {
      tmp += A[i][j] * B[j];
    }
    if (tmp > 0) ans++;
  }
  cout << ans << endl;
  return 0;
}
// g++ -o b.out b.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc226/tasks/abc226_b
// oj t -c "./b.out"
// oj s https://atcoder.jp/contests/abc226/tasks/abc226_b b.cpp


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main()
{
  int N, M, X;
  cin >> N >> M >> X;
  int A[M];
  rep(i, M) {
    cin >> A[i];
  }
  int ans1 = 0;
  for (int i = 0; i < M; i++) {
    if (A[i] < X) ans1++;
  }
  int ans2 = 0;
  for (int i = M-1; i >= 0; i--) {
    if (A[i] > X) ans2++;
  }
  int ans = min(ans1, ans2);
  cout << ans << endl;
  return 0;
}
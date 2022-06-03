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
  int N, D, X;
  cin >> N >> D >> X;
  vector<int> A(N);
  rep(i, N) {
    cin >> A[i];
  }
  int ans = X;
  rep(i, N) {
    int tmp = 0;
    for (int j = 1; j <= D; j += A[i]) {
      tmp++;
    }
    ans += tmp;
  }
  cout << ans << endl;
  return 0;
}
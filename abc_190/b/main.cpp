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
  int N, S, D;
  cin >> N >> S >> D;
  int X[N], Y[N];
  rep(i, N) cin >> X[i] >> Y[i];
  string ans = "No";
  rep(i, N) {
    if (X[i] >= S) continue;
    if (Y[i] <= D) continue;
    ans = "Yes";
  }
  cout << ans << endl;
}
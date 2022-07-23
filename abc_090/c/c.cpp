// g++ -o c.out c.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc226/tasks/abc226_c
// oj t -c "./c.out"
// oj s https://atcoder.jp/contests/abc226/tasks/abc226_c c.cpp


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
long long minimum_time = 0;
vector<bool> used(200007, false);
vector<int> G[1 << 18];
long long K[200007];
long long T[200007];

int main()
{
  ll N, M;
  cin >> N >> M;
  ll ans;
  if (N >= 3 && M >= 3) {
    ans = (N - 2) * (M - 2);
  } else if (N == 1 && M == 1) {
    ans = 1;
  } else if (N == 1 || M == 1) {
    ans = max(N, M) - 2;
  } else {
    ans = 0;
  }
  cout << ans << endl;
}
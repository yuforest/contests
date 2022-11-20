// g++ -o b.out b.cpp -std=c++11
// oj d https://atcoder.jp/contests/abc219/tasks/abc219_b
// oj t -c "./b.out"
// oj s https://atcoder.jp/contests/abc219/tasks/abc219_b b.cpp


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{

  int N;
  cin >> N;
  int l[N], r[N];
  ll ans = 0;
  rep(i, N) {
    cin >> l[i] >> r[i];
    ans += r[i]  - l[i] + 1;
  }
  cout << ans << endl;
}
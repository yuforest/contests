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

  ll N;
  ll X;
  cin >> N >> X;
  ll V[N], P[N];
  rep(i, N) {
    cin >> V[i] >> P[i];
  }
  ll sum = 0;
  int ans = -1;
  rep(i, N) {
    ll concentration = V[i] * P[i];
    // cout << concentration << endl;
    sum += concentration;
    if (sum > X * 100) {
      ans = i + 1;
      break;
    }
  }
  cout << ans << endl;

}
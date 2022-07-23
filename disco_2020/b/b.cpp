// g++ -o b.out b.cpp -std=c++11
// oj d https://atcoder.jp/contests/abc219/tasks/abc219_b
// oj t -c "./b.out"
// oj s https://atcoder.jp/contests/abc219/tasks/abc219_b b.cpp


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{

  ll N;
  cin >> N;
  ll A[N+1];
  rep1(i, N) {
    cin >> A[i];
  }
  vector<ll> cumulative(N+1);
  cumulative[0] = 0;

  rep1(i, N) {
    cumulative[i] = cumulative[i-1] + A[i];
  }
  ll length = cumulative[N];
  double half = length / 2.0;
  auto it = lower_bound(cumulative.begin(), cumulative.end(), half);
  // for (auto e: cumulative) {
  //   cout << e << endl;
  // }
  ll index = it - cumulative.begin();
  ll ans1 = cumulative[index] - (cumulative[N] - cumulative[index]);
  ll ans2 = (cumulative[N] - cumulative[index-1]) - cumulative[index-1];
  ll ans = min(ans1, ans2);
  cout << ans << endl;
}
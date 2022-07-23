// g++ -o a.out a.cpp -std=c++17
// oj d https://atcoder.jp/contests/agc_012/tasks/agc_012_a
// oj t -c "./a.out"
// oj s https://atcoder.jp/contests/agc_012/tasks/agc_012_a a.cpp

#include <bits/stdc++.h>
using namespace std;
int n, k;
int c[300005];
map<int, int> mp;
long long mod = 1000000007;
using ll = long long;

int main(void)
{
  ll N, A, B;
  cin >> N >> A >> B;
  ll ans;
  if (A > B) {
    ans = 0;
  } else if (N == 1 && A != B) {
    ans = 0;
  } else {
    ans = (B - A) * (N - 2) + 1;
  }
  cout << ans << endl;
}
// g++ -o c.out c.cpp -std=c++11
// oj d https://atcoder.jp/contests/abc216/tasks/abc216_c
// oj t -c "./c.out"
// oj s https://atcoder.jp/contests/abc216/tasks/abc216_c c.cpp

#include <bits/stdc++.h>
using namespace std;
int n, k;
int c[300005];
map<int, int> mp;
long long mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main(void)
{
  int N;
  cin >> N;
  int a[N];
  double avg = 0;
  rep(i, N) {
    cin >> a[i];
    avg += a[i];
  }
  avg /= (double) N;
  int int_avg = round(avg);
  int ans = 0;
  rep(i, N) {
    ans += pow(abs(a[i] - int_avg), 2);
  }
  cout << ans << endl;

}
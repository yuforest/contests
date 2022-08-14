// g++ -o c.out c.cpp -std=c++11
// oj d https://atcoder.jp/contests/abc219/tasks/abc219_c
// oj t -c "./c.out"
// oj s https://atcoder.jp/contests/abc219/tasks/abc219_c c.cpp

#include <bits/stdc++.h>
using namespace std;
int n, k;
int c[300005];
map<int, int> mp;
long long mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

vector<ll> red_to_blue(11);
vector<ll> blue_to_blue(11);

ll ans = 0;

ll N, X, Y;

int main(void)
{
  int N;
  cin >> N;
  int A[N+1];
  rep(i, N) {
    cin >> A[i+1];
  }
  ll ans = 0;
  ll normal_count = 0;
  for(int i = 1; i <= N; i++) {
    if (A[i] == i) {
      normal_count++;
    }
  }
  ans += normal_count * (normal_count-1) / 2;
  ll tmp = 0;
  for(int i = 1; i <= N; i++) {
    if (i == A[i]) continue;
    if (A[A[i]] == i) {
      tmp++;
    }
  }
  ans += tmp / 2;
  cout << ans << endl;

  return 0;


}
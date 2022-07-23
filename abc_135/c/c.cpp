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
  ll N;
  cin >> N;

  ll A[N+1];
  ll B[N];
  rep(i, N+1) {
    cin >> A[i];
  }
  rep(i, N) {
    cin >> B[i];
  }
  ll ans = 0;
  rep(i, N) {
    // i, i+1番目を見るがiから埋めていく
    ll i_help = min(A[i], B[i]);
    A[i] -= i_help;
    B[i] -= i_help;
    ans += i_help;
    ll i1_help = min(A[i+1], B[i]);
    A[i+1] -= i1_help;
    B[i] -= i1_help;
    ans += i1_help;
  }
  cout << ans << endl;
}
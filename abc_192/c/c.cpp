// g++ -o c.out c.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc190/tasks/abc190_c
// oj t -c "./c.out"
// oj s https://atcoder.jp/contests/abc190/tasks/abc190_c c.cpp


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
  set<ll> expressed;
  for (ll i = 2; i * i <= N; i++) {
    ll x = i * i;
    while(x <= N) {
      expressed.insert(x);
      x *= i;
    }
    // for (ll j = 2; j <= 50; j++) {
    //   ll val = pow(i, j);
    //   if (val <= N) {
    //     expressed.insert(val);
    //   }
    // }
  }
  ll ans = N - expressed.size();
  cout << ans << endl;
}
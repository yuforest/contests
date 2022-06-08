// g++ -o c.out c.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc226/tasks/abc226_c
// oj t -c "./c.out"
// oj s https://atcoder.jp/contests/abc226/tasks/abc226_c c.cpp


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
long long minimum_time = 0;
vector<bool> used(200007, false);
vector<int> G[1 << 18];
long long K[200007];
long long T[200007];
const int inf = INT_MAX / 2;
const ll infl = 1LL << 60;


int main()
{
  long long N;
  cin >> N;
  ll ans = infl;
  rep1(i, 1000100) {
    if (N % i == 0) {
      ans = min(ans, i + (N / i) - 2);
    }
  }
  cout << ans << endl;
}
// g++ -o a.out a.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc235/tasks/abc235_a
// oj t -c "./a.out"
// oj s https://atcoder.jp/contests/abc235/tasks/abc235_a a.cpp

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

int main(void)
{
  ll N, A, B;
  cin >> N >> A >> B;
  ll diff = B - A;
  ll ans;
  if (diff % 2 == 0) {
    ans = diff / 2;
  } else {
    // 2人のいずれかが1かNに到達した後、1回調整し、もう一方がいる方に向かう
    ans = min(A - 1, N - B) + 1 + ((B - A - 1) / 2);
  }
  cout << ans << endl;

  return 0;
}
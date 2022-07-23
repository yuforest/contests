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
ll MOD = 1000000007;

int main()
{

  ll N, K;
  cin >> N >> K;
  ll A[N];
  rep(i, N) {
    cin >> A[i];
  }
  ll ans = 0;
  for (int i = 0; i < N; i++) {
    ll migi = 0, zentai = 0;
    // 現在より右にある転倒数
    for (int j = i; j < N; j++)
      if (A[i] > A[j]) migi++;
    // 全体で自分より小さいもの
    for (int j = 0; j < N; j++)
      if (A[i] > A[j]) zentai++;

    // 現在の位置より右にあるものをK回掛けている、配列の中に現れるもの
    ans += migi * K % MOD;
    ans %= MOD;
    // 全体の中で出現するものKC2回を掛ける
    ans += (K - 1) * K / 2 % MOD * zentai % MOD;
    ans %= MOD;
  }
  cout << ans << endl;
}
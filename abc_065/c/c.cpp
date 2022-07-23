// g++ -o a.out a.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc222/tasks/abc222_a
// oj t -c "./a.out"
// oj s https://atcoder.jp/contests/abc222/tasks/abc222_a c.cpp

#include <bits/stdc++.h>
using namespace std;
int n, k;
int c[300005];
map<int, int> mp;
long long mod = 1000000007;
using ll = long long;

long long permutation(ll N) {
  ll ans = 1;
  for (ll i = 1; i<= N; i++) {
    ans *= i;
    ans %= mod;
  }
  return ans;
}

int main(void)
{
  ll N, M;
  cin >> N >> M;

  if (N == M) {
    cout << ((permutation(N) * permutation(M)) % mod) * 2 % mod << endl;
  } else if (abs(N-M) == 1) {
    cout << (permutation(N) * permutation(M)) % mod << endl;
  } else {
    cout << 0 << endl;
  }

}
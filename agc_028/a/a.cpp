// g++ -o a.out a.cpp -std=c++11
// oj d https://atcoder.jp/contests/abc217/tasks/abc217_a
// oj t
// oj s https://atcoder.jp/contests/abc217/tasks/abc217_a a.cpp

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
// greatest common divisor
ll gcd(ll a, ll b) { return a ? gcd(b % a, a) : b; }
// least common multiple
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

int main() {
	ll N, M;
  cin >> N >> M;
  string S, T;
  cin >> S >> T;
  ll L = lcm(N, M);
  ll G = gcd(N, M);
  vector<ll> array_S;
  vector<ll> array_T;
  for (int i = 0; i < G; i++) {
    if (S[N / G * i] != T[M / G * i]) {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << L << endl;
}
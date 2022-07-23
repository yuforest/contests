// g++ -o a.out a.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc256/tasks/abc256_a
// oj t -c "./a.out"
// oj s https://atcoder.jp/contests/abc256/tasks/abc256_a a.cpp

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
int n, k;
int c[300005];
map<int, int> mp;
long long mod = 1000000007;
using ll = long long;

int main(void)
{
  ll N;
  cin >> N;
  cout << setprecision(14) << pow(2, N) << endl;
  return 0;
}
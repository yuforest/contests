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

int main(void)
{
  long long N;
  cin >> N;

  vector<long long> count(N + 1, 0);
  for (long long i = 2LL; i <= N; ++i) {
    long long k = i;
    for (long long j = 2LL; j <= i; ++j) {
      while (k % j == 0) {
        ++count.at(j);
        k /= j;
      }
    }
  }

  long long answer = 1;
  for (long long i = 2LL; i <= N; ++i) {
    answer *= (count.at(i) + 1);
    answer %= mod;
  }

  cout << answer << endl;
}
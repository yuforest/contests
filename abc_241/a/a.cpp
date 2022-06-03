// g++ -o a.out a.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc235/tasks/abc235_a
// oj t -c "./a.out"
// oj s https://atcoder.jp/contests/abc235/tasks/abc235_a a.cpp

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
int n, k;
int c[300005];
map<int, int> mp;
long long mod = 1000000007;

int main(void)
{
  int a[10];
  rep(i, 10) {
    cin >> a[i];
  }
  int count = 0;
  int current = 0;
  while(true) {
    current = a[current];
    if (count == 2) break;
    count++;
  }
  cout << current << endl;
  return 0;
}
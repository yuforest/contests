// g++ -o a.out a.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc235/tasks/abc235_a
// oj t -c "./a.out"
// oj s https://atcoder.jp/contests/abc235/tasks/abc235_a a.cpp

#include <bits/stdc++.h>
using namespace std;
int n, k;
int c[300005];
map<int, int> mp;
long long mod = 1000000007;

long long func(long long x) {
  return pow(x, 2) + 2 * x + 3;
}

int main(void)
{
  string num;
  cin >> num;
  int a, b, c;
  a = num[0] - '0';
  b = num[1] - '0';
  c = num[2] - '0';
  int abc, bca, cab;
  abc = a * 100 + b * 10 + c;
  bca = b * 100 + c * 10 + a;
  cab = c * 100 + a * 10 + b;
  cout << abc + bca + cab << endl;

  return 0;
}
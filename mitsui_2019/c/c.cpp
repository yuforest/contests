// g++ -o c.out c.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc226/tasks/abc226_c
// oj t -c "./c.out"
// oj s https://atcoder.jp/contests/abc226/tasks/abc226_c c.cpp


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

bool ans = false;
void dfs(int remaining, int quotient) {
  if (quotient == 0) {
    if (remaining == 0) ans = true;
    return;
  }
  dfs(remaining - 0, quotient-1);
  dfs(remaining - 1, quotient-1);
  dfs(remaining - 2, quotient-1);
  dfs(remaining - 3, quotient-1);
  dfs(remaining - 4, quotient-1);
  dfs(remaining - 5, quotient-1);
}

int main()
{
  int X;
  cin >> X;
  int quotient = X / 100;
  int remaining = X % 100;
  int count = 0;
  for (int i = 5; i >= 1; i--) {
    count += remaining / i;
    remaining = remaining % i;
  }
  if (count <= quotient) {
    cout << 1 << endl;
  } else {
    cout << 0 << endl;
  }
  // dfs(remaining, quotient);
}
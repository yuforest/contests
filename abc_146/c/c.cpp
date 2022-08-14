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
#define rep(i, n) for (int i = 0; i < (n); ++i)

ll A, B, X;
//---------------------------------------------------------------------------------------------------
ll check(ll x) {
  ll dx = to_string(x).length();
  return A * x + B * dx;
}
//---------------------------------------------------------------------------------------------------
int main() {
  cin >> A >> B >> X;
  ll ok = 0, ng = 1000000001;
  // 二分探索(okとngの差が1になるまで)
  while (ok + 1 != ng) {
    ll md = (ok + ng) / 2;
    if (check(md) <= X) ok = md;
    else ng = md;
  }
  cout << ok << endl;
}
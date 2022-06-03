// g++ -o c.out c.cpp -std=c++11
// oj d https://atcoder.jp/contests/abc217/tasks/abc217_d
// oj t -c "./d.out"
// oj s https://atcoder.jp/contests/abc217/tasks/abc217_d d.cpp

#include <bits/stdc++.h>
using namespace std;
int n, k;
int c[300005];
map<int, int> mp;
long long mod = 1000000007;

int main(void)
{
  int L, Q;
  cin >> L >> Q;
  set<int> que;
  que.insert(0);
  que.insert(L);
  for (int i = 0; i < Q; i++) {
    int c, x;
    cin >> c >> x;
    if (c == 1) {
      que.insert(x);
    } else if (c == 2) {
      auto it = que.lower_bound(x);
      int ans = *it - *prev(it);
      cout << ans << endl;
    }
  }
}
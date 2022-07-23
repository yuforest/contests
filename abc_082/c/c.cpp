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
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main(void)
{
  int N;
  cin >> N;
  int a[N];
  map<int, int> mp;
  rep(i, N) {
    cin >> a[i];
    mp[a[i]]++;
  }
  ll ans = 0;
  for(auto e: mp) {
    if (e.first == e.second) continue;
    if (e.first < e.second) ans += e.second - e.first;
    if (e.first > e.second) ans += e.second;
  }
  cout << ans << endl;

}
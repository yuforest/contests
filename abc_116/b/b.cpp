// g++ -o b.out b.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc226/tasks/abc226_b
// oj t -c "./b.out"
// oj s https://atcoder.jp/contests/abc226/tasks/abc226_b b.cpp


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main()
{
  int s;
  cin >> s;
  map<int, int> mp;
  mp[s]++;
  int ans;
  for (int i = 1; i <= 1000000; i++) {
    if (s % 2 == 0) {
      s = s / 2;
    } else {
      s = 3 * s + 1;
    }
    if (mp[s] == 0) {
      mp[s]++;
    } else {
      ans = i + 1;
      break;
    }
  }
  cout << ans << endl;
}
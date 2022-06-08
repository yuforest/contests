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
  int X;
  cin >> X;
  set<int> s;
  for (int i = 1; i <= 1000; i++) {
    for (int j = 2; j <= 10; j++) {
      int val = pow(i, j);
      if (val <= 1000 && val <= X) {
        s.insert(val);
      }
    }
  }
  // イテレータから値を取得
  int ans = *s.rbegin();
  cout << ans << endl;
}
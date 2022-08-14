// g++ -o b.out b.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc216/tasks/abc216_b
// oj t -c "./b.out"
// oj s https://atcoder.jp/contests/abc216/tasks/abc216_b b.cpp


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int k, t; cin >> k >> t;
  priority_queue<pair<int,int> > que;
  rep (i, t) {
    int a; cin >> a;
    que.emplace(a, i);
  }
  int ans = 0;
  int last = -1;
  while (!que.empty()) {
    int a, i;
    // 要素をまとめて取り出している
    tie(a, i) = que.top(); que.pop();
    // 同じケーキでない時は1引いて残っていれば再プッシュ
    if (i != last) {
      last = i;
      a -= 1;
      if (a) que.emplace(a, i);
    } else {
      // キューが空ならそのケーキを連続で食べるしかない
      if (que.empty()) { ans += a; break; }
      int b, j;
      // 要素をまとめて取り出している
      // 違うケーキを再度取り出す
      tie(b, j) = que.top();
      que.pop();
      last = j;
      b -= 1;
      que.emplace(a, i);
      if (b) que.emplace(b, j);
    }
  }
  cout << ans << endl;
  return 0;

}
// g++ -o b.out b.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc226/tasks/abc226_b
// oj t -c "./b.out"
// oj s https://atcoder.jp/contests/abc226/tasks/abc226_b b.cpp


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main()
{
  int A, B, M;
  cin >> A >> B >> M;
  vector<int> a(A);
  vector<int> b(B);
  rep(i, A) cin >> a[i];
  rep(i, B) cin >> b[i];
  int a_min = 100007;
  rep(i, A) {
    a_min = min(a_min, a[i]);
  }
  int b_min = 100007;
  rep(i, B) {
    b_min = min(b_min, b[i]);
  }
  int ans = a_min + b_min;
  for (int i = 0; i < M; i++) {
    int tmp = 0;
    int x, y, c;
    cin >> x >> y >> c;
    tmp = a[x-1] + b[y-1] - c;
    ans = min(ans, tmp);
  }
  cout << ans << endl;
  return 0;
}
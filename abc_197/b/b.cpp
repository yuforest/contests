// g++ -o b.out b.cpp -std=c++11
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
  int H, W, X, Y;
  cin >> H >> W >> X >> Y;
  X--;Y--;
  string S[H];
  rep(i, H) cin >> S[i];
  int ans = 1;
  // 上に見ていく
  for(int i = X-1; i >= 0; i--) {
    if (S[i][Y] == '#') break;
    else ans++;
  }
  // 下に見ていく
  for(int i = X+1; i < H; i++) {
    if (S[i][Y] == '#') break;
    else ans++;
  }
  // 左に見ていく
  for(int i = Y-1; i >= 0; i--) {
    if (S[X][i] == '#') break;
    else ans++;
  }
  // 左に見ていく
  for(int i = Y+1; i < W; i++) {
    if (S[X][i] == '#') break;
    else ans++;
  }
  cout << ans << endl;
}
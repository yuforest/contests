// g++ -o a.out a.cpp -std=c++11
// oj d https://atcoder.jp/contests/abc213/tasks/abc213_a
// oj t
// oj s https://atcoder.jp/contests/abc213/tasks/abc212_a a.cpp

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int H, W;
  cin >> H >> W;
  vector<string> s(H);
  int walkX[4] = {0, 1, 0, -1};
  int walkY[4] = {1, 0, -1, 0};
  for (int i = 0; i < H; ++i) {
    cin >> s.at(i);
  }

  string ans = "Yes";
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      if (s.at(i).at(j) == '.') continue;
      bool connected = false;
      for (int k = 0; k < 4; ++k) {
        int ny = i + walkY[k];
        int nx = j + walkX[k];
        if (ny < 0 || nx < 0 || ny > H - 1|| nx > W - 1) continue;
        if (s.at(ny).at(nx) == '#') connected = true;
      }
      if (!connected) ans = "No";
    }
  }
  cout << ans << endl;
}
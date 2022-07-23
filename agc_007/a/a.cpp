// g++ -o a.out a.cpp -std=c++11
// oj d https://atcoder.jp/contests/agc003/tasks/agc003_a
// oj t
// oj s https://atcoder.jp/contests/agc003/tasks/agc003_a a.cpp

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

vector<vector<bool>> used(8, vector<bool>(8, false));
bool ans = false;
string A[8];
int H, W;

vector<pair<int, int>> moves = {{1, 0}, {0, 1}};

// void dfs(int x, int y) {
//   if (used[x][y] = true) return;
// 	used[x][y] = true;
//   if (used[H-1][W-1]) {
//     ans = true;
//     return;
//   }

//   for (auto move: moves) {
//     int new_x = x + move.first;
//     int new_y = y + move.second;

//     if (new_x < W && new_y < H && A[new_x][new_y] == '#') {
//       dfs(new_x, new_y);
//     }
//   }
// }

int main()
{
  cin >> H >> W;
  rep(i , H) {
    cin >> A[i];
  }
  int count  = 0;
  rep(i, H) {
    rep(j, W) {
      if (A[i][j] == '#') count++;
    }
  }
  if (count == H + W - 1) {
    cout << "Possible" << endl;
  } else {
    cout << "Impossible" << endl;
  }
  return 0;
}
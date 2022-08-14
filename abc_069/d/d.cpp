// g++ -o d.out d.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc222/tasks/abc222_d
// oj t -c "./d.out"
// oj s https://atcoder.jp/contests/abc222/tasks/abc222_d d.cpp

#include <bits/stdc++.h>
using namespace std;
int n, k;
int c[300005];
map<int, int> mp;
// long long mod = 1000000007;
// 縦軸が弁当の種類、横軸がたこ焼きの数、配列の値が鯛焼きの数
int dp[301][301][301];
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main(void)
{
  int H, W, N;
  cin >> H >> W >> N;
  int A[N+1];
  rep(i, N) {
    cin >> A[i+1];
  }
  vector<vector<int>> grid(H, vector<int>(W, 0));
  int current_w = 0;
  int current_h = 0;
  int current = 1;
  while(true) {
    // cout << current_h << endl;
    // cout << current_w << endl;
    // cout << endl;
    // 現在の数字を入れていく
    grid[current_h][current_w] = current;
    A[current]--;
    if (A[current] == 0) current++;

    // Hの高さの偶奇によって終了条件が異なる
    if (H % 2 == 0) {
      if (current_h == H-1 && current_w == 0) break;
    } else {
      if (current_h == H-1 && current_w == W-1) break;
    }

    // 偶数行の時右に動く
    if (current_h % 2 == 0) {
      // 端まで来たら下に移動
      if (current_w == W-1) {
        current_h++;
      } else {
        current_w++;
      }
    } else {
      // 奇数行の時左に動く
      // 端まで来たら下に移動
      if (current_w == 0) {
        current_h++;
      } else {
        current_w--;
      }
    }
  }
  for(int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cout << grid[i][j];
      if (j != W-1) cout << " ";
    }
    cout << endl;
  }
}
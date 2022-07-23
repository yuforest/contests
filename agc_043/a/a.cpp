// g++ -o a.out a.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc235/tasks/abc235_a
// oj t -c "./a.out"
// oj s https://atcoder.jp/contests/abc235/tasks/abc235_a a.cpp

#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const vector<int> dx = {1, 0};
const vector<int> dy = {0, 1};
const long long INF = 1LL<<60;
int H, W;
vector<string> fi;

long long solve() {
    vector<vector<long long>> dp(H, vector<long long>(W, INF));
    // 最初のマスが壁ならコスト1追加
    if (fi[0][0] == '#') dp[0][0] = 1;
    else dp[0][0] = 0;

    for (int i = 0; i < H; ++i) {
      for (int j = 0; j < W; ++j) {
        for (int dir = 0; dir < 2; ++dir) {
          // 移動先の座標を計算
          int ni = i + dx[dir], nj = j + dy[dir];
          if (ni >= H || nj >= W) continue;
          int add = 0;
          if (fi[ni][nj] == '#' && fi[i][j] == '.') add = 1;
          // 移動先と現在のマスから移動するコストの低い方を採用
          chmin(dp[ni][nj], dp[i][j] + add);
        }
      }
    }
    // 最後のマスに移動するコストを返す
    return dp[H-1][W-1];
}

int main() {
    cin >> H >> W;
    fi.resize(H);
    for (int i = 0; i < H; ++i) cin >> fi[i];
    cout << solve() << endl;
}

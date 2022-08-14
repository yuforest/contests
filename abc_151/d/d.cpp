// g++ -o d.out d.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc174/tasks/abc174_d
// oj t -c "./d.out"
// oj s https://atcoder.jp/contests/abc174/tasks/abc174_d d.cpp

#include <bits/stdc++.h>
using namespace std;
int c[300005];
map<int, int> mp;
// long long mod = 1000000007;
// 縦軸が弁当の種類、横軸がたこ焼きの数、配列の値が鯛焼きの数
int dp[301][301][301];
vector<int> G[1 << 18];

#define rep(i, n) for (int i = 0; i < (n); ++i)

vector<pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int H, W;
string S[20];

int explore(int h, int w) {
  queue<vector<int>> que;
  que.push({h, w});
  int tmp = 0;
  vector<vector<int>> distances(H, vector<int>(W, -1));
  distances[h][w] = 0;
  // cout << "h: " << h << " " << "w: " << w << endl;
  while(!que.empty()) {
    vector<int> current = que.front();
    int current_h = current[0];
    int current_w = current[1];
    // 最大の距離を更新
    tmp = max(tmp, distances[current_h][current_w]);
    // cout << "h: " << current_h << " " << "w: " << current_w << endl;
    que.pop();
    // 4方向の探索
    for(int i = 0; i < directions.size(); i++) {
      pair<int, int> direction = directions[i];
      int next_h = current_h + direction.first;
      int next_w = current_w + direction.second;
      // 迷路から出ない場合
      if (next_h >= 0 && next_h < H && next_w >= 0 && next_w < W) {
        // 遷移先が壁ではない
        if (S[next_h][next_w] == '#') continue;
        // 既に探索済み
        if (distances[next_h][next_w] != -1) continue;
        // 次の遷移先の距離を確定
        distances[next_h][next_w] = distances[current_h][current_w] + 1;
        // 次の遷移先をpush
        que.push({next_h, next_w});
      }
    }
  }
  return tmp;
}

using namespace std;
using ll = long long;
int main()
{
  cin >> H >> W;
  rep(i, H) {
    cin >> S[i];
  }
  int ans = 0;
  // スタート地点を全探索
  for(int h = 0; h < H; h++) {
    for(int w = 0; w < W; w++) {
      vector<int> start = {h, w, 0};
      // スタートが壁の場合は探索しない
      if (S[h][w] == '#') continue;
      ans = max(ans, explore(h, w));
    }
  }
  cout << ans << endl;
}

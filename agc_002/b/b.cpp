// g++ -o b.out b.cpp -std=c++11
// oj d https://atcoder.jp/contests/abc219/tasks/abc219_b
// oj t -c "./b.out"
// oj s https://atcoder.jp/contests/abc219/tasks/abc219_b b.cpp


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{

  int N, M;
  cin >> N >> M;
  int x[M];
  int y[M];
  rep(i, M) {
    cin >> x[i] >> y[i];
  }

  vector<bool> is_red(N+1, false);
  vector<int> balls(N+1, 1);
  is_red[1] = true;
  for(int i = 0; i < M; i++) {
    int tmp_x = x[i];
    int tmp_y = y[i];

    // 箱のボールが1つで赤いボールが入っている可能性がある時
    if (balls[tmp_x] == 1 && is_red[tmp_x]) {
      is_red[tmp_x] = false;
      is_red[tmp_y] = true;
    }
    if (balls[tmp_x] > 1 && is_red[tmp_x]) {
      is_red[tmp_y] = true;
    }
    balls[tmp_x]--;
    balls[tmp_y]++;
  }
  int ans = 0;
  for(int i = 1; i <= N; i++) {
    if (is_red[i]) ans++;
  }
  cout << ans << endl;
}

#include <bits/stdc++.h>
using namespace std;

int BFS(vector<string> vec, int s_y, int s_x, int g_y, int g_x) {
  int y, x, depth;        // キューから取り出した座標
  struct Corr
  {
    int y;
    int x;
    int depth;
  };
  queue<Corr> q;
  vector<int> y_vec = {0, 0, -1, +1};
  vector<int> x_vec = {-1, +1, 0, 0};

  while (!q.empty())
  {
    Corr now = q.front();
    q.pop();
    y = now.y;
    x = now.x;
    depth = now.depth;

    // 停止条件：現在の座標がゴールなら深さを返す
    if (y == g_y && x == g_x) {
      return depth;
    }

    // 上下左右 4 方向を探索．進むことができればキューに格納する．
    for (int i = 0; i < 4; ++i)
    {
      Corr next = {y + y_vec[i], x + x_vec[i], depth + 1};
      if (0 <= next.y && next.y <= N - 1 && 0 <= next.x && next.x <= M - 1 && vec[next.y][next.x] == '.' && vec[next.y][next.x] != '#')
      {
        vec[next.y][next.x] = 'x'; // 同じ場所を探索しないようにする
        q.push(next);
      }
    }
  }
  return 0;
}

int main()
{
  // char C;
  // cin >> C;
  // C++;
  // cout << C << endl;
  // int N,K,M;
  // cin >> N >> K >> M;
  // vector<int> A(N);

  // for (int i;i < N-1; i++) {
  //   int point;
  //   cin >> point;
  //   A.at(i) = point;
  // }

  // int sum = accumulate(A.begin(), A.end(), 0);
  // if(M*N - sum <= 0) {
  //   cout << 0 << endl;
  // } else if (M * N - sum > K) {
  //   cout << -1 << endl;
  // } else {
  //   cout << M * N - sum << endl;
  // }

  // int N,M;
  // int correct_count = 0;
  // int penalty = 0;
  // cin >> N >> M;
  // vector<int> answered(N+1, 0);
  // vector<int> penalties(N+1, 0);
  // for (int i=0;i < M;i++) {
  //   int question_num;
  //   cin >> question_num;
  //   string is_correct;
  //   cin >> is_correct;
  //   if (is_correct == "AC" && answered.at(question_num) == 0)
  //   {
  //     correct_count++;
  //     answered.at(question_num) = 1;
  //   }
  //   else if (is_correct == "WA" && answered.at(question_num) == 0)
  //   {
  //     penalties.at(question_num) += 1;
  //   }
  // }
  // for (int i = 1; i <= N; i++) {
  //   if (answered.at(i) == 1) {
  //     penalty += penalties.at(i);
  //   }
  // }
  // cout << correct_count << " " << penalty << endl;

  int H, W;
  cin >> H >> W;

  // vector<vector<string>> maze(H, vector<string>(W, "."));
  vector<string> maze(H, "");
  vector<vector<int>> start_and_goals;

  for (int i =0; i < H; i++) {
    string part;
    cin >> part;
    maze.at(i) = part;
  }

  for (int i= 0; i < H; i++) {
    if () {
      start_and_goals.push_back();
    }
  }

  int count = BFS(maze);

  for (int i = 0; i < H; i++)
  {
    cout << maze.at(i) << endl;
  }
}


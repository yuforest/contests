#include <bits/stdc++.h>
using namespace std;

// int sum(vector<vector<int>> matrix, int H, int W)
// {
//   int sum = 0;
//   for (int i = 0; i < H; i++) {
//     for (int j = 0; j < W; j++)
//     {
//       sum += matrix.at(i).at(j);
//     }
//   }
//   return sum;
// }

int main()
{
  // int H, W, N;
  // cin >> H >> W >> N;
  // vector<vector<int>> matrix(H, vector<int>(W, 0));

  // int count = 0;
  // int sum = 0;
  // while (true) {
  //   if (sum >= N) {
  //     break;
  //   }

  //   if (H >= W) {
  //     count++;
  //     sum += H;
      // for (int i = 0; i < H; i++) {
      //   for (int j = 0; j < W; j++) {
      //     matrix.at(i).at(j) = 1;
      //   }
      //   sum = accumulate(matrix.begin(), matrix.end(), 0);
      //   cout << sum << endl;
      //   count++;
      //   if (sum > N)
      //   {
      //     break;
      //   }
      // }
    // } else {
    //   count++;
    //   sum += W;
      // for (int j = 0; j < W; j++)
      // {
      //   for (int i = 0; i < H; i++)
      //   {
      //     matrix.at(i).at(j) = 1;
      //   }
      //   sum = accumulate(matrix.begin(), matrix.end(), 0);
      //   cout << sum << endl;
      //   count++;
      //   if (sum > N)
      //   {
      //     break;
      //   }
      // }
  //   }
  // }
  // cout << count << endl;
  int N;
  cin >> N;
  vector<vector<int>> robots(N, vector<int>(2, 0));
  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    int l;
    cin >> l;
    robots.at(i).at(0) = x;
    robots.at(i).at(1) = l;
  }
  vector<int> excludes;
  sort(&robots[0], &robots[N], [](auto &x, auto &y) { return x[1] > y[1]; });
  int ans = N;
  for (int i = 0; i < N; i++)
  {
    bool skip = false;
    for (int k = 0; k < excludes.size(); k++) {
      if (excludes.at(k) == i)
      {
        skip = true;
        break;
      }
    }
    if (skip) {
      continue;
    }
    for (int j = i + 1; j < N; j++) {
      int min = robots.at(i).at(0) - robots.at(i).at(1);
      int max = robots.at(i).at(0) + robots.at(i).at(1);
      int current_min = robots.at(j).at(0) - robots.at(j).at(1);
      int current_max = robots.at(j).at(0) + robots.at(j).at(1);
      if (current_min > min && current_min < max) {
        // cout << min << " " << max << " " << current << endl;
        ans -= 1;
        excludes.push_back(j);
      } else if (current_max > min && current_max < max) {
        // cout << min << " " << max << " " << current << endl;
        ans -= 1;
        excludes.push_back(j);
      }
    }
  }
  cout << ans << endl;
}

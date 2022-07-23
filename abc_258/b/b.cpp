// g++ -o b.out b.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc256/tasks/abc256_b
// oj t -c "./b.out"
// oj s https://atcoder.jp/contests/abc256/tasks/abc256_b b.cpp


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
map<int, int> mp;

int main()
{
  int N;
  cin >> N;
  vector<vector<int>> A(N, vector<int>(N));

  // vector<vector<bool>> used(N, vector<int>(N, false));
  // bool used[N][N];

  int start_i = 0;
  int start_j = 0;
  int start = 0;
  rep(i, N) {
    string val;
    cin >> val;
    rep(j, N) {
      A[i][j] = val[j] - '0';
      // if (A[i][j] > start) {
      //   start_i = i;
      //   start_j = j;
      //   start = A[i][j];
      // }
    }
  }

  int count = 0;
  vector<vector<int>> directions = {{-1, -1}, {0, -1}, {1, -1}, {-1, 0}, {1, 0}, {-1, 1}, {0, 1}, {1, 1}};
  ll ans = 0;
  rep(x, N) {
    rep(y, N) {
      int start_i = x;
      int start_j = y;
      int start = A[start_i][start_j];
      rep(i, 8) {
        string tmp = "";
        int current_i = start_i;
        int current_j = start_j;
        int current = start;
        vector<int> direction = directions[i];
        tmp += to_string(current);
        rep(j, N-1) {
          int next_i;
          int next_j;
          if (current_i + direction[0] > N-1) {
            next_i = 0;
          } else if (current_i + direction[0] < 0) {
            next_i = N-1;
          } else {
            next_i = current_i + direction[0];
          }

          if (current_j + direction[1] > N-1) {
            next_j = 0;
          } else if (current_j + direction[1] < 0) {
            next_j = N-1;
          } else {
            next_j = current_j + direction[1];
          }

          tmp += to_string(A[next_i][next_j]);
          current_i = next_i;
          current_j = next_j;
        }
        // cout << tmp << endl;
        ans = max(ans, stoll(tmp));
      }
    }
  }
  cout << ans << endl;
  return 0;
}
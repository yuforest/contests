#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  vector<vector<int>> A(3, vector<int>(3));
  rep (i, 3) {
    rep (j, 3) {
      cin >> A.at(i).at(j);
    }
  }
  // rep(i, 3)
  // {
  //   rep(j, 3)
  //   {
  //     int N;
  //     cout << A[i][j] << endl;
  //   }
  // }
  int N;
  cin >> N;
  rep(i, N) {
    int b;
    cin >> b;
    rep(i, 3) {
      rep(j, 3) {
        if (A.at(i).at(j) == b) {
          A[i][j] = -1;
        }
      }
    }
  }
  bool bingo = false;
  rep(i, 3)
  {
    if (A[i][0] == A[i][1] && A[i][1] == A[i][2] && A[i][2] == A[i][0]) {
      bingo = true;
    }
    if (A[0][i] == A[1][i] && A[1][i] == A[2][i] && A[2][i] == A[0][i]) {
      bingo = true;
    }
  }
  if (A[0][0] == A[1][1] && A[0][0] == A[2][2] && A[1][1] == A[2][2])
  {
    bingo = true;
  }
  if (A[0][2] == A[1][1] && A[1][1] == A[2][0] && A[2][0] == A[0][2])
  {
    bingo = true;
  }
  if (bingo) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
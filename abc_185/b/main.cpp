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

  int N, M, T;
  cin >> N >> M >> T;
  int A[M], B[M];
  string ans = "Yes";
  rep(i, M) cin >> A[i] >> B[i];
  int current_time = 0;
  int current_buttery = N;

  rep(i, M) {
    current_buttery -= A[i] - current_time;
    if (current_buttery <= 0) {
      ans = "No";
      break;
    }
    current_buttery = min(N, current_buttery + (B[i] - A[i]));
    current_time = B[i];
  }
  current_buttery -= T - current_time;
  if (current_buttery <= 0) {
    ans = "No";
  }
  cout << ans << endl;
}
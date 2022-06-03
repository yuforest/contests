// g++ -o b.out b.cpp -std=c++11
// oj d https://atcoder.jp/contests/abc210/tasks/abc210_b
// oj t -c "./b.out"
// oj s https://atcoder.jp/contests/abc210/tasks/abc210_b b.cpp


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int N;
  string S;
  cin >> N >> S;

  string ans = "Takahashi";
  for (int i = 0; i < N; ++i)
  {
    if (S.at(i) == '1') {
      break;
    }
    if (ans == "Takahashi") {
      ans  = "Aoki";
    } else {
      ans = "Takahashi";
    }
  }
  cout << ans << endl;
}
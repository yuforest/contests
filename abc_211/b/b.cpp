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
  string S[4];

  for (int i = 0; i < 4; ++i) {
    cin >> S[i];
  }


  bool check[4];
  for (int i = 0; i < 4; i++)
  {
    check[i] = false;
  }

  for (int i = 0; i < 4; ++i) {
    if (S[i] == "H") {
      check[0] = true;
    }
    if (S[i] == "2B") {
      check[1] = true;
    }
    if (S[i] == "3B") {
      check[2] = true;
    }
    if (S[i] == "HR") {
      check[3] = true;
    }
  }
  string ans = "Yes";
  for (int i = 0; i < 4; ++i) {
    if (check[i] == false) {
      ans = "No";
      break;
    }
  }
  cout << ans << endl;

}
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

  string S[3], T;
  cin >> S[0] >> S[1] >> S[2] >> T;
  string ans = "";
  for (int i = 0; i < T.size(); ++i) {
    int index = T[i] - '0' - 1;
    ans += S[index];
  }
  cout << ans << endl;
}
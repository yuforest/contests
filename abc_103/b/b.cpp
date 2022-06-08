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

  string S, T;
  cin >> S >> T;
  int size = S.size();
  string ans = "No";
  rep(i, size) {
    string rotated = S[size-1] + S.substr(0, size-1);
    S = rotated;
    if (rotated == T) ans = "Yes";
  }
  cout << ans << endl;

}
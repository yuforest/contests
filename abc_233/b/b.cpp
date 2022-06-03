// g++ -o b.out b.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc233/tasks/abc233_b
// oj t -c "./b.out"
// oj s https://atcoder.jp/contests/abc233/tasks/abc233_b b.cpp


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main()
{
  int L, R;
  string S;
  cin >> L >> R >> S;
  L--;
  R--;
  string ans = "";
  for (int i = 0;i < S.size(); i++) {
    if (i >= L && i <= R) {
      ans.push_back(S[L + R - i]);
    } else {
      ans.push_back(S[i]);
    }
  }
  cout << ans << endl;
  return 0;
}
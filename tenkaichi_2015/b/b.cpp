// g++ -o b.out b.cpp -std=c++11
// oj d https://atcoder.jp/contests/abc216/tasks/abc216_b
// oj t -c "./b.out"
// oj s https://atcoder.jp/contests/abc216/tasks/abc216_b b.cpp


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  string S;
  getline(cin, S);
  int count = 0;
  string ans = "";
  for (int i = 0; i < S.size(); ++i) {
    if (S[i] == ' ') {
      count++;
    } else if (S[i] != ' ' && count > 0) {
      ans.push_back(',');
      ans.push_back(S[i]);
      count = 0;
    } else {
      ans.push_back(S[i]);
    }
  }
  cout << ans << endl;
}

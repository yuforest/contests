// g++ -o a.out a.cpp -std=c++11
// oj d https://atcoder.jp/contests/agc003/tasks/agc003_a
// oj t
// oj s https://atcoder.jp/contests/agc003/tasks/agc003_a a.cpp

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int N;
  string s, t;
  cin >> N >> s >> t;
  int ans = 2 * N;
  string tmp = "";
  int match_count = 0;
  for (int i = N-1; i >= 0; i--) {
    tmp = s[i] + tmp;
    if (t.substr(0, tmp.size()) == tmp) {
      match_count = max(match_count, (int)tmp.size());
    }
  }
  cout << ans - match_count << endl;
  return 0;
}
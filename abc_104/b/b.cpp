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

  string S;
  cin >> S;
  string ans = "AC";
  if (S[0] != 'A') ans = "WA";
  bool appeared = false;
  for (int i = 2; i < S.size()-1; i++) {
    if (S[i] == 'C') {
      if (appeared) {
        ans = "WA";
        break;
      }
      appeared = true;
    }
  }
  if (!appeared) {
    ans = "WA";
  }
  rep(i, S.size()) {
    if (S[i] != 'A' && S[i] != 'C') {
      if(S[i] < 'a' || S[i] > 'z') {
        ans = "WA";
      }
    }
  }
  cout << ans << endl;
}
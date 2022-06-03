#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  string S;
  cin >> S;
  string ans = "Yes";
  rep(i, S.size()) {
    if ((i+1)%2 == 0) {
      if (S.at(i) != 'L' && S.at(i) != 'U' && S.at(i) != 'D') {
        ans = "No";
      }
    } else {
      if (S.at(i) != 'R' && S.at(i) != 'U' && S.at(i) != 'D')
      {
        ans = "No";
      }
    }
  }
  cout << ans << endl;
}
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
  string ans = S;
  string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  rep(i, S.size()) {
    rep(j, alpha.size()) {
      if (S.at(i) == alpha.at(j)) {
        if (j + N > alpha.size() - 1)
        {
          ans.at(i) = alpha.at(j + N - 26);
        }
        else
        {
          ans.at(i) = alpha.at(j + N);
        }
      }
    }
  }
  cout << ans << endl;
}
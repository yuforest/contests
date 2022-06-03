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

  int ans = 0;
  rep(i, N) {
    if (S.at(i) == 'A' && i+1 <= N-1) {
      if (S.at(i+1) == 'B' && i+2 <= N-1) {
        if (S.at(i+2) == 'C') {
          ans++;
        }
      }
    }
  }
  cout << ans << endl;
}
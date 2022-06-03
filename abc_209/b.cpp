#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int N, X;
  cin >> N >> X;
  vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A.at(i);
  }
  string ans = "Yes";
  for (int i = 0; i < N; ++i)
  {
    if ((i + 1) % 2 == 0) {
      X -= A.at(i) - 1;
    } else {
      X -= A.at(i);
    }
    if (X < 0) {
      ans = "No";
      break;
    }
  }
  cout << ans << endl;
}


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int N;
  cin >> N;
  int ans;
  if (N%2 == 0) {
    ans = (N/2);
  } else {
    ans = N/2 + 1;
  }
  cout << ans << endl;
}
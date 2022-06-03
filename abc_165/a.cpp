#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int N, A, B;
  cin >> N >> A >> B;
  string ans = "NG";
  for (int i = A; i <= B; i++) {
    if (i % N == 0) {
      ans = "OK";
    }
  }
  cout << ans << endl;
}
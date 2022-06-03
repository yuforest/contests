#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
#define rep_ex(i, n) for (int i = 0; i <= (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int A, B;
  cin >> A >> B;
  int cnt = 0;
  int concent_number = 0;
  int ans;
  while (true) {
    if (B == 1) {
      ans = 0;
      break;
    }
    concent_number += A;
    if (cnt != 0) {
      concent_number -= 1;
    }
    cnt++;
    if (concent_number >= B) {
      ans = cnt;
      break;
    }
  }
  cout << ans << endl;
}
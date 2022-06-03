#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int N, M;
  cin >> N >> M;
  vector<int> ans(N, -1);
  bool ok = true;
  rep(i, M) {
    int dig;
    int num;
    cin >> dig >> num;
    if (ans[dig-1] <= 0) {
      ans[dig-1] = num;
    } else {
      if (ans[dig-1] != num) {
        ok = false;
      }
    }
  }
  if (N == 3 && ans[0] == 0) {
    ok = false;
  }
  if (N == 2 && ans[0] == 0) {
    ok = false;
  }
  if (!ok) {
    cout << -1 << endl;
    return 0;
  }
  int ans_num = 0;
  for (int i = N-1; i >= 0;i--) {
    if (ans[i] == -1) {
      if (N == 2) {
        if (i==0) {
          ans[i] = 1;
        } else {
          ans[i] = 0;
        }
      }
      if (N == 3) {
        if (i == 0)
        {
          ans[i] = 1;
        }
        else {
          ans[i] = 0;
        }
      }
      if(N == 1) {
        ans[i] = 0;
      }
    }
    ans_num += pow(10, N-i-1) * ans[i];
  }
  cout << ans_num << endl;
  return 0;
}
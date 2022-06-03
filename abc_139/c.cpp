#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int N;
  cin >> N;
  vector<int> H(N);
  rep(i, N) {
    cin >> H[i];
  }
  int current_min;
  int ans = 0;
  int tmp_ans = 0;
  rep(i, N) {
    if (i == 0) {
      current_min = H[0];
      continue;
    }
    if (current_min < H[i]) {
      ans = max(ans, tmp_ans);
      tmp_ans = 0;
      current_min = H[i];
    } else {
      tmp_ans++;
      current_min = min(current_min, H[i]);
    }
  }
  ans = max(ans, tmp_ans);

  cout << ans << endl;
}
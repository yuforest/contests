#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int N, M;
  cin >> N >> M;
  int L[M], R[M];
  int left_card = 0;
  int right_card = 100001;
  rep (i, M) {
    cin >> L[i] >> R[i];
  }
  rep (i, M) {
    left_card = max(left_card, L[i]);
    right_card = min(right_card, R[i]);
  }
  int ans = max(0, right_card - left_card + 1);
  cout << ans << endl;
}
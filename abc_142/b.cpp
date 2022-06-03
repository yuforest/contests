#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int N, K;
  cin >> N >> K;
  vector<int> h(N);
  int ans = 0;
  rep(i, N) {
    cin >> h.at(i);
    if (h.at(i) >= K) {
      ans++;
    }
  }
  cout << ans << endl;
}
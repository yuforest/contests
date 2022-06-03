#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  double N;
  int K;
  cin >> N >> K;
  double ans = 0;
  rep(i, N) {
    int score = i+1;
    int cnt = 0;
    while (true) {
      if (score >= K) {
        break;
      }
      score *= 2;
      cnt += 1;
    }
    double val = (1.0 / N) * pow(0.5, cnt);
    ans += val;
  }
  cout << std::setprecision(12) << ans << endl;
}
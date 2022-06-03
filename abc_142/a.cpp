#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  double N;
  cin >> N;
  double ans;
  double count;
  rep1(i, N) {
    if (i % 2 == 1) {
      count++;
    }
  }
  ans = count / N;
  cout << std::setprecision(10) << scientific << ans << endl;
}
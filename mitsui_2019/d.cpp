#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
#define rep_ex(i, n) for (int i = 0; i <= (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int N;
  string S;
  cin >> N >> S;
  ll ans = 0;
  vector<bool> d1(10);
  vector<bool> d2(100);
  vector<bool> d3(1000);
  rep(i, N) {
    int d = S.at(i) - '0';
    rep(j, 100) {
      if (d2[j]) {
        d3[j*10+d] = true;
      }
    }
    rep(j, 10) {
      if (d1[j]) {
        d2[10*j+d] = true;
      }
    }
    d1[d] = true;
  }
  rep(i, 1000) {
    if (d3.at(i) == true) {
      ans++;
    }
  }
  cout << ans << endl;

}
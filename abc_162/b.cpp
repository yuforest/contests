#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int N;
  cin >> N;
  ll sum = 0;
  for(int i = 1; i <= N; i++) {
    if (i % 15 == 0) {
      continue;
    }
    if (i % 5 == 0) {
      continue;
    }
    if (i % 3 == 0) {
      continue;
    }
    sum += i;
  }
  cout << sum << endl;
}

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int N;
  cin >> N;
  vector<int> d(N);
  rep(i, N) {
    cin >> d.at(i);
  }
  int sum = 0;
  for (int i = 0; i < N; i++) {
    for (int j = i+1; j < N; j++) {
      sum += d.at(i) * d.at(j);
    }
  }
  cout << sum << endl;
}
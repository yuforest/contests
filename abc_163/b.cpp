#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int N, M;
  cin >> N >> M;
  vector<int> A(N);
  rep(i, M) {
    cin >> A.at(i);
  }
  int ans;
  ans = N;
  rep(i, M) {
    N -= A.at(i);
  }
  if(N < 0) {
    cout << -1 << endl;
  } else {
    cout << N << endl;
  }
}
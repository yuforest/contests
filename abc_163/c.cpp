#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int N;
  cin >> N;
  vector<int> A(N-1);
  rep(i, N-1) {
    cin >> A.at(i);
  }
  vector<int> ans(N, 0);
  rep(i, N-1) {
    int num = A.at(i);
    ans.at(num-1) += 1;
  }
  rep(i, N) {
    cout << ans.at(i) << endl;
  }
}
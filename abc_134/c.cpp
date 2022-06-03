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
  vector<int> A(N);
  rep (i, N) {
    cin >> A[i];
  }
  vector<int> sorted_A = A;
  sort(sorted_A.begin(), sorted_A.end(), greater<int>());
  rep(i, N) {
    if (sorted_A[0] == A[i]) {
      cout << sorted_A[1] << endl;
    } else {
      cout << sorted_A[0] << endl;
    }
  }
  return 0;
}
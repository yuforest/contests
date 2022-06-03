#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define SIZE_OF_ARRAY(array) (sizeof(array) / sizeof(array[0]))

int main()
{
  double N, M;
  cin >> N >> M;
  vector<int> A(N);
  rep(i, N) {
    cin >> A.at(i);
  }
  int sum = accumulate(A.begin(), A.end(), 0);
  sort(A.begin(), A.end(), greater<int>());
  rep(i, M) {
    if (A.at(i) < (sum * (1 / (4 * M))))
    {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

long long int N, M, K, T, H, W, L, R;

int main()
{
  cin >> N >> K;
  vector<pair<long long int, long long int>> vp(N);
  for (auto &i : vp)
    cin >> i.first >> i.second;
  sort(vp.begin(), vp.end());
  for (auto i : vp)
  {
    if (K >= i.first)
    {
      K += i.second;
    }
  }
  cout << K << endl;
}


// 10 1000000000
// 1 1000000000
// 2 1000000000
// 3 1000000000
// 4 1000000000
// 5 1000000000
// 6 1000000000
// 6 1000000000
// 6 1000000000
// 6 1000000000
// 6 1000000000



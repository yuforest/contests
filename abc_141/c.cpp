#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int N, K, Q;
  cin >> N >> K >> Q;
  int A[Q];
  rep(i, Q) {
    cin >> A[i];
  }
  map<int, int> mp;
  rep(i, Q) {
    mp[A[i]]++;
  }
  rep1(i, N) {
    // 減点された回数
    int minus_count = Q - mp[i];
    if (K - minus_count <= 0) {
      cout << "No" << endl;
    } else {
      cout << "Yes" << endl;
    }
  }
  return 0;
}
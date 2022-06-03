#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int A, B;
  cin >> A >> B;
  for (int i = 1; i <= 1000; i++) {
    int val_a = floor(i * 0.08);
    int val_b = floor(i * 0.1);
    if (val_a == A && val_b == B) {
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}
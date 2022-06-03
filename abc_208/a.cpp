#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  double A, B;
  cin >> A >> B;
  if (B / A <= 6 && B / A >= 1)
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
}
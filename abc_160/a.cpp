#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  string S;
  cin >> S;
  if (S.at(2) == S.at(3) && S.at(4) == S.at(5))
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
}
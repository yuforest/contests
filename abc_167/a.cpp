#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  string S, T;
  cin >> S >> T;
  T = T.substr(0, S.size());
  if (S == T)
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
}
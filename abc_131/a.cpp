#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  string S;
  cin >> S;
  if (S.at(0) == S.at(1) || S.at(1) == S.at(2) || S.at(2) == S.at(3)) {
    cout << "Bad" << endl;
  } else {
    cout << "Good" << endl;
  }
}
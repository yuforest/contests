#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  string N;
  cin >> N;
  rep(i, N.size()) {
    if (N.at(i) == '7'){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}
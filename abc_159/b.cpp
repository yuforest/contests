#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  string S;
  cin >> S;
  bool ans = true;
  int N = S.size();
  int half_N = N / 2;

  rep(i, N / 2) {
    if (S.at(i) != S.at(N - i - 1)) {
      ans = false;
      break;
    }
  }
  rep(i, half_N / 2) {
    if (S.at(i) != S.at(half_N - i - 1)) {
      ans = false;
      break;
    }
  }
  reverse(S.begin(), S.end());
  rep(i, half_N / 2) {
    if (S.at(i) != S.at(half_N - i - 1)) {
      ans = false;
      break;
    }
  }
  if (ans) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  
}
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  string S;
  cin >> S;
  vector<string> week = {
    "MON",
    "TUE",
    "WED",
    "THU",
    "FRI",
    "SAT",
    "SUN",
  };
  int index;
  rep(i, week.size()) {
    if (week.at(i) == S) {
      index = i;
    }
  }
  if (S == "SUN") {
    cout << 7 << endl;
  } else {
    cout << 6 - index << endl;
  }
}
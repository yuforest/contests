// g++ -o a.out a.cpp -std=c++11
// oj d https://atcoder.jp/contests/agc003/tasks/agc003_a
// oj t
// oj s https://atcoder.jp/contests/agc003/tasks/agc003_a a.cpp

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  string S;
  cin >> S;
  map<char, int> count;
  int N_count = 0;
  int W_count = 0;
  int S_count = 0;
  int E_count = 0;
  for (int i = 0; i < S.size(); ++i) {
    count[S[i]]++;
  }
  if (
    (count['N'] > 0 && count['S'] == 0) ||
    (count['N'] == 0 && count['S'] > 0) ||
    (count['W'] > 0 && count['E'] == 0) ||
    (count['W'] == 0 && count['E'] > 0)
  ) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  }
}
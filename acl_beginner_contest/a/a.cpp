// g++ -o a.out a.cpp -std=c++11
// oj d https://atcoder.jp/contests/abc218/tasks/abc218_a
// oj t
// oj s https://atcoder.jp/contests/abc218/tasks/abc218_a a.cpp

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int N;
  string S;
  cin >> N >> S;
  if (S[N-1] == 'o') {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
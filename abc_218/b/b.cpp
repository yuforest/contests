// g++ -o b.out b.cpp -std=c++11
// oj d https://atcoder.jp/contests/abc218/tasks/abc218_b
// oj t -c "./b.out"
// oj s https://atcoder.jp/contests/abc218/tasks/abc218_b b.cpp


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int P[26];
  for (int i = 0; i < 26; ++i) {
    cin >> P[i];
  }
  string alphabets = "abcdefghijklmnopqrstuvwxyz";
  for (int i = 0; i < 26; i++) {
    cout << alphabets[P[i]-1];
  }
  cout << endl;
}
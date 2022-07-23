// g++ -o a.out a.cpp -std=c++11
// oj d https://atcoder.jp/contests/abc219/tasks/abc219_a
// oj t
// oj s https://atcoder.jp/contests/abc219/tasks/abc219_a a.cpp

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  string S;
  cin >> S;
  map<char, int> mp;
  rep(i, S.size()) {
    mp[S[i]]++;
  }
  for(auto e: mp) {
    if (e.second == 1) {
      cout << e.first << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
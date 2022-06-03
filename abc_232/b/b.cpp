// g++ -o b.out b.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc232/tasks/abc232_b
// oj t -c "./b.out"
// oj s https://atcoder.jp/contests/abc232/tasks/abc232_b b.cpp


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main()
{
  string S, T;
  cin >> S >> T;
  for (int i = 0; i <= 26; i++) {
    string changed = "";
    for (int j = 0; j < S.size(); j++) {
      int index = S.at(j) - 'a';
      // cout << index << endl;
      int diff = index + i;
      if (diff >= 26) {
        diff -= 26;
      }
      char mozi = 'a' + diff;
      changed += mozi;
    }
    // cout << changed << endl;
    if (changed == T) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}
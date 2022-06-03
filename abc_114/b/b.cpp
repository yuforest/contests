// g++ -o b.out b.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc226/tasks/abc226_b
// oj t -c "./b.out"
// oj s https://atcoder.jp/contests/abc226/tasks/abc226_b b.cpp


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
  int ans = 1000;
  for (int i = 2; i < (int)S.size(); i++) {
    int num = (S[i-2] - '0') * 100 + (S[i-1] - '0') * 10 + (S[i] - '0');
    int diff = abs(753 - num);
    ans = min(ans, diff);
  }
  cout << ans << endl;
}
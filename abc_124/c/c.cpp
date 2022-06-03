// g++ -o c.out c.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc226/tasks/abc226_c
// oj t -c "./c.out"
// oj s https://atcoder.jp/contests/abc226/tasks/abc226_c c.cpp


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
long long minimum_time = 0;
vector<bool> used(200007, false);
vector<int> G[1 << 18];
long long K[200007];
long long T[200007];


int main()
{
  string S;
  cin >> S;
  // 10101010で塗る場合
  int ans1 = 0;
  int ans2 = 0;
  for (int i = 0; i < S.size(); i++) {
    if (i % 2 == 0) {
      if (S[i] == '0') {
        ans1++;
      }
    } else {
      if (S[i] == '1') {
        ans1++;
      }
    }
  }
  // 0101010で塗る場合
  for (int i = 0; i < S.size(); i++) {
    if (i % 2 == 0) {
      if (S[i] == '1') ans2++;
    } else {
      if (S[i] == '0') ans2++;
    }
  }
  int ans;
  ans = min(ans1, ans2);
  cout << ans << endl;
  return 0;
}
// g++ -o c.out c.cpp -std=c++11
// oj d https://atcoder.jp/contests/abc219/tasks/abc219_c
// oj t -c "./c.out"
// oj s https://atcoder.jp/contests/abc219/tasks/abc219_c c.cpp

#include <bits/stdc++.h>
using namespace std;
int n, k;
int c[300005];
map<int, int> mp;
long long mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main(void)
{
  int N;
  cin >> N;
  int ans = 0;
  rep(i, N) {
    int num = i+1;
    bool not_7 = true;
    stringstream ss;
    ss << oct << num;
    for(auto c: ss.str()) {
      if (c == '7') not_7 = false;
    }
    for(auto c: to_string(num)) {
      if (c == '7') not_7 = false;
    }
    if (not_7) ans++;
  }
  cout << ans << endl;
}
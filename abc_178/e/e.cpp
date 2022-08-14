// g++ -o c.out c.cpp -std=c++11
// oj d https://atcoder.jp/contests/abc216/tasks/abc216_c
// oj t -c "./c.out"
// oj s https://atcoder.jp/contests/abc216/tasks/abc216_c c.cpp

#include <bits/stdc++.h>
using namespace std;
int n, k;
int c[300005];
map<int, int> mp;
long long mod = 1000000007;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main(void)
{
  int N;
  cin >> N;
  int x[N], y[N];
  rep(i, N) {
    cin >> x[i] >> y[i];
  }
  vector<int> sums;
  vector<int> subs;
  rep(i, N) {
    sums.push_back(x[i] + y[i]);
    subs.push_back(x[i] - y[i]);
  }
  sort(sums.begin(), sums.end());
  sort(subs.begin(), subs.end());
  // 2点(a,b), (c,d)のマンハッタン距離->(a+b, a-b)と(c+d, c-d)のチェビシェフ距離->max(|(a+b) - (c+d)|, |(a-b) - (c-d)|)
  // 2点間の「和の差」か「差の差」の内大きい方が最大のマンハッタン距離となる
  cout << max(sums.back() - sums[0], subs.back() - subs[0]) << endl;
}
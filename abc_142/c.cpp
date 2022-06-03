// g++ -o c.out c.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc226/tasks/abc226_c
// oj t -c "./c.out"
// oj s https://atcoder.jp/contests/abc226/tasks/abc226_c c.cpp


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
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
  int N;
  cin >> N;
  vector<int> A(N+1);
  rep1(i, N) {
    cin >> A[i];
  }
  vector<int> ans(N+1);
  rep1(i, N) {
    ans[A[i]] = i;
  }
  rep1(i, N) {
    cout << ans[i];
    if (i != N) {
      cout << " ";
    }
  }
  cout << endl;


}
// g++ -o a.out a.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc222/tasks/abc222_a
// oj t -c "./a.out"
// oj s https://atcoder.jp/contests/abc222/tasks/abc222_a c.cpp

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
  double K;
  cin >> N >> K;
  vector<int> A(N);
  rep(i, N) {
    cin >> A[i];
  }
  // auto itr = std::find(A.begin(), A.end(), 1);
  // int index = itr - A.begin();
  // cout << index << endl;
  // int before = index;
  // int after = N - index - 1;
  int ans = ceil((N - 1) / (K - 1));
  cout << ans << endl;
}
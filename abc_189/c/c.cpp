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
  int A[N];
  rep(i, N) {
    cin >> A[i];
  }
  int ans = 0;
  for(int l=0; l < N;l++) {
    // l番目に載っているみかんの数
    int x = A[l];
    for(int r=l; r < N; r++) {
      // 皿に乗っているみかんの最小値(できるだけ大きな長方形を作るために)
      x = min(x, A[r]);
      // (r - l + 1)は皿の数を導いている
      ans = max(ans, x * (r - l + 1));
    }
  }
  cout << ans << endl;
}
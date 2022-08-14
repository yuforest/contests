// g++ -o d.out d.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc222/tasks/abc222_d
// oj t -c "./d.out"
// oj s https://atcoder.jp/contests/abc222/tasks/abc222_d d.cpp

#include <bits/stdc++.h>
using namespace std;
int n, k;
int c[300005];
map<int, int> mp;
// long long mod = 1000000007;
// 縦軸が弁当の種類、横軸がたこ焼きの数、配列の値が鯛焼きの数
#define rep(i, n) for (int i = 0; i < (n); ++i)

int dp[33][101010];
int ans[101010];
using ll = long long;

int main(void)
{
  ll N, M;
  cin >> N >> M;
  vector<ll> A(N);
  priority_queue<
    long long,                // 要素の型はlong long
    std::vector<long long>,   // 内部コンテナはstd::vector (デフォルトのまま)
    std::less<long long>   // 降順 (デフォルトはstd::less<T>、降順)
  > que;
  rep(i, N) {
    cin >> A[i];
    que.push(A[i]);
  }
  // queの中にある一番高い商品に対して割引を行う
  while(M > 0) {
    ll val = que.top() / 2;
    que.pop();
    // cout << val << endl;
    que.push(val);
    M--;
  }
  ll ans = 0;
  while (!que.empty()) {
    ll val = que.top();
    que.pop();
    ans += val;
  }
  cout << ans << endl;

}
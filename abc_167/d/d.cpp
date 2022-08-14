// g++ -o d.out d.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc186/tasks/abc186_d
// oj t -c "./d.out"
// oj s https://atcoder.jp/contests/abc186/tasks/abc186_d d.cpp

#include <bits/stdc++.h>
using namespace std;
int n, k;
int c[300005];
map<int, int> mp;
#define rep(i, n) for (int i = 0; i < (n); ++i)
long long mod = 1000000007;
using ll = long long;

int main() {
  ll N, K;
  cin >> N >> K;
  ll A[N+1];
  rep(i, N) {
    cin >> A[i+1];
  }
  vector<int> visited(N+1, -1);
  visited[1] = 0;
  ll now_town = 1;
  ll move_cnt = 0;
  ll cycle;
  for(int i = 0; i < N ; i++) {
    move_cnt++;
    now_town = A[now_town];
    if (move_cnt == K) {
      cout << now_town << endl;
      return 0;
    }
    if (visited[now_town] == -1) {
      visited[now_town] = move_cnt;
    } else {
      // 最初に発生したサイクルの検知
      cycle = move_cnt - visited[now_town];
      break;
    }
  }
  // 今までに移動した回数を引いておく
  K -= move_cnt;
  // あまりを取っても現在いる位置に戻ってくる
  K %= cycle;
  // 余り回数のテレポーテーションを計算する
  for(int i = 0; i < K; i++) {
    now_town = A[now_town];
  }
  cout << now_town << endl;


}
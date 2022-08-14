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
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)
// greatest common divisor
ll gcd(ll a, ll b) { return a ? gcd(b % a, a) : b; }
// least common multiple
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

// 変換テーブル
// int f[26][26];

int main(void)
{
  string S, T;
  cin >> S >> T;
  int N = S.length();

  // 変換テーブル
  vector<vector<int>> f(26, vector<int>(26, 0));
  rep(i, N) {
    int a = S[i] - 'a';
    int b = T[i] - 'a';
    // aをbに変換するということ
    f[a][b] = 1;
  }

  // ある文字について複数の変換先があってはいけない
  rep(i, 26) {
    int cn = 0;
    // 変換先が0でなければカウント
    rep(j, 26) if (f[i][j]) cn++;
    if (2 <= cn) {
      printf("No\n");
      return 0;
    }
  }
  // ある文字について複数の変換元があってはいけない
  rep(j, 26) {
    int cn = 0;
    // 変換元が0でなければカウント
    rep(i, 26) if (f[i][j]) cn++;
    if (2 <= cn) {
      printf("No\n");
      return 0;
    }
  }

  printf("Yes\n");
}
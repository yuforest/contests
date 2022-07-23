// g++ -o a.out a.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc235/tasks/abc235_a
// oj t -c "./a.out"
// oj s https://atcoder.jp/contests/abc235/tasks/abc235_a a.cpp

#include <bits/stdc++.h>
using namespace std;
int n, k;
int c[300005];
map<int, int> mp;
long long mod = 1000000007;

#define rep(i, n) for (int i = 0; i < (n); ++i)

int main(void)
{
  int N, A, B, C, D;
  string S;
  cin >> N >> A >> B >> C >> D >> S;
  // 番兵
  S = "#" + S + "#";

  // 2つ連続で岩がくると駄目(Aの次のマスからCまでまたはBの次のマスからDまで)
  auto can_reach = [&](int start, int end) {
      for (int i = start; i + 1 <= end; i++) {
          if (S[i] == '#' && S[i + 1] == '#') return false;
      }
      return true;
  };

  if (!can_reach(A, C) || !can_reach(B, D)) {
      cout << "No" << endl;
      return 0;
  }

  // Bの次のマスからDの前までに追い越せるかどうか
  if (C > D) {
      bool snuke_can_over = false;
      for (int i = B; i <= D; i++) {
          if (S[i - 1] == '.' && S[i] == '.' && S[i + 1] == '.') {
              snuke_can_over = true;
          }
      }
      if (!snuke_can_over) {
          cout << "No" << endl;
          return 0;
      }
  }
  cout << "Yes" << endl;

  return 0;
}
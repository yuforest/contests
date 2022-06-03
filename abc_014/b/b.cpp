// g++ -o b.out b.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc014/tasks/abc014_b
// oj t -c "./b.out"
// oj s https://atcoder.jp/contests/abc014/tasks/abc014_b b.cpp


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  string S;
  cin >> S;
  int N;
  cin >> N;
  int l[N];
  int r[N];
  rep(i, N) {
    cin >> l[i];
    l[i] -= 1;
    cin >> r[i];
    r[i] -= 1;
  }

  rep(i, N) {
    int diff = r[i] - l[i];
    int loop_count = ceil(diff / 2.0);
    for (int j = 0; j < loop_count; j++) {

      char tmp_l = S[l[i] + j];

      S[l[i] + j] = S[r[i] - j];
      S[r[i] - j] = tmp_l;
    }
  }

  cout << S << endl;

}
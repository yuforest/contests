// g++ -o b.out b.cpp -std=c++11
// oj d https://atcoder.jp/contests/abc216/tasks/abc216_b
// oj t -c "./b.out"
// oj s https://atcoder.jp/contests/abc216/tasks/abc216_b b.cpp


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int N;
  string S;
  cin >> N;
  cin >> S;
  if (N % 2 != 0) {
    cout << -1 << endl;
  } else {
    int count = 0;
    int half = N / 2;
    for (int i = 0; i < half; ++i) {
      if (S[i] != S[half+i]) count++;
    }
    cout << count << endl;
  }
}
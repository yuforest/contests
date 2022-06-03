// g++ -o a.out a.cpp -std=c++11
// oj d https://atcoder.jp/contests/abc217/tasks/abc217_a
// oj t
// oj s https://atcoder.jp/contests/abc217/tasks/abc217_a a.cpp

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  double sum = 0;
  double gpa = 0;
  for (int i = 0; i < N; ++i) {
    if (S[i] == 'A') sum += 4.0;
    if (S[i] == 'B') sum += 3.0;
    if (S[i] == 'C') sum += 2.0;
    if (S[i] == 'D') sum += 1.0;
    if (S[i] == 'F') sum += 0;
  }
  gpa = sum / N;
  cout << std::setprecision(15) << gpa << endl;
}
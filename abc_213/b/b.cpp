// g++ -o b.out b.cpp -std=c++11
// oj d https://atcoder.jp/contests/abc212/tasks/abc212_b
// oj t -c "./b.out"
// oj s https://atcoder.jp/contests/abc212/tasks/abc212_b b.cpp


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A.at(i);
  }
  vector<int> sorted(N);
  sorted = A;
  sort(sorted.begin(), sorted.end());
  int wanted = sorted.at(sorted.size() - 2);
  auto itr = find(A.begin(), A.end(), wanted);
  int wanted_index = itr - A.begin();

  cout << wanted_index + 1 << endl;
}
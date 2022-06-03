// g++ -o c.out c.cpp -std=c++11
// oj d https://atcoder.jp/contests/abc212/tasks/abc212_c
// oj t -c "./c.out"
// oj s https://atcoder.jp/contests/abc212/tasks/abc212_c c.cpp




#include <bits/stdc++.h>
using namespace std;
int n, k;
int c[300005];
map<int, int> mp;
long long mod = 1000000007;

int main(void)
{
  int N, M;
  cin >> N >> M;
  vector<int> A(N);
  vector<int> B(M);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  for (int i = 0; i < M; i++) {
    cin >> B.at(i);
  }
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());

  int ans = 1000000007;
  for (int i = 0; i < N; i++) {
    auto position = lower_bound(B.begin(), B.end(), A.at(i));
    int index = distance(B.begin(), position);
    if (index >= B.size()) {
      index -= 1;
    }
    if (index > 0) {
      int index2 = index - 1;
      ans = min(ans, abs(A.at(i) - B.at(index2)));
    }
    if (index < B.size() - 1) {
      int index3 = index + 1;
      ans = min(ans, abs(A.at(i) - B.at(index3)));
    }
    ans = min(ans, abs(A.at(i) - B.at(index)));
  }
  cout << ans << endl;
}
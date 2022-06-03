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

int main(void)
{
  int N;
  cin >> N;
  int A[N];
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  vector<int> ans;
  for (int i = 0; i < N; i++) {
    auto result = find(ans.begin(), ans.end(), A[i]);
    if (result == ans.end()) {
      ans.push_back(A[i]);
    } else {
      ans.erase(result);
    }
  }
  cout << ans.size() << endl;
}
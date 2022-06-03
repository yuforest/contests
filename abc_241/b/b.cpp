// g++ -o b.out b.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc233/tasks/abc233_b
// oj t -c "./b.out"
// oj s https://atcoder.jp/contests/abc233/tasks/abc233_b b.cpp


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
map<int, int> mp;

int main()
{
  int N, M;
  cin >> N >> M;
  int A[N+1];
  int B[N+1];
  rep1(i, N) {
    cin >> A[i];
    mp[A[i]] += 1;
  }
  rep1(i, M) {
    cin >> B[i];
    mp[B[i]] -= 1;
    if (mp[B[i]] < 0) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
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

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  map<int,int> ma;
  for (int i = 0; i < N; ++i) cin >> A[i], ++ma[A[i]];

  auto solve = [&]() -> bool {
    if (N % 3 != 0) return (ma[0] == N);
    vector<int> v;
    for (auto it : ma) v.push_back(it.first);
    if (v.size() == 1) return (ma[0] == N);
    else if (v.size() == 2) return (ma[0] == N/3);
    else if (v.size() == 3) {
        if ((v[0] ^ v[1] ^ v[2]) != 0) return false;
        return (ma[v[0]] == N/3 && ma[v[1]] == N/3 && ma[v[2]] == N/3);
    }
    else return false;
  };
  cout << (solve() ? "Yes" : "No") << endl;
}
// g++ -o b.out b.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc256/tasks/abc256_b
// oj t -c "./b.out"
// oj s https://atcoder.jp/contests/abc256/tasks/abc256_b b.cpp


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
map<int, int> mp;

int main()
{
  int N, K, Q;
  cin >> N >> K >> Q;
  int A[N];
  rep(i, K) {
    cin >> A[i];
  }
  int L[Q];
  rep(i, Q) {
    int val;
    cin >> val;
    val--;
    L[i] = val;
  }
  rep(i, Q) {
    int index = L[i];
    if (A[index] == N) continue;
    if (A[index]+1 == A[index+1]) continue;
    A[index] += 1;
  }
  rep(i, K) {
    if (i == K-1) {
      cout << A[i] << endl;
    } else {
      cout << A[i] << " ";
    }
  }
  return 0;
}
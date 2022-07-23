// g++ -o c.out c.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc226/tasks/abc226_c
// oj t -c "./c.out"
// oj s https://atcoder.jp/contests/abc226/tasks/abc226_c c.cpp


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
long long minimum_time = 0;
vector<bool> used(200007, false);
vector<int> G[1 << 18];
long long K[200007];
long long T[200007];

int main()
{
  int N;
  cin >> N;
  int A[N];
  rep(i, N) {
    cin >> A[i];
  }
  deque<int> deq;
  bool reversed = false;
  rep(i, N) {
    if (i % 2 == 0) {
      deq.push_back(A[i]);
    } else {
      deq.push_front(A[i]);
    }
    reversed = !reversed;
  }
  if (reversed) {
    reverse(deq.begin(), deq.end());
  }
  rep (i, N) {
    if (i != N-1) {
      cout << deq[i] << " ";

    } else {
      cout << deq[i] << endl;
    }
  }
  return 0;
}
// g++ -o c.out c.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc233/tasks/abc233_c
// oj t -c "./c.out"
// oj s https://atcoder.jp/contests/abc233/tasks/abc233_c c.cpp


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
long long minimum_time = 0;
vector<bool> used(200007, false);
vector<vector<int>> G1(10, vector<int>());
vector<vector<int>> G2(10, vector<int>());
long long K[200007];
long long T[200007];
#include <bits/stdc++.h>
using namespace std;

// vector<vector<int>> histories(1000000007, vector<int>());

// int histories[1000000007];
// vector<int> histories_array[1 << 18];

int main() {
  int N, Q;
  cin >> N >> Q;
  int A[N+1];
  map< int, vector<int> > m;

  rep1(i, N) {
    cin >> A[i];
    m[A[i]].push_back(i);
  }

  rep1(i, Q) {
    int x, k;
    cin >> x >> k;
    if (m[x].size() >= k) {
      cout << m[x][k-1] << endl;
    } else {
      cout << -1 << endl;
    }
  }

  return 0;
}

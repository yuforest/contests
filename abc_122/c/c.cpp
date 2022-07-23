// g++ -o c.out c.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc233/tasks/abc233_c
// oj t -c "./c.out"
// oj s https://atcoder.jp/contests/abc233/tasks/abc233_c c.cpp


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
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

ll MAX = 1 << 18;

int N;
ll X;
int L[100007];
vector<vector<ll>> a(100007, vector<ll>());
ll ans = 0;

int main() {
  int N, Q;
  cin >> N >> Q;
  string S;
  cin >> S;
  vector<int> cumulative(N+1, 0);
  for (int i = 1; i < N; i++) {
    if (S[i-1] == 'A' && S[i] == 'C') {
      cumulative[i] = cumulative[i-1] + 1;
    } else {
      cumulative[i] = cumulative[i-1];
    }
  }
  // rep(i,N) {
  //   cout << cumulative[i] << endl;
  // }
  rep(i, Q) {
    int l, r;
    cin >> l >> r;
    l--;
    r--;
    cout << cumulative[r] - cumulative[l] << endl;
  }
  return 0;
}

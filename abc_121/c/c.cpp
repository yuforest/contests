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

void check(int currentIndex, ll currentAns) {
    if (currentIndex == N) {
    //   cout << currentAns << endl;
      if (X == currentAns) {
        ans++;
      }
      return;
    }
    if (X < currentAns) {
      return;
    }

    for (int i = 0; i < L[currentIndex]; i++) {
        ll tmpVal = currentAns * a[currentIndex][i];
        if (X < tmpVal) {
            continue;
        }
        check(currentIndex+1, tmpVal);
    }
}

int main() {
  cin >> N >> X;
  rep (i, N) {
    cin >> L[i];
    rep (j, L[i]) {
      ll val;
      cin >> val;
      a[i].push_back(val);
    }
  }
  check(0, 1);

  cout << ans << endl;
  return 0;
}

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

int main() {
  int N, M;
  cin >> N >> M;

  string S[N+1], T[M+1];
  rep1(i, N) {
    cin >> S[i];
  }
  rep1(i, M) {
    cin >> T[i];
  }

  map<string, bool> express;
  rep1(i, M) {
    express[T[i]] = true;
  }
  rep1(i, N) {
    if (express[S[i]] == true) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  return 0;
}

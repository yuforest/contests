// g++ -o d.out d.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc186/tasks/abc186_d
// oj t -c "./d.out"
// oj s https://atcoder.jp/contests/abc186/tasks/abc186_d d.cpp

#include <bits/stdc++.h>
using namespace std;
int n, k;
int c[300005];
map<int, int> mp;
#define rep(i, n) for (int i = 0; i < (n); ++i)
long long mod = 1000000007;
using ll = long long;

int main() {
  ll N, K, R, S, P;
  cin >> N >> K >> R >> S >> P;
  string T;
  cin >> T;
  // K回目までは必ず勝つ手、それ以降は勝つ手がK回前と同じなら勝てない
  ll ans = 0;
  bool results[N];
  rep(i, N){
    if (i < K) {
      if (T[i] == 'r') {
        ans += P;
      } else if (T[i] == 's') {
        ans += R;
      } else {
        ans += S;
      }
      results[i] = true;
    } else {
      if (T[i] == T[i-K]) {
        if (results[i-K]) {
          results[i] = false;
        } else {
          if (T[i] == 'r') {
            ans += P;
          } else if (T[i] == 's') {
            ans += R;
          } else {
            ans += S;
          }
          results[i] = true;
        }
      } else {
        if (T[i] == 'r') {
          ans += P;
        } else if (T[i] == 's') {
          ans += R;
        } else {
          ans += S;
        }
        results[i] = true;
      }
    }
  }
  cout << ans << endl;


}
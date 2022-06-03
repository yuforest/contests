// g++ -o b.out b.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc226/tasks/abc226_b
// oj t -c "./b.out"
// oj s https://atcoder.jp/contests/abc226/tasks/abc226_b b.cpp


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main()
{
  int N;
  string S;
  cin >> N >> S;

  int ans = 0;
  for (int i = 0; i < N; i++) {
    map<char, int> first;
    map<char, int> last;
    // search first half
    for (int j = 0; j < i; j++) {
      first[S[j]]++;
    }
    // search last half
    for (int j = i; j < N; j++) {
      last[S[j]]++;
    }
    int count = 0;
    for (auto x : first) {
      if (last[x.first] > 0) {
        count++;
      }
    }
    ans = max(ans, count);
  }
  cout << ans << endl;
}
// g++ -o c.out c.cpp -std=c++11
// oj d https://atcoder.jp/contests/abc219/tasks/abc219_c
// oj t -c "./c.out"
// oj s https://atcoder.jp/contests/abc219/tasks/abc219_c c.cpp

#include <bits/stdc++.h>
using namespace std;
int n, k;
int c[300005];
map<int, int> mp;
long long mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main(void)
{
  int N;
  cin >> N;
  string S[N];
  rep(i, N) {
    cin >> S[i];
  }
  int full = 0;
  int first_B = 0;
  int last_A = 0;
  int both = 0;
  rep(i, N) {
    string current = S[i];
    if (current[0] == 'B' && current[current.size()-1] == 'A') both++;
    else if (current[0] == 'B') first_B++;
    else if (current[current.size()-1] == 'A') last_A++;
    for(int j = 0; j < current.size(); j++) {
      if (j != current.size()-1) {
        if (current[j] == 'A' && current[j+1] == 'B') {
          full++;
        }
      }
    }
  }
  // cout << full << endl;
  // cout << first_B << endl;
  // cout << last_A << endl;
  // cout << both << endl;
  int ans = full;
  if (first_B + last_A == 0) {
    ans += max(0, both-1);
  } else {
    ans += both + min(first_B, last_A);
  }
  cout << ans << endl;
}

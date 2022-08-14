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
using ll = long long;

vector<ll> red_to_blue(11);
vector<ll> blue_to_blue(11);

ll ans = 0;

ll N, X, Y;

void red_dfs(ll, ll);
void blue_dfs(ll, ll);

void red_dfs(ll level, ll count) {
  // cout << "red" << endl;
  // cout << level << " " << count << endl;
  if (level == 1) return;
  red_dfs(level-1LL, count);
  blue_dfs(level, count * X);
}

void blue_dfs(ll level, ll count) {
  // cout << "blue" << endl;
  // cout << level << " " << count << endl;
  if (level == 1) {
    ans += count;
    return;
  }
  red_dfs(level-1LL, count);
  blue_dfs(level-1, count * Y);
}




int main(void)
{
  int N;
  cin >> N;
  string S[N];
  map<string, int> mp;
  rep(i, N) {
    cin >> S[i];
  }
  rep(i, N) {
    if (mp[S[i]] == 0) {
      cout << S[i] << endl;
    } else {
      cout << S[i] << "(" << mp[S[i]] <<  ")" << endl;
    }
    mp[S[i]]++;
  }

  return 0;


}
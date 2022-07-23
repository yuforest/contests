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
  cin >> N >> X >> Y;
  // red_to_blue[2] = X;
  // for (int i = 3; i <= 10; i++) {
  //   red_to_blue[i] = red_to_blue[i]  *  red_to_blue[i];
  // }
  // blue_to_blue[2] = Y;
  // for (int i = 3; i <= 10; i++) {
  //   blue_to_blue[i] = blue_to_blue[i]  *  blue_to_blue[i];
  // }
  red_dfs(N, 1LL);
  // map<ll, ll> red;
  // map<ll, ll> blue;

  cout << ans << endl;
  return 0;


}
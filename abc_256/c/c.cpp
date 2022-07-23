// g++ -o c.out c.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc256/tasks/abc256_c
// oj t -c "./c.out"
// oj s https://atcoder.jp/contests/abc256/tasks/abc256_c c.cpp

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
map<int, int> mp;

int h[3];
int w[3];
// ll count = 0;

// void dfs(int pos, int arr[]) {
//   // minimum_time += T[pos];
// 	// used[pos] = true;

//   if (pos == 9) {

//   }

//   for (int i = 1; i <= 10; i++) {
//     dfs(pos+1, arr.push_back(i));
//   }

// 	// for (int i : G[pos]) {
// 	// 	if (used[i] == false) dfs(i);
// 	// }
// }

int main(){
  rep(i, 3) {
    cin >> h[i];
  }
  rep(i, 3) {
    cin >> w[i];
  }
  ll ans = 0;
  for (int i1 = 1; i1 <= h[0]-2; i1++) {
    for (int i2 = 1; i2 <= h[0] - i1; i2++) {
      for (int i3 = 1; i3 <= h[0] - i1 - i2; i3++) {
        for (int i4 = 1; i4 <= w[0] - i1; i4++) {
          for (int i5 = 1; i5 <= h[1] - i4; i5++) {
            for (int i6 = 1; i6 <= h[1] - i4 - i5; i6++) {
              if (i1 + i2 + i3 == h[0] && i4 + i5 + i6 == h[1]) {
                if (i1 + i4 < w[0] && i2 + i5 < w[1] && i3 + i6 < w[2]) {
                  int i7 = w[0] - i1 - i4;
                  int i8 = w[1] - i2 - i5;
                  int i9 = w[2] - i3 - i6;
                  if (i7 + i8 + i9 == h[2]) ans++;
                }
              }
            }
          }
        }
      }
    }
  }
  cout << ans << endl;
}
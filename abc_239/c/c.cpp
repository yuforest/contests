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

#include<bits/stdc++.h>
#define mod 998244353
#define inv2 499122177
using namespace std;

int main(){
  long long x1, x2, y1, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  bool ans = false;
  for (int i = -2; i <= 2; i++) {
    for (int j = -2; j <= 2; j++) {
      for (int k = -2; k <= 2; k++) {
        for (int l = -2; l <= 2; l++) {
          if (i == 0 || j == 0 || k == 0 || l == 0) continue;
          if (abs(i) == 1 && abs(j) == 1) continue;
          if (abs(i) == 2 && abs(j) == 2) continue;
          if (abs(k) == 1 && abs(l) == 1) continue;
          if (abs(k) == 2 && abs(l) == 2) continue;
          if (x1 + i == x2 + k && y1 + j == y2 + l) ans = true;
        }
      }
    }
  }
  if (ans) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
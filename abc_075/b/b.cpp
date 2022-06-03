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
  int H, W;
  cin >> H >> W;
  string S[H];
  for (int i = 0; i < H; i++) {
    cin >> S[i];
  }
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      char current = S[i][j];
      if (current == '.') {
        int count = 0;
        for (int k = -1; k <= 1; k++) {
          for (int l = -1; l <= 1; l++) {
            if (k == 0 && l == 0) continue;
            if (i + k >= 0 && i + k < H && j + l >= 0 && j + l < W ) {
              if (S[i + k][j + l] == '#') count++;
            }
          }
        }
        char charCount = '0' + count;
        S[i][j] = charCount;
      }
    }
  }
  for (int i = 0; i < H; i++) {
    cout << S[i] << endl;
  }
}
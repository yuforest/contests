#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int X;
  cin >> X;
  bool break_flg = false;
  for (int i = -120; i<= 120; i++) {
    for (int j = -120; j <= 120; j++) {
      if(pow(i, 5) - pow(j, 5) == X) {
        cout << i << ' ' << j << endl;
        break_flg = true;
        break;
      }
    }
    if (break_flg) {
      break;
    }
  }
}
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  string S;
  int Q;
  cin >> S >> Q;
  bool reversed = false;
  for (int i = 0; i < Q; i++) {
    int t;
    cin >> t;
    if (t == 1) {
      // reverse(S.begin(), S.end());
      reversed = !reversed;
    } else {
      int f;
      string p;
      cin >> f >> p;
      if (reversed) {
        if (f == 1)
        {
          S.append(p);
        }
        else
        {
          S.insert(0, p);
        }
      } else {
        if (f == 1)
        {
          S.insert(0, p);
        }
        else
        {
          S.append(p);
        }
      }
    }
  }
  if (reversed) {
    reverse(S.begin(), S.end());
  }
  cout << S << endl;
}
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep1(i, n) for (int i = 1; i <= (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int N, A, B, C;
  cin >> N >> A >> B >> C;
  vector<string> s(N);
  rep(i, N) {
    cin >> s[i];
  }
  vector<char> route;
  string ans;
  if (A+B+C == 0) {
    cout << "No" << endl;
    return 0;
  }
  if (A+B+C == 1) {
    rep(i, N) {
      if (s[i] == "AB") {
        if (A == 0 && B == 0) {
          cout << "No" << endl;
          return 0;
        } else {
          if (A==1) {
            route.push_back(A);
          } else {
            route.push_back(B);
          }
        }
      }
      if (s[i] == "BC") {
        if (B == 0 && C == 0) {
          cout << "No" << endl;
          return 0;
        } else {
          if (B==1) {
            route.push_back(B);
          } else {
            route.push_back(C);
          }
        }
      }
      if (s[i] == "AC") {
        if (A == 0 && C == 0) {
          cout << "No" << endl;
          return 0;
        } else {
          if (A==1) {
            route.push_back(A);
          } else {
            route.push_back(C);
          }
        }
      }
    }
    cout << "Yes" << endl;
    rep(i, N) {
      cout << route[i] << endl;
    }
    return 0;
  }
  if (A+B+C >= 2) {
    if (s[0] == "AB" && A == 0 && B==0) {
      cout << "No" << endl;
      return 0;
    }
    if (s[0] == "BC" && C == 0 && B==0) {
      cout << "No" << endl;
      return 0;
    }
    if (s[0] == "AC" && A == 0 && C==0) {
      cout << "No" << endl;
      return 0;
    }
    cout << "Yes" << endl;
    rep(i, N) {
      
    }
  return 0;
  // cout << ans << endl;
}
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int X, Y, Z;
  // int N, M;
  cin >> X >> Y >> Z;
  swap(X, Y);
  swap(X, Z);
  cout << X << " " << Y << " " << Z << endl;
}
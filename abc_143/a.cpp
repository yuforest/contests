#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int A, B;
  cin >> A >> B;
  int length;
  length = A - B*2;
  if (length < 0) {
    cout << 0 << endl;
  } else {
    cout << length << endl;
  }
}
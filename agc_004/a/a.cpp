// g++ -o a.out a.cpp -std=c++11
// oj d https://atcoder.jp/contests/agc003/tasks/agc003_a
// oj t
// oj s https://atcoder.jp/contests/agc003/tasks/agc003_a a.cpp

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  ll A, B, C;
  cin >> A >> B >> C;
  if (A % 2 == 0 || B % 2 == 0 || C % 2 == 0) {
    cout << 0 << endl;
  } else {
    vector<ll> array = { A, B, C };
    sort(array.begin(), array.end());
    cout << array[0] * array[1] << endl;
  }
  return 0;
}
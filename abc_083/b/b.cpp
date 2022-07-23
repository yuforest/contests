// g++ -o b.out b.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc226/tasks/abc226_b
// oj t -c "./b.out"
// oj s https://atcoder.jp/contests/abc226/tasks/abc226_b b.cpp


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main()
{
  int a, b;
  cin >> a >> b;
  string str_a, str_b;
  str_a = to_string(a);
  str_b = to_string(b);
  int val = stol(str_a + str_b);
  double sqrt_val = sqrt(val);
  // cout << sqrt_val << endl;
  // cout << (int)sqrt_val << endl;
  if (sqrt_val == (int) sqrt_val) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
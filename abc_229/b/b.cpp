// g++ -o b.out b.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc229/tasks/abc229_b
// oj t -c "./b.out"
// oj s https://atcoder.jp/contests/abc229/tasks/abc229_b b.cpp


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main()
{
  ll A, B;
  cin >> A >> B;
  bool kuriagari = false;
  while (A > 0 && B > 0) {
    ll a_remain = A % 10;
    ll b_remain = B % 10;
    if (a_remain + b_remain >= 10) {
      kuriagari = true;
    }

    A /= 10;
    B /= 10;
  }

   if (kuriagari) {
    cout << "Hard" << endl;
  } else {
    cout << "Easy" << endl;
  }
}
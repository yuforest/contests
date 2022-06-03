// g++ -o b.out b.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc216/tasks/abc216_b
// oj t -c "./b.out"
// oj s https://atcoder.jp/contests/abc216/tasks/abc216_b b.cpp


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int N, A, B;
  string S;
  cin >> N >> A >> B >> S;
  int kokunai = 0;
  int kaigai = 0;

  rep (i, N) {
    if (S[i] == 'c') {
      cout << "No" << endl;
    }
    if (S[i] == 'a') {
      if ((kokunai + kaigai) < (A + B)) {
        kokunai++;
        cout << "Yes" << endl;
      } else {
        cout << "No" << endl;
      }
    }
    if (S[i] == 'b') {
      if ((kokunai + kaigai) < (A + B) && kaigai < B) {
        kaigai++;
        cout << "Yes" << endl;
      } else {
        cout << "No" << endl;
      }
    }

  }

}
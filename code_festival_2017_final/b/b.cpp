// g++ -o b.out b.cpp -std=c++11
// oj d https://atcoder.jp/contests/abc216/tasks/abc216_b
// oj t -c "./b.out"
// oj s https://atcoder.jp/contests/abc216/tasks/abc216_b b.cpp


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int b_count = 0;
int N;
vector<int> A;


int main()
{
  string S;
  cin >> S;
  int a = 0;
  int b = 0;
  int c = 0;
  rep(i, S.size()) {
    if (S.at(i) == 'a') {
      a++;
    } else if (S.at(i) == 'b') {
      b++;
    } else {
      c++;
    }
  }
  string ans = "YES";
  if (abs(a-b) > 1 || abs(b-c) > 1 || abs(c-a) > 1) {
    ans = "NO";
  }
  cout << ans << endl;
}
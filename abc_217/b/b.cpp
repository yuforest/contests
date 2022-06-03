// g++ -o b.out b.cpp -std=c++11
// oj d https://atcoder.jp/contests/abc217/tasks/abc217_b
// oj t -c "./b.out"
// oj s https://atcoder.jp/contests/abc217/tasks/abc217_b b.cpp


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  string S1;
  string S2;
  string S3;
  cin >> S1 >> S2 >> S3;
  string contests[4] = {"ABC", "ARC", "AGC", "AHC"};
  for (int i = 0; i < 4; ++i) {
    if (S1 != contests[i] && S2 != contests[i] && S3 != contests[i]) {
      cout << contests[i] << endl;
    }
  }

}
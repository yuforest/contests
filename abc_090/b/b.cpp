// g++ -o b.out b.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc226/tasks/abc226_b
// oj t -c "./b.out"
// oj s https://atcoder.jp/contests/abc226/tasks/abc226_b b.cpp


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

bool is_palindromic_num(int num) {
  string str_num = to_string(num);
  int size = str_num.size();
  for(int i = 0; i < size / 2; i++) {
    if (str_num[i] != str_num[size-i-1]) {
      return false;
    }
  }
  return true;
}


int main()
{
  int A, B;
  cin >> A >> B;
  int ans = 0;
  for (int i = A; i <= B; i++) {
    if (is_palindromic_num(i)) ans++;
  }
  cout << ans << endl;
  return 0;
}
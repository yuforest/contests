// g++ -o c.out c.cpp -std=c++11
// oj d https://atcoder.jp/contests/abc219/tasks/abc219_c
// oj t -c "./c.out"
// oj s https://atcoder.jp/contests/abc219/tasks/abc219_c c.cpp

#include <bits/stdc++.h>
using namespace std;
int n, k;
int c[300005];
map<int, int> mp;
long long mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (n); ++i)

vector<pair<char, int>> encode(const string& str) {
  int n = (int)str.size();
  vector<pair<char, int>> ret;
  for (int l = 0; l < n;) {
      int r = l + 1;
      for (; r < n && str[l] == str[r]; r++) {};
      ret.push_back({str[l], r - l});
      l = r;
  }
  return ret;
}

int main(void)
{
  string S, T;
  cin >> S >> T;

  vector<pair<char, int>> S_array;
  vector<pair<char, int>> T_array;
  S_array = encode(S);
  T_array = encode(T);
  string ans = "Yes";
  if (S_array.size() != T_array.size()) {
    ans = "No";
  } else {
    for (int i = 0; i < S_array.size(); i++) {
      if (S_array[i].first != T_array[i].first) {
        ans = "No";
      }
      if (S_array[i].second > T_array[i].second) {
        ans = "No";
      }
      if (S_array[i].second != T_array[i].second && S_array[i].second == 1) {
        ans = "No";
      }
    }
  }

  cout << ans << endl;


}
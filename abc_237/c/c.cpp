// g++ -o c.out c.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc233/tasks/abc233_c
// oj t -c "./c.out"
// oj s https://atcoder.jp/contests/abc233/tasks/abc233_c c.cpp


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
long long minimum_time = 0;
vector<bool> used(200007, false);
vector<vector<int>> G1(10, vector<int>());
vector<vector<int>> G2(10, vector<int>());
long long K[200007];
long long T[200007];
#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  int s_count = S.size();
  while(true) {
    if (S[s_count-1] == 'a') {
      s_count--;
    } else {
      break;
    }
  }
  int last_s_count = S.size() - s_count;
  S = S.erase(s_count);
  s_count = 0;
  while(true) {
    if (S[s_count] == 'a') {
      s_count++;
    } else {
      break;
    }
  }
  S = S.erase(0, s_count);
  // cout << S << endl;
  string reversed_S = S;
  reverse(reversed_S.begin(), reversed_S.end());
  if (S == reversed_S && last_s_count >= s_count) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}

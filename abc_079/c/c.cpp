// g++ -o c.out c.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc226/tasks/abc226_c
// oj t -c "./c.out"
// oj s https://atcoder.jp/contests/abc226/tasks/abc226_c c.cpp


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
long long minimum_time = 0;
vector<bool> used(200007, false);
vector<int> G[1 << 18];
long long K[200007];
long long T[200007];



int main()
{
  string S;
  cin >> S;
  int nums[4];
  for (int i = 0; i < 4; i++) {
    nums[i] = S[i] - '0';
  }
  vector<string> operator_combinations;
  char operators[2] = {'+', '-'};
  rep(i, 2) {
    rep(j, 2) {
      rep(k, 2) {
        string tmp = "";
        tmp  += operators[i];
        tmp  += operators[j];
        tmp  += operators[k];
        operator_combinations.push_back(tmp);
      }
    }
  }
  for (auto operator_combination: operator_combinations) {
    int sum = nums[0];
    string ans = "";
    ans += '0' + nums[0];
    for (int i = 0; i < 3; i++) {
      if (operator_combination[i] == '+') {
        sum += nums[i+1];
      } else {
        sum -= nums[i+1];
      }
      ans += operator_combination[i];
      ans += '0' + nums[i+1];
    }
    if (sum == 7) {
      ans += "=7";
      cout << ans << endl;
      break;
    }
  }
}
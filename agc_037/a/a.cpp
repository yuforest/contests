// g++ -o a.out a.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc235/tasks/abc235_a
// oj t -c "./a.out"
// oj s https://atcoder.jp/contests/abc235/tasks/abc235_a a.cpp

#include <bits/stdc++.h>
using namespace std;
int n, k;
int c[300005];
map<int, int> mp;
long long mod = 1000000007;

int main(void)
{
  string s;
  cin >> s;
  int n = s.size();
  vector<int> dp(n,0);
  dp[0] = 1;
  if(n == 1){
    cout << 1 << endl;
    return 0;
  }
  string first = "";
  first += s[0];
  string second = "";
  second += s[1];
  for(int i = 0; i < n - 1; i++){
    if(first == second){
      dp[i+1] = dp[i];
      if (i < n - 2) {
        second = second + s[i+2];
      }
    } else {
      // S[i]とS[i+1]が異なるのでカウントを増やす
      dp[i+1] = dp[i] + 1;
      if (i < n - 2) {
        first = second;
        second = s[i+2];
      }
    }
  }
  cout << dp[n-1] << endl;

  return 0;
}
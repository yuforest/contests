// g++ -o a.out a.cpp -std=c++17
// oj d https://atcoder.jp/contests/agc_012/tasks/agc_012_a
// oj t -c "./a.out"
// oj s https://atcoder.jp/contests/agc_012/tasks/agc_012_a a.cpp

#include <bits/stdc++.h>
using namespace std;
int n, k;
int c[300005];
map<int, int> mp;
long long mod = 1000000007;
using ll = long long;

int main(void)
{
  string s;
  cin >> s;
  ll ans = 100;
  // 全探索
  for(char i='a'; i<='z'; i++){
      auto itr = s.begin() - 1;
      ll ans1 = 0;
      // 特定の文字が次に現れるところまでを取得してその最大値を検索している
      while(itr != s.end()){
          auto tmp = itr;
          itr = find(itr+1, s.end(), i);
          // −1は縮んだ分
          ans1 = max(ll(itr - tmp) - 1, ans1);
      }
      // 操作回数の最小値を更新
      ans = min(ans, ans1);
  }
  cout << ans << endl;
}
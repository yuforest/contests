// g++ -o a.out a.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc222/tasks/abc222_a
// oj t -c "./a.out"
// oj s https://atcoder.jp/contests/abc222/tasks/abc222_a c.cpp

#include <bits/stdc++.h>
using namespace std;
int n, k;
int c[300005];
map<int, int> mp;
long long mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (n); ++i)

// 別解、全探索
// string s[60];
// int main() {
//   int n;
//   cin >> n;
//   for(int i=0; i<n;i++){
//     cin >> s[i];
//   }
//   string ans = "";
//   for (char c='a'; c<='z'; c++) {
//   	int small = 99999999;
// 		for (int i=0;i<n;i++) {
//       int cnt = 0;
//       for(int j=0;j<s[i].length();j++){
//         if(s[i][j] == c) cnt++;
//       }
// 			small = min(small, cnt);
//     }
//   	for(int i=0; i<small; i++) ans += c;
//   }
//   cout << ans << endl;
// }

int main(void)
{
  int N;
  cin >> N;
  string S[N];
  rep(i, N) {
    cin >> S[i];
  }

  if (N == 1) {
    string single_ans = S[0];
    sort(single_ans.begin(), single_ans.end());
    cout << single_ans << endl;
    return 0;
  }
  // 最初の積集合を作る
  map<char, int> tmp1;
  for (auto c: S[0]) {
    tmp1[c]++;
  }
  map<char, int> tmp2;
  for (auto c: S[1]) {
    tmp2[c]++;
  }
  map<char, int> ans;
  for (auto e: tmp1) {
    if (tmp2[e.first] > 0) {
      ans[e.first] = min(tmp1[e.first], tmp2[e.first]);
    }
  }

  rep(i, N) {
    map<char, int> tmp;
    for (auto c: S[i]) {
      tmp[c]++;
    }
    map<char, int> new_ans;
    for (auto e: tmp) {
      if (ans[e.first] > 0) {
        new_ans[e.first] = min(ans[e.first], tmp[e.first]);
      }
    }
    ans = new_ans;
  }
  string str_ans = "";
  for (auto e: ans) {
    rep(i, e.second) {
      str_ans += e.first;
    }
  }
  cout << str_ans << endl;

}
// g++ -o d.out d.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc229/tasks/abc229_d
// oj t -c "./d.out"
// oj s https://atcoder.jp/contests/abc229/tasks/abc229_d d.cpp

#include <bits/stdc++.h>
using namespace std;
int n, k;
int c[300005];
map<int, int> mp;

int main(void)
{
  string S;
  int K;
  cin >> S >> K;

  int count = 0;
  int tmp_count = 0;
  int tmp_K = K;
  for (int i = 0; i < S.size(); i++) {
    if (S[i] == 'X') {
      tmp_count++;
    } else {
      if (tmp_K > 0) {
        tmp_K--;
        tmp_count++;
      } else {
        count = max(count, tmp_count);
        tmp_K = K-1;
        tmp_count = 1;
      }
    }
  }
  count = max(count, tmp_count + tmp_K);
  int S_size = S.size();
  count = min(count,  S_size);
  cout << count << endl;
}
// g++ -o c.out c.cpp -std=c++11
// oj d https://atcoder.jp/contests/abc215/tasks/abc215_c
// oj t -c "./c.out"
// oj s https://atcoder.jp/contests/abc215/tasks/abc215_c c.cpp

#include <bits/stdc++.h>
using namespace std;
int n, k;
int c[300005];
map<int, int> mp;
long long mod = 1000000007;

int main(void)
{
  string S;
  int K;
  cin >> S >> K;
  sort(S.begin(), S.end());
	string answer;
  int count = 0;
	do {
    count++;
    if (K == count) answer = S;
	} while (next_permutation(S.begin(), S.end()));
  cout << answer << endl;
}
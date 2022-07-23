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
#define rep(i, n) for (ll i = 0; i < (n); ++i)

int main() {
  string S;
  long long K;
  cin >> S >> K;
  // 同じ文字が続いた回数をカウントする配列
  vector<long long> v;
  for (int i = 0; i < S.size();) {
    int j = i;
    while (j < S.size() && S[j] == S[i]) ++j;
    v.push_back(j - i);
    i = j;
  }
  if (S[0] != S.back()) {
    long long sum = 0;
    for (auto c : v) sum += c/2;
    cout << sum * K << endl;
  } else {
    if (v.size() == 1) cout << v[0] * K / 2 << endl;
    else {
      long long left = v[0], right = v.back(), mid = 0;
      for (int i = 1; i+1 < v.size(); ++i) mid += v[i]/2;
      cout << mid*K + (left+right)/2 * (K-1) + left/2 + right/2 << endl;
    }
  }
}
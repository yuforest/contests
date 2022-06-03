// g++ -o c.out c.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc028/tasks/abc028_c
// oj t -c "./c.out"
// oj s https://atcoder.jp/contests/abc028/tasks/abc028_c c.cpp


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int A[5];
  rep(i, 5) {
    cin >> A[i];
  }
  vector<int> numbers;
  for (int i = 0; i < 5; i++) {
    for (int j = i+1; j < 5; j++) {
      for (int k = j+1; k < 5; k++) {
        int sum = A[i] + A[j] + A[k];
        numbers.push_back(sum);
      }
    }
  }
  sort(numbers.begin(), numbers.end());
  numbers.erase(unique(numbers.begin(), numbers.end()), numbers.end());
  sort(numbers.begin(), numbers.end(), greater<int>());
  cout << numbers[2] << endl;
}
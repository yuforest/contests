// g++ -o d.out d.cpp -std=c++11
// oj d https://atcoder.jp/contests/abc212/tasks/abc212_d
// oj t -c "./d.out"
// oj s https://atcoder.jp/contests/abc212/tasks/abc212_d d.cpp




#include <bits/stdc++.h>
using namespace std;
int n, k;
int c[300005];
map<int, int> mp;
long long mod = 1000000007;

int main(void)
{
  int Q;
  cin >> Q;

  priority_queue<
      long long,                // 要素の型はint
      std::vector<long long>,   // 内部コンテナはstd::vector (デフォルトのまま)
      std::greater<long long>   // 昇順 (デフォルトはstd::less<T>)
    > que;
  long long sum = 0;
  vector<long long> answers;


  for (int i = 0; i < Q; i++) {
    long long operation;
    long long X;
    cin >> operation;
    if (operation == 1) {
      cin >> X;
      X -= sum;
      que.push(X);
    }
    if (operation == 2) {
      cin >> X;
      sum += X;
    }
    if (operation == 3) {
      long long top = que.top() * 1LL;
      long long val = top + sum;
      answers.push_back(val);
      que.pop();
    }
  }
  int size = answers.size();
  for (int i = 0; i < size; i++) {
    cout << answers.at(i) << endl;
  }
}
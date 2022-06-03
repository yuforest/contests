// g++ -o b.out b.cpp -std=c++11
// oj d https://atcoder.jp/contests/abc216/tasks/abc216_b
// oj t -c "./b.out"
// oj s https://atcoder.jp/contests/abc216/tasks/abc216_b b.cpp


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int b_count = 0;
int N;
vector<int> A;

void recursive(vector<int> array, int index) {
  if (array.size() == N) {
    int multiple = 1;
    for (int i = 0; i < N; ++i) {
      multiple *= array[i];
    }
    if (multiple % 2 == 0) b_count++;
    return;
  }
  vector<int> minus = array;
  minus.push_back(A[index]-1);
  recursive(minus, index+1);

  vector<int> same = array;
  same.push_back(A[index]);
  recursive(same, index+1);

  vector<int> plus = array;
  plus.push_back(A[index]+1);
  recursive(plus, index+1);
}

int main()
{
  cin >> N;
  for (int i = 0; i < N; ++i) {
    int val;
    cin >> val;
    A.push_back(val);
  }
  recursive({}, 0);
  cout << b_count << endl;
}
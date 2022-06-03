// g++ -o c.out c.cpp -std=c++11
// oj d https://atcoder.jp/contests/abc213/tasks/abc213_c
// oj t -c "./c.out"
// oj s https://atcoder.jp/contests/abc213/tasks/abc213_c c.cpp




#include <bits/stdc++.h>
using namespace std;
int n, k;
int c[300005];
map<int, int> mp;
long long mod = 1000000007;

int main(void)
{
  int H, W, N;
  cin >> H >> W >> N;
  int A[N];
  int B[N];
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    cin >> B[i];
  }
  vector<int> vecA;
  vector<int> vecB;
  for (int i = 0; i < N; ++i) vecA.push_back(A[i]);
  for (int i = 0; i < N; ++i) vecB.push_back(B[i]);
  sort(vecA.begin(), vecA.end());
  vecA.erase(unique(vecA.begin(), vecA.end()), vecA.end());
  sort(vecB.begin(), vecB.end());
  vecB.erase(unique(vecB.begin(), vecB.end()), vecB.end());

  for (int i = 0; i < N; ++i) {
    int idA = lower_bound(vecA.begin(), vecA.end(), A[i]) - vecA.begin();
    int idB = lower_bound(vecB.begin(), vecB.end(), B[i]) - vecB.begin();
    // cout << A[i] << " " << B[i] << endl;
    cout << idA + 1 << " " << idB + 1 << endl;
  }
}
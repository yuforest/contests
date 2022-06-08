// g++ -o b.out b.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc226/tasks/abc226_b
// oj t -c "./b.out"
// oj s https://atcoder.jp/contests/abc226/tasks/abc226_b b.cpp


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main()
{
  int A, B, K;
  cin >> A >> B >> K;
  set<int> st{};
  for(int i = A; i < A + K; i++) {
    if (i > B) break;
    st.insert(i);
  }
  for(int i = B; i > B - K; i--) {
    if (i < A) break;
    st.insert(i);
  }
  for(auto x : st) {
    cout << x << endl;
  }
  return 0;
}
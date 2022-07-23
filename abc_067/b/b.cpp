// g++ -o b.out b.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc226/tasks/abc226_b
// oj t -c "./b.out"
// oj s https://atcoder.jp/contests/abc226/tasks/abc226_b b.cpp


#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i<b; i++)
#define rep0(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

string S;
int solve() {
    int N = S.length();
    int ans = 0;
    rep(i, 2, N - 1) if (i % 2 == 0) {
        string A = S.substr(0, i / 2);
        string B = S.substr(i / 2, i / 2);
        if (A == B) ans = max(ans, i);
    }
    return ans;
}

int main()
{

  cin >> S;
  cout << solve() << endl;
}
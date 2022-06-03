// g++ -o c.out c.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc233/tasks/abc233_c
// oj t -c "./c.out"
// oj s https://atcoder.jp/contests/abc233/tasks/abc233_c c.cpp


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
long long minimum_time = 0;
vector<bool> used(200007, false);
vector<vector<int>> G1(10, vector<int>());
vector<vector<int>> G2(10, vector<int>());
long long K[200007];
long long T[200007];
#include <bits/stdc++.h>
using namespace std;

string toBinary(long long n)
{
    string r;
    while (n != 0){
      r += ( n % 2 == 0 ? "0" : "2" );
      n /= 2;
    }
    reverse(r.begin(), r.end());
    return r;
}

int main() {
  long long K;
  cin >> K;

  string ans = toBinary(K);

  cout << ans << endl;


  return 0;
}

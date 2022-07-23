// g++ -o c.out c.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc226/tasks/abc226_c
// oj t -c "./c.out"
// oj s https://atcoder.jp/contests/abc226/tasks/abc226_c c.cpp


#include <bits/stdc++.h>
// #define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
long long minimum_time = 0;
vector<bool> used(200007, false);
vector<int> G[1 << 18];
long long K[200007];
// long long T[200007];
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)


string SS, T;
//---------------------------------------------------------------------------------------------------
string solve() {
    int N = SS.length();
    int M = T.length();

    set<string> ans;
    // 右から順番に見ていく、Nから初めてMまでデクリメントしていく
    rrep(R, N, M) {
      // 現在のインデックスからMを引いたもの、Tの初めの文字のインデックス
      int L = R - M;

      int ok = 1;
      // M文字の文字列Tを入れることができない時はokを0に変更
      rep(i, 0, M) if (SS[L + i] != '?' && SS[L + i] != T[i]) ok = 0;
      // OKの時は文字列を組み立てる
      if (ok) {
        string S;
        // 復元前の文字列を追加
        rep(i, 0, N) S += SS[i];
        // Tが入るべき場所を埋めていく作業
        rep(i, 0, M) S[L + i] = T[i];
        // ?になっているところは全てaに置換する作業
        rep(i, 0, N) if (S[i] == '?') S[i] = 'a';
        ans.insert(S);
      }
    }

    if(ans.size() == 0) return "UNRESTORABLE";
    return *(ans.begin());
}
//---------------------------------------------------------------------------------------------------

int main() {
  cin >> SS >> T;
  cout << solve() << endl;
  return 0;
}
// g++ -o a.out a.cpp -std=c++11
// oj d https://atcoder.jp/contests/abc217/tasks/abc217_a
// oj t
// oj s https://atcoder.jp/contests/abc217/tasks/abc217_a a.cpp

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
// greatest common divisor
ll gcd(ll a, ll b) { return a ? gcd(b % a, a) : b; }
// least common multiple
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

int main(){

  string s;
  cin >> s;

  int n = s.size();

  // 26文字以下であれば使われていない文字の内最小のものをくっつけて返す
  if(n!=26){
    vector<bool> isUsed(26);
    for(char c: s) isUsed[ c - 'a' ] = true;
    for(int i=0 ;i<26; i++) {
      if(!isUsed[i]){
        cout << s << (char)('a' + i) << endl;
        return 0;
      }
    }
  }else{
    // そうでない場合
    vector<bool> rem(26);
    // 最後の文字を数字で記録
    rem[ s[25] - 'a' ] = true;
    s.pop_back();
    // 25文字目から逆にループ
    for(int i=24; i>=0; i--){
      // 全ての文字を検索
      for(int j=0; j<26; j++){
        // 記録されていて現在検索中の文字より辞書順で小さければ、最後の文字を削除してj番目の文字追加して表示
        if(rem[j] && s[i] - 'a' < j){
          s.pop_back();
          cout << s << (char)(j + 'a') << endl;
          return 0;
        }
      }
      // 上記に引っ掛からなければ記録して、最後の文字を削除
      rem[ s[i] - 'a' ] = true;
      s.pop_back();
    }
  }
  cout << -1 << endl;
  return 0;
}

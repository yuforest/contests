// ここは競プロではサボりがちです
#include <bits/stdc++.h>
using namespace std;

// デバッグ用マクロです。詳しくは https://naskya.net/post/0002/
#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

// 節操ないですが、競プロでは便利です。
using ll = long long;
using vi = vector<int>;
using vl = vector<long long>;
using vs = vector<string>;
using vc = vector<char>;
using vb = vector<bool>;
using vpii = vector<pair<int, int>>;
using vpll = vector<pair<long long, long long>>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<long long>>;
using vvc = vector<vector<char>>;
using vvb = vector<vector<bool>>;
using vvvi = vector<vector<vector<int>>>;
using pii = pair<int, int>;

map<int, int> mp;
long long mod = 1000000007;
vector<ll> G[1 << 18];

// ACLです。使わない時はコメントアウトしています。導入方法はググってみてください。
// #include <atcoder/all>
// using namespace atcoder;

// 競プロerはrepマクロが大好き
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep3(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(), (x).end()

// 無くても困らない
#define INFTY (1 << 30)

// 浮動小数点の誤差を考慮した等式ですが、使わずに済むなら使わない方が確実です
#define EPS (1e-7)
#define equal(a, b) (fabs((a) - (b)) < EPS)

#define yes "Yes"
#define no "No"

// DPやlong longの最大値最小値更新で重宝します。
template <typename T>
inline bool chmax(T &a, T b) {
  return ((a < b) ? (a = b, true) : (false));
}
template <typename T>
inline bool chmin(T &a, T b) {
  return ((a > b) ? (a = b, true) : (false));
}

// 最初が小文字で_を含まない場合はキャメルケース
bool isCamel(string s){
  return islower(s[0]) && s.find('_')==string::npos;
}


bool is_snake(string s){
  rep(i,s.length()){
    // 大文字が含まれておらず
    if(isupper(s[i])) return false;
    // 0以外の文字の一つ前が_の時、今の文字が小文字でなければいけない
    if(i==0 || s[i-1]=='_') if(!islower(s[i])) return false;
  }
  return true;
}

int main(){
  string s; cin>>s;

  // 先頭と末尾の _ を消す
  int head=0,tail=0;
  // 最初の文字が_であるかぎり消してheadを増やす
  while(!s.empty() && s[0]=='_') s=s.substr(1), head++;
  // 最後の文字が_であるかぎり消して、tailを増やす
  while(!s.empty() && s[(int)s.length()-1]=='_') s=s.substr(0,(int)s.length()-1), tail++;

  // 最初の_を出力
  cout<<string(head,'_');
  // 残った文字列がキャメルケースなら
  if(isCamel(s)){
    // 大文字は小文字、それ以外はそのまま出力
    rep(i,s.length()){
      if(isupper(s[i])){
        cout<<'_'<<(char)tolower(s[i]);
      } else{
        cout<<s[i];
      }
    }
  } else if(is_snake(s)){
    // _ならiを増やして、増やした後の文字を大文字で出力
    // そうでなければそのまま出力
    rep(i,s.length()){
      if(s[i]=='_'){
        i++;
        cout<<(char)toupper(s[i]);
      }
      else{
        cout<<s[i];
      }
    }
  } else {
    // どちらでもなければそのまま出力
    cout<<s;
  }
  // 最後の_を出力
  cout<<string(tail,'_')<<endl;

  return 0;
}
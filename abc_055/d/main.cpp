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

// DPやlong longの最大値最小値更新で重宝します。
template <typename T>
inline bool chmax(T &a, T b) {
  return ((a < b) ? (a = b, true) : (false));
}
template <typename T>
inline bool chmin(T &a, T b) {
  return ((a > b) ? (a = b, true) : (false));
}


#define N 100010
int n;
char s[N];
int a[N];

void print(){
  for(int i=1;i<=n;i++) printf("%c",a[i]?'W':'S');
}

// 矛盾しないか判定
bool judge(int d,char c,int x,int y){
  // 最初が羊の時cがoなら両端は同じ
  if(d==0&&c=='o'&&x==y){return 1;}
  // 最初が羊の時cがxなら両端は異なる
  if(d==0&&c=='x'&&x!=y){return 1;}
  // 最初が狼の時cがxなら両端は同じ
  if(d==1&&c=='x'&&x==y){return 1;}
  // 最初が狼の時cがoなら両端は異なる
  if(d==1&&c=='o'&&x!=y){return 1;}
  return 0;
}

int main(){
  scanf("%d",&n);
  // 1からNまでに文字を入れる
  scanf("%s",s+1);
  rep(i, n+1) debug(s[i]);
  // 0: S 1: W
  for(int d0=0;d0<=1;d0++){
    for(int d1=0;d1<=1;d1++){
      // 最初の2つを決めて、残りを決める
      a[1]=d0;
      a[2]=d1;
      for(int i=3;i<=n;i++){
        // 1つ前が羊でoなら、今の文字は2つ前と同じ
        if(a[i-1]==0 && s[i-1]=='o') a[i]=a[i-2];
        // 1つ前が羊でxなら、今の文字は2つ前と異なる
        if(a[i-1]==0 && s[i-1]=='x') a[i]=a[i-2]^1;
        // 1つ前が狼でxなら、今の文字は2つ前と同じ
        if(a[i-1]==1 && s[i-1]=='x') a[i]=a[i-2];
        // 1つ前が狼でoなら、今の文字は2つ前と異なる
        if(a[i-1]==1 && s[i-1]=='o') a[i]=a[i-2]^1;
      }
      // 矛盾しないか確かめて問題なければ出力
      if(judge(a[1],s[1],a[n],a[2])&&judge(a[n],s[n],a[n-1],a[1])){
        print();
        return 0;
      }
    }
  }
  // 実現不可能な場合
  printf("-1");
  return 0;
}
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

int main()
{
  static char s[1000100];
  scanf("%s",s);
  int n=strlen(s);
  // mは最初のかぶりんの数、コンボ数は0
  int m=5,C=0;
  // スコア
  long long A=0;
  static int K[1000100]={0},H[1000100]={0};
  for(int i=0;i<n;){
    // 通常投げでかぶりんが1匹以上いる
    if(s[i]=='N'&&m>=1){
      m--;
      // コンボを含めたダメージ計算
      A+=10+(C/10);
      // ここで戻ってきたかぶりんやコンボ数は次の時間から適用される
      // 今の時間から6秒後に帰ってくる
      K[i+6]++;
      // ダメージを与えるとコンボ数が増える
      H[i+1]++;
      // 今の時間に帰ってきたかぶりんを増やす
      m+=K[i];
      // 今の時間のコンボ数を増やす
      C+=H[i];
      // 時間を進める
      i++;
    } else if(s[i]=='C'&&m>=3){
      // ため投げでかぶりんが3匹以上いる
      m-=3;
      // コンボを含めたダメージ計算
      A+=50+(C/10)*5;
      // ここで戻ってきたかぶりんやコンボ数は次の時間から適用される
      // 今の時間から8秒後に帰ってくる
      K[i+8]+=3;
      // 今の時間から3秒後にダメージを与えてコンボ数が増える
      H[i+3]++;
      // 投げるまでは何もできないので
      // 帰ってきたかぶりんとコンボの計算だけして進める
      for(int t=0;t<3;t++){
        m+=K[i];
        C+=H[i];
        i++;
      }
    } else{
      // この時は何もできないので、手元に帰ってきたかぶりんと
      // ダメージを与えたコンボ数を増やす
      m+=K[i];
      C+=H[i];
      i++;
    }
  }
  printf("%lld\n",A);
  return 0;
}
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
// vector<ll> G[1 << 18];

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

int N,M;
string pat[1002];
string first,last;
bool G[1002][1002];
int back[1002];
int cost[1002];

// 1文字以内の変更で一緒の文字列になるかどうか
bool match(const string &s,const string &t){
  int wrong=0;
  rep(i,M){
    if(s[i]!=t[i])wrong++;
    if(wrong>1)return false;
  }
  return true;
}

int main(){
  cin>>first>>last;
  // 文字サイズ
  M=first.size();
  // 入力
  cin>>N;
  for(int i=0;i<N;i++){
    cin>>pat[i];
  }
  // 最初と最後が同じ場合は1度も操作する必要がない
  if(first==last){
    cout<<0<<endl;
    cout<<first<<endl<<first<<endl;
    return 0;
  }
  // 最初と最後もセットしておく
  pat[N]=first;
  pat[N+1]=last;
  // その分増やして
  N+=2;
  // 2重ループを回して、グラフを構築する
  // 1文字以内の変更で同じ文字になれば辺をつなげる
  rep(i,N){
    rep(j,N){
      if(match(pat[i],pat[j])){
        G[i][j]=true;
      }
    }
  }
  // スタートとゴールを決める
  int s=N-2,e=N-1;
  // コストの配列を-1で初期化
  memset(cost,-1,sizeof(cost));
  // スタートのコストは0
  cost[s]=0;
  queue<int> que;
  que.push(s);
  // 幅優先探索
  while(!que.empty()){
    int now=que.front();
    que.pop();
    // 今の頂点と繋がっている頂点には
    // 今の頂点までのコスト+1で移動できる
    rep(i,N){
      // 未訪問ならば
      if(G[now][i]&&cost[i]==-1){
        // コストをセットして探索候補に追加
        cost[i]=cost[now]+1;
        que.push(i);
        // 次の頂点に対する今の頂点を保存しておく
        back[i]=now;
      }
    }
  }
  // 探索後に最後まで到達できていなければ実現不可能
  if(cost[e]==-1){
    cout << -1 << endl;
    return 0;
  }
  // 移動回数-1(間にある単語の数)を出力
  cout<<cost[e]-1<<endl;
  vector<string> res;
  // 最後から辿って最初に行き着くまで単語を追加する
  while(e!=s){
    res.push_back(pat[e]);
    // 前の頂点に行く
    e=back[e];
  }
  // 最後から入っているので逆にする
  reverse(res.begin(),res.end());

  // 最初は入っていないので出力して
  cout << first << endl;
  // 残りも出力する
  rep(i,res.size()){
    cout<<res[i]<<endl;
  }
}
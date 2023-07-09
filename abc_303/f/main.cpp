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
#include <atcoder/all>
using namespace atcoder;

// 競プロerはrepマクロが大好き
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep3(i,a,b) for(int i=a;i<b;i++)
#define per(i, b) per2(i, 0, b)
#define per3(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
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

int N;
long H;
int main()
{
  cin>>N>>H;
  vector<pair<int,int> >td(N);
  for(int i=0;i<N;i++) {
    cin>>td[i].first>>td[i].second;
  }
  // 与える総ダメージが大きい順にソート
  sort(td.begin(),td.end(),[](pair<int,int>l,pair<int,int>r)
  {
    return (long)l.first*l.second>(long)r.first*r.second;
  });
  debug(td);
  vector<pair<int,int> >TD;
  for(pair<int,int>p:td)
  {
    // 最初の要素はpush
    // それ以降は、最後の要素のターンが今のターンより大きく、
    // 最後の要素のダメージが今のダメージより小さい場合にpush
    // つまり持続ターンが長く、ダメージが小さいものを優先してpush
    if(TD.empty())TD.push_back(p);
    else if(TD.back().first>p.first&&TD.back().second<p.second)TD.push_back(p);
  }
  // 逆順にして持続ターンが長い順にする
  reverse(TD.begin(),TD.end());
  debug(TD);
  vector<long>LIM;
  LIM.push_back(1);
  for(int i=1;i<TD.size();i++)
  {
    long t=(long)TD[i-1].first*TD[i-1].second;
    t=(t+TD[i].second-1)/TD[i].second;
    assert(LIM.back()<t);
    assert(t<=TD[i].first);
    LIM.push_back(t);
  }
  long L=0,R=H;
  while(R-L>1)
  {
    long M=(L+R)/2;
    __int128 T=H;
    for(int i=0;i<TD.size();i++)if(LIM[i]<=M)
    {
      long l=LIM[i];
      long r=M+1;
      if(i+1<TD.size())r=min(r,LIM[i+1]);
      long t=TD[i].first;
      long d=TD[i].second;
      assert(l<=t);
      if(t<r)
      {
        T-=(__int128)(r-t)*t*d;
        r=t;
      }
      T-=d*((__int128)r*(r-1)/2-(__int128)l*(l-1)/2);
      if(T<=0)break;
    }
    if(T<=0)R=M;
    else L=M;
  }
  cout<<R<<endl;
}
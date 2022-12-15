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

long long mod = 1000000007;
// vector<ll> G[1 << 18];

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

#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  // 入力を受け取る
  int n,m,k;
  cin >> n >> m >> k;
  vector<int>a(n);
  for(int i=0;i<n;i++)cin >> a[i];

  ll ans=0;
  // 現在の管理するべき集合の中で
  // 小さい方からK個を管理する集合と
  // それ以外の大きい値を管理する集合を
  // multisetで定義する
  multiset<int>small,large;

  // 値を追加して小さい集合と大きい集合の整合性を取る処理を行う
  auto push=[&](int x){
    // 小さい方に値を入れる
    small.insert(x);
    // 総和に足す
    ans+=x;
    // 制限個数を超えていたら下記の処理を行う
    if(small.size()>k){
      // 小さい方の最後の値を取得(つまり一番大きい値)
      auto it=--small.end();
      // largeの方にその値を入れて
      large.insert(*it);
      // 総和から引いた後に
      ans-=*it;
      // 削除する
      small.erase(it);
    }
  };

  // 値を削除して、小さい集合と大きい集合の整合性を取る処理を行う
  auto pop=[&](int x){
    // 小さい方にするべき値が存在するか確認
    auto it=small.find(x);
    // 小さい方に存在する時
    if(it!=small.end()){
      // 総和から引いたあと
      ans-=*it;
      // 削除して
      small.erase(it);
      // 大きい集合の最初の値を取得
      it=large.begin();
      // 総和に足して
      ans+=*it;
      // 小さい方に追加した後
      small.insert(*it);
      // 大きい方から削除する
      large.erase(it);
    }else{
      // この時は大きい方に存在するのでそれを削除する
      it=large.find(x);
      large.erase(it);
    }
  };

  vl answers;

  // 最初のm個をpushする
  for(int i=0;i<m;i++) push(a[i]);
  // 最初の答えを出力
  answers.push_back(ans);

  for(int i=m;i<n;i++){
    // m以降の値を追加していく
    push(a[i]);
    // m個前の値を削除する
    pop(a[i-m]);
    // 答えを出力
    answers.push_back(ans);
  }
  rep(i, answers.size()) {
    if (i) cout << " ";
    cout << answers[i];
  }
  cout << endl;
}
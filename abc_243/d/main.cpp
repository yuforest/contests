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


// 幅優先探索でも解ける
// int main(){
//   string s;
//   cin >> s;

//   map<string,int> mp;
//   queue<string> q;

//   mp[s]=0;
//   q.push(s);

//   while(!q.empty()){
//     string current=q.front();q.pop();
//     if(current=="atcoder"){
//       cout << mp[current] << "\n";
//       return 0;
//     }

//     for(int i=1;i<7;i++){
//       string next=current;
//       swap(next[i-1],next[i]);
//       if(mp.find(next)==mp.end()){
//         q.push(next);
//         mp[next] = mp[current]+1;
//       }
//     }
//   }
//   return 0;
// }


vector<int> bit;
int sum(int i){
  int s = 0;
  while(i>0){
    s += bit[i];
    i -= i & (-i);
  }
  return s;
}

void add(int i,int x){
  while(i < bit.size()){
    bit[i] += x;
    // iの最後の1bitを足している
    i += i & (-i);
  }
}

// bubblesortでも解ける
// int ans = 0;
// vi bubblesort(vector<int> array,int size){
// 	for(int i = 0; i < size; i++){
// 		for(int j = i + 1; j < size; j++){
// 			if(array[i] > array[j]){
// 				int number = array[i];
// 				array[i] = array[j];
// 				array[j] = number;
//         ans++;
// 			}
// 		}
// 	}
//   return array;
// }

int main(){
  bit.resize(10);
  for(int i=0;i<10;i++) {
    bit[i]=0;
  }

  string s;
  cin >> s;
  map<char,int> mp;
  string atc="*atcoder";
  // mapの各文字に対して何文字目なのかという情報が入る
  for(int i=1;i<=7;i++){
    mp[atc[i]] = i;
  }
  vector<int> a = {-1};
  // 入力された文字がatcoderの何文字目なのかという情報
  for(int i=0;i<7;i++) {
    a.push_back(mp[s[i]]);
  }
  // a = bubblesort(a, 8);

  int res = 0;
  for(int i = 1;i<=7;i++){
    // BITの総和 - 自分より左側 = 自分より右側
    res += (i-1-sum(a[i]));
    // 自分の位置に1を足す
    add(a[i], 1);
  }
  cout << res << "\n";
  return 0;
}
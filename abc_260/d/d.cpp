#include<bits/stdc++.h>

using namespace std;

int main(){
  int n, k;
  cin >> n >> k;
  vector<int> under(n+5,-1);
  vector<int> pile(n+5,0);
  // 積まれたカードのうち最大のもの
  set<int> st;
  vector<int> res(n+5,-1);
  for(int i=1;i<=n;i++){
    int p;
    cin >> p;
    // 場の中で最小のものを見つける(場にあるカードで現在のカードより大きいものを探す)
    auto it = st.upper_bound(p);
    // 最小のものがなければ、カードを積み上げる
    if(it==st.end()){
      pile[p] = 1;
      st.insert(p);
    } else{
      // 見つかった場合、現在のカードの下にそのカードを入れる
      under[p] = (*it);
      // カードを積み上げる
      pile[p] = pile[(*it)]+1;
      // 一番上のカードを変更
      st.erase(it);
      st.insert(p);
    }
    // 現時点でk枚積み上がったら
    if(pile[p]==k){
      // 一番上のカードを消す
      st.erase(p);
      int x=p;
      for(int j=0;j<k;j++){
        // 現在のターンを入れる
        res[x]=i;
        // xに下にあるカードを代入(underを使って）
        x=under[x];
      }
    }
  }

  for(int i=1;i<=n;i++){cout << res[i] << "\n";}
  return 0;
}

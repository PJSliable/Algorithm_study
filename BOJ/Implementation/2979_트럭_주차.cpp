#include <bits/stdc++.h>
using namespace std;
int a, b, c, arrive, leave, total;
int l[101];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> a >> b >> c;
  for (int j = 0; j < 3; j++){
    cin >> arrive >> leave;
    for (int i = arrive; i < leave;i++){
      l[i]++;
    }
  }

  for (int j:l){
    if(j ==1){
      total += a;
    }else if(j==2){
      total += 2*b;
    }else if(j==3){
      total += 3*c;
    }
  }

  cout << total << '\n';
  return 0;
}
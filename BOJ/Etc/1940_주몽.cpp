#include <bits/stdc++.h>
using namespace std;
int N, M, now, mv, cnt[100001], ans;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  cin >> M;

  for (int i = 0; i < N; i++){
    cin >> now;
    cnt[now]++;
  }
  
  for (int i = 1; i <= int(M / 2); i++)
  {
    if (M-i < 100000 && cnt[i] && cnt[M-i] && (2*i != M)){
      ans += 1;
    }
  }
  cout << ans <<'\n';
  return 0;
}
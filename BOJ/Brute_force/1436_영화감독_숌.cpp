#include <bits/stdc++.h>
using namespace std;
int N, cnt, ret;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> N;
  while(N != cnt){
    ret++;
    if (to_string(ret).find("666") != string::npos)cnt++;
  }
  cout << ret << '\n';
  return 0;
}
#include <bits/stdc++.h>
using namespace std;

int N, M, j, lo, ret;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> N >> M;
  cin >> j;
  int start = 1;
  for (int i = 0; i < j; i++){
    int end = start + M - 1;
    cin >> lo;
    if (lo < start)
    {
      ret += start - lo;
      start = lo;
      continue;
    }
    if (lo > end){
      ret += lo - end;
      start += lo - end;
    }
  }
  cout << ret << '\n';
  return 0;
}
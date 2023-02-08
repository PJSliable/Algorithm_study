#include <bits/stdc++.h>
using namespace std;

int N, a[1000001], ret[1000001];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> N;
  stack<int> stk;
  fill(&ret[0], &ret[0] + 1000001, -1);
  for (int i = 0; i < N; i++){
    cin >> a[i];
    while (stk.size() && a[stk.top()] < a[i]){
      ret[stk.top()] = a[i];
      stk.pop();
    }
    stk.push(i);
  }
  for (int i = 0; i < N; i++)
    cout << ret[i] << ' ';
  return 0;
}
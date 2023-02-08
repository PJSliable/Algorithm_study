#include <bits/stdc++.h>
using namespace std;
int N, r, now, root;
vector<int> adj[54];

int dfs(int here){
  int ret = 0;
  int child = 0;
  for (int there : adj[here])
  {
    if (there == r)
      continue;
    ret += dfs(there);
    child++;
  }
  // 자식이 없다면 1을 반환, 있다면 기존에 누적된 ret의 합을 반환
  if(child == 0)
    return 1;
  return ret;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> N;
  for (int i = 0; i < N; i++){
    cin >> now;
    if (now == -1){
      root = i;
    }
    else
      adj[now].push_back(i);
  }
  cin >> r;
  if (r == root){
    cout << 0 << '\n';
    return 0;
  }
  cout << dfs(root) << '\n';
  return 0;
}
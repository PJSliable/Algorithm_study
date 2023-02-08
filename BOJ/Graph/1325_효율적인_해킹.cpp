#include <bits/stdc++.h>
using namespace std;
const int max_value = 10001;
int N, M, A, B, visited[max_value], mv, dp[max_value];
vector<int> adj[max_value];

int dfs(int here){
  int ret = 1;
  visited[here] = 1;
  for (int there : adj[here])
  {
    if (visited[there] != 1){
      ret += dfs(there);
    }
  }
  return ret;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> N >> M;
  for (int i = 0; i < M;i++){
    cin >> A >> B;
    adj[B].push_back(A);
  }

  for (int i = 1; i <= N; i++){
    memset(visited, 0, sizeof(visited));
    dp[i] = dfs(i);
    mv = max(dp[i], mv);
  }

  for (int i = 1; i <= N; i++) {
    if (mv == dp[i])
      cout << i << " ";
  }
  cout << '\n';
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int max_n = 51;
int T, M, N, K, x, y, v[max_n][max_n], visited[max_n][max_n];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
void bfs(int i, int j){
  queue<pair<int,int>> q;
  q.push({i, j});
  visited[i][j] = 1;
  while (q.size())
  {
    tie(x, y) = q.front();
    q.pop();
    for (int i = 0; i < 4; i++)
    {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (nx < 0 || ny < 0 || nx >= N || ny >= M || v[nx][ny] == 0)
        continue;
      if (visited[nx][ny])
        continue;
      q.push({nx, ny});
      visited[nx][ny] = 1;
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> T;
  for (int k = 0; k < T; k++){
    fill(&v[0][0], &v[0][0] + 51 * 51, 0);
    fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);
    cin >> M >> N >> K;
    for (int i = 0; i < K; i++){
      cin >> x >> y;
      v[y][x] = 1;
    }
    int ret = 0;
    for (int i = 0; i < N; i++){
      for (int j = 0; j < M; j++){
        if (v[i][j] == 1 && visited[i][j] == 0)
        {
          bfs(i, j);
          ret++;
        }
      }
    }
    cout << ret << '\n';
  }
  return 0;
}
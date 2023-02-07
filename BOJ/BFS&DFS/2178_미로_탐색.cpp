#include <bits/stdc++.h>
using namespace std;
const int max_n = 104;
string s;
int N, M, x, y, nx, ny, visited[max_n][max_n], v[max_n][max_n];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int main()
{
  cin >> N >> M;
  for (int i = 0; i < N; i++)
  {
    cin >> s;
    for (int j = 0; j < M; j++){
      v[i][j] = s[j] - '0';
    }
  }
  queue<pair<int, int>> q;
  q.push({0, 0});
  visited[0][0] = 1;
  while (q.size())
  {
    tie(x, y) = q.front();
    q.pop();
    for (int i = 0; i < 4; i++){
      nx = x + dx[i];
      ny = y + dy[i];
      if (nx < 0 || ny < 0 || nx >= N || ny >= M || v[nx][ny]==0)
        continue;
      if (visited[nx][ny]) continue;
      q.push({nx, ny});
      visited[nx][ny] = visited[x][y] + 1;
      if (nx == N - 1 && ny == M-1){
        cout << visited[nx][ny] << '\n';
        exit(0);
      }
    }
  }
}
#include <bits/stdc++.h>
using namespace std;

int N, M, m[101][101], visited[101][101], ret, before;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void air(int x, int y){
  for (int i = 0; i < 4; i++)
  {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (nx < 0 || ny < 0 || nx >= 101 || ny >= 101 || m[nx][ny] == 1 || visited[nx][ny] == 1)
      continue;
    visited[nx][ny] = 1;
    m[nx][ny] = -1;
    air(nx, ny);
  }
}
int countCheeze(){
  int cnt = 0;
  for (int i = 0; i < 101; i++)
  {
    for (int j = 0; j < 101; j++){
      if (m[i][j] == 1)
        cnt++;
    }
  }
  return cnt;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> N >> M;
  for (int i = 0; i < N; i++){
    for (int j = 0; j < M; j++){
      cin >> m[i][j];
    }
  }
  before = countCheeze();
  while (++ret)
  {
    //공기 노출 지역은 -1로 갱신
    fill(&visited[0][0], &visited[0][0] + 101 * 101, 0);
    visited[100][100] = 1;
    m[100][100] = -1;
    air(100, 100);
    // 치즈의 4방향에 공기 노출 지역이 있다면 치즈를 녹여 공기로 변경
    vector<pair<int, int>> v;
    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < M; j++){
        if (m[i][j] == 1){
          int flag = 0;
          for (int k = 0; k < 4; k++){
            int ni = i + dx[k];
            int nj = j + dy[k];
            if (ni < 0 || nj < 0 || ni >= 101 || nj >= 101)
              continue;
            if (m[ni][nj] == -1){
              flag = 1;
              break;
            }
          }
          if (flag){
            v.push_back({i,j});
          }
        }
      }
    }
    for (auto now : v){
      m[now.first][now.second] = -1;
    }
    int now = countCheeze();
    if (now == 0){
      break;
    }else{
      before = now;
    }
  }

  cout << ret << '\n';
  cout << before << '\n';
  return 0;
}
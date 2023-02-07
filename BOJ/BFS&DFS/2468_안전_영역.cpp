#include <bits/stdc++.h>
using namespace std;
const int max_n= 104;
int N, v[max_n][max_n], visited[max_n][max_n], ret, tall, x, y;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> N;
  for (int i = 0; i < N; i++){
    for (int j = 0; j < N; j++){
      cin >> v[i][j];
      if (v[i][j] > tall)
        tall = v[i][j]; // 최대 높이를 tall로 설정
    }
  }
  for (int height = 1; height <= tall; height++)
  {                                                  // 물에 잠기는 높이를 1 ~ tall-1의 범위로 설정
    fill(&visited[0][0], &visited[0][0] + max_n * max_n, 0); // 방문 배열을 초기화
    int cnt = 0;
    for (int i = 0; i < N; i++){
      for (int j = 0; j < N; j++){ // 맨 위부터 하나씩 탐색
        if (v[i][j] < height || visited[i][j] == 1) // 물에 잠기는 곳이거나 방문한 곳이면 제외
          continue;
        cnt++;
        queue<pair<int, int>> q;
        q.push({i, j});
        visited[i][j] = 1; // 탐색한 곳은 방문 표시
        while(q.size()){
          tie(x,y) = q.front();
          q.pop();
          for (int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= N || ny >= N || visited[nx][ny] == 1)
              continue;
            if (v[nx][ny] >= height)
            {
              visited[nx][ny] = 1;
              q.push({nx, ny});
            }
          }
        }
      }
    }
    if (cnt > ret)
      ret = cnt;
  }
  cout << ret << '\n';
}
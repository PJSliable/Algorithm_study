#include <bits/stdc++.h>
using namespace std;

int N, M, x, y, ret, m[8][8], temp[8][8];
vector<pair<int, int>> wall;
vector<pair<int, int>> v;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int spreadingVirusAndCountingSafe(){
  for (auto virus: v){
    queue<pair<int, int>> q;
    q.push(virus);
    while (q.size()){
      tie(x, y) = q.front();
      q.pop();
      for (int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= N || ny >= M || temp[nx][ny] != 0)
          continue;
        temp[nx][ny] = 2;
        q.push({nx, ny});
      }
    }
  }
  int cnt = 0;
  for (int i = 0; i < N; i++){
    for (int j = 0; j < M; j++){
      if (temp[i][j] == 0)
        cnt++;
    }
  }
  return cnt;
}
void combi(int start, vector<pair<int ,int>> b){
  if(b.size() == 3){
    memcpy(temp, m, sizeof(m));
    for (auto now_wall:b){
      tie(x, y) = now_wall;
      temp[x][y] = 1;
    }
    int value = spreadingVirusAndCountingSafe();
    if (ret < value)
      ret = value;
    return;
  }
  for (int i = start + 1; i < wall.size(); i++){
    b.push_back(wall[i]);
    combi(i, b);
    b.pop_back();
  }
  return;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> N >> M;
  fill(&m[0][0], &m[0][0] + 8 * 8, 1);
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++){
      cin >> m[i][j];
      if (m[i][j] == 2)
        v.push_back({i, j});
      else if(m[i][j] == 0)
        wall.push_back({i, j});
    }
  }

  vector<pair<int, int>> b;
  combi(-1, b);
  cout << ret << '\n';
  return 0;
}
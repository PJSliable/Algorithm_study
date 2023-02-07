#include <bits/stdc++.h>
using namespace std;

int M, N, K, x_1, x_2, y_1, y_2, x, y;
vector<int> ret;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> M >> N >> K;
  int v[M][N];
  fill(&v[0][0], &v[0][0] + M * N, 0);
  for (int k = 0; k < K; k++)
  {
    cin >> x_1 >> y_1 >> x_2 >> y_2;
    for (int i = y_1; i < y_2; i++){
      for (int j = x_1; j < x_2; j++){
        v[i][j] = 1;
      }
    }
  }

  for (int i = 0; i < M; i++){
    for (int j = 0; j < N; j++){
      if (v[i][j] == 0){
        int cnt = 1;
        queue<pair<int, int>> q;
        v[i][j] =1;
        q.push({i, j});
        while(q.size()){
          tie(x, y) = q.front();
          q.pop();
          for (int di = 0; di < 4; di++){
            int nx = x + dx[di];
            int ny = y + dy[di];
            if (nx < 0 || ny < 0 || nx >= M || ny >= N || v[nx][ny] == 1)
              continue;
            v[nx][ny] = 1;
            q.push({nx, ny});
            cnt++;
          }
        }
        ret.push_back(cnt);
      }
    }
  }
  sort(ret.begin(), ret.end());
  cout << ret.size() << '\n';
  for(int i: ret)
    cout << i << ' ';
  cout << '\n';
}
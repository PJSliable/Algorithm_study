#include <bits/stdc++.h>
using namespace std;
int N, M, visited[50][50], ret, x,y;
char m[50][50];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
void bfs(int x, int y){
    memset(visited, 0, sizeof(visited));
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = 1;
    while (q.size())
    {
        tie(x, y) = q.front();
        q.pop();
        for (int i = 0; i < 4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0||ny<0||nx>=N||ny>=M||visited[nx][ny]!=0)continue;
            if (m[nx][ny] == 'W')continue;
            visited[nx][ny] = visited[x][y] + 1;
            ret = max(ret, visited[nx][ny]);
            q.push({nx, ny});
        }
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++)cin >> m[i][j];
    }
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            if(m[i][j] == 'L')bfs(i, j);
        }
    }
    cout << ret-1 << '\n';
}
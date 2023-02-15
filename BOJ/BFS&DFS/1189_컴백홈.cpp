#include <bits/stdc++.h>
using namespace std;
char m[5][5];
int R, C, K, visited[5][5], ret;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void dfs(int x, int y, int cnt, int visited[5][5]){
    if (x == 0 && y == C-1){
        if (cnt == K){
            ret++;
        }
        return;
    }
    for (int i = 0; i < 4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= R || ny < 0 || ny >=C || visited[nx][ny] || m[nx][ny] == 'T')
            continue;
        visited[nx][ny] = 1;
        dfs(nx, ny, cnt + 1, visited);
        visited[nx][ny] = 0;
    }
    return;
}

int main()
{
    fastIO();
    cin >> R >> C >> K;
    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            cin >> m[i][j];
        }
    }
    visited[R - 1][0] = 1;
    dfs(R - 1, 0, 1, visited);
    cout << ret << '\n';
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int R, C, visited, ret;
char a[20][20];
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void dfs(int x, int y, int cnt, int visited){
    for (int di = 0; di < 4; di++){
        int nx = x + dx[di];
        int ny = y + dy[di];
        if (nx < 0|| ny <0|| nx >= R || ny >= C || (visited & (1 << (a[nx][ny]-'A'))))
            continue;
        dfs(nx, ny, cnt+1, visited | (1 << (a[nx][ny] - 'A')));
    }
    ret = max(ret, cnt);
}

int main()
{
    fastIO();
    cin >> R >> C;
    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++)
            cin >> a[i][j];
    }
    dfs(0, 0, 1, 1 << (a[0][0] - 'A'));
    cout << ret << '\n';
    return 0;
}
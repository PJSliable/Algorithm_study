#include <bits/stdc++.h>
using namespace std;

int R, C, ret, a[26];
char m[20][20];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void dfs(int l, int x, int y, int a[26]){
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx<0|| ny<0|| nx >=R || ny >= C || a[m[nx][ny] - 'A'])
            continue;
        a[m[nx][ny] - 'A'] = 1;
        dfs(l+1, nx, ny, a);
        a[m[nx][ny] - 'A'] = 0;
    }
    ret = max(ret, l);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> R >> C;
    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            cin >> m[i][j];
        }
    }
    a[m[0][0] - 'A'] = 1;
    dfs(1, 0, 0, a);
    cout << ret << '\n';
}
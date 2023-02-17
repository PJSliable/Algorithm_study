#include <bits/stdc++.h>
using namespace std;
int N, m[10][10], visited[10][10], ret = 200 * 10 * 10 + 1;
int dy[5] = {0, -1, 0, 1, 0};
int dx[5] = {0, 0, 1, 0, -1};
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool check(int x, int y){
    for (int di = 0; di < 5; di++)
    {
        int nx = x + dx[di];
        int ny = y + dy[di];
        if (visited[nx][ny])return false;
    }
    return true;
}
void eraseflower(int x, int y){
    for (int di = 0; di < 5; di++)
    {
        int nx = x + dx[di];
        int ny = y + dy[di];
        visited[nx][ny] = 0;
    }
}
int setflower(int x, int y){
    int sum = 0;
    for (int di = 0; di < 5; di++)
    {
        int nx = x + dx[di];
        int ny = y + dy[di];
        sum += m[nx][ny];
        visited[nx][ny] = 1;
    }
    return sum;
}
void dfs(int idx, int sum){
    if (idx == 3){
        ret = min(sum, ret);
        return;
    }
    for (int i = 1; i < N - 1; i++)
    {
        for (int j = 1; j < N - 1; j++){
            if (!check(i,j))
                continue;
            dfs(idx + 1, sum + setflower(i,j));
            eraseflower(i, j);
        }
    }
}

int main()
{
    fastIO();
    cin >> N;
    for (int i = 0; i < N;i++){
        for (int j = 0; j < N;j++)cin >> m[i][j];
    }
    dfs(0, 0);
    cout << ret << '\n';
    return 0;
}
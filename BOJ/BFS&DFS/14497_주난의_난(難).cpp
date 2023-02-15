#include <bits/stdc++.h>
using namespace std;
#define y1 aaa
char m[301][301];
int N, M, x, y, x1, y1, x2, y2, visited[301][301], cnt;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
queue<pair<int, int>> q;

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main()
{
    fastIO();
    cin >> N >> M;
    cin >> x1 >> y1 >> x2 >> y2;
    x1--;
    y1--;
    x2--;
    y2--;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            cin >> m[i][j];
    }
    q.push({x1, y1});
    while (m[x2][y2] != '0')
    {
        cnt++;
        queue<pair<int, int>> temp;
        while (q.size())
        {
            tie(x, y) = q.front();
            q.pop();
            for (int di = 0; di < 4;di++){
                int nx = x + dx[di];
                int ny = y + dy[di];
                if (nx < 0 || nx >= N || ny < 0 || ny >= M || visited[nx][ny])
                    continue;
                visited[nx][ny] = cnt;
                if (m[nx][ny] != '0'){
                    m[nx][ny] = '0';
                    temp.push({nx, ny});
                }else{
                    q.push({nx, ny});
                }
            }
        }
        q = temp;
    }
    cout << visited[x2][y2] << '\n';
    return 0;
}
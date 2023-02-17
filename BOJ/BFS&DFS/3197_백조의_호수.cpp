#include <bits/stdc++.h>
using namespace std;
int R, C, ret, x, y, visited[1500][1500], visited_swan[1500][1500], swanY, swanX;
char m[1500][1500];
queue<pair<int, int>> swanQ, swanQ_temp, waterQ, waterQ_temp;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool move_swan(int i, int j){
    while (swanQ.size())
    {
        tie(x, y) = swanQ.front();
        swanQ.pop();
        if (m[x][y] == 'L' && !(x == i && y == j))return 1;
        for (int di = 0; di < 4; di++){
            int nx = x + dx[di];
            int ny = y + dy[di];
            if (nx < 0 || nx >= R || ny <0 || ny >= C || visited_swan[nx][ny])
                continue;
            visited_swan[nx][ny] = 1;
            if (m[nx][ny] == '.'){
                swanQ.push({nx, ny});
            }else if (m[nx][ny] == 'X'){
                swanQ_temp.push({nx, ny});
            }
            else if (m[nx][ny] == 'L')
                return 1;
        }
    }
    return 0;
}
void melting(){
    while (waterQ.size())
    {
        tie(x, y) = waterQ.front();
        waterQ.pop();
        for (int di = 0; di < 4; di++){
            int nx = x + dx[di];
            int ny = y + dy[di];
            if (nx < 0 || nx >= R || ny <0 || ny >= C || visited[nx][ny])
                continue;
            
            if (m[nx][ny] == 'X'){
                waterQ_temp.push({nx, ny});
                visited[nx][ny] = 1;
                m[nx][ny] = '.';
            }
        }
    }
}
int main()
{
    fastIO();
    cin >> R >> C;
    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++)
        {
            cin >> m[i][j];
            if (m[i][j] == 'L'){
                swanY = j;
                swanX = i;
            }
            if(m[i][j] == '.'||m[i][j] == 'L'){
                waterQ.push({i, j});
                visited[i][j] = 1;
            }
        }
    }
    swanQ.push({swanX, swanY});
    visited_swan[swanX][swanY] = 1;
    while (1)
    {
        if (move_swan(swanX, swanY))break;
        melting();
        ret++;
        swanQ = swanQ_temp;
        waterQ = waterQ_temp;
        queue<pair<int, int>> empty;
        swanQ_temp = empty;
        waterQ_temp = empty;
    }
    cout << ret << '\n';
    return 0;
}
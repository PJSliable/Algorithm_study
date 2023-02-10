#include <bits/stdc++.h>
using namespace std;
int R, C, visited[1000][1000], ret, x, y, jx, jy;
char m[1000][1000];
queue<pair<int, int>> mv;
queue<pair<int, int>> fi;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int move(){
    queue<pair<int, int>> v1;
    while (mv.size())
    {
        tie(x, y) = mv.front();
        mv.pop();
        if (m[x][y] == 'F')
            continue;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx<0|| ny<0|| nx>= R ||ny>= C)
            {
                ret = visited[x][y];
                // 탈출 성공
                return 1;
            }
            if (visited[nx][ny] == 0 && m[nx][ny] == '.'){
                visited[nx][ny] = visited[x][y] + 1;
                v1.push({nx, ny});
            }
        }
    }
    mv = v1;
    if (!mv.size()) // 탈출 실패
        return 2;
    // 다음으로 넘어갈 때
    return 0;
}

void fire(){
    queue<pair<int, int>> f;
    while (fi.size())
    {
        tie(x, y) = fi.front();
        fi.pop();
        for (int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx<0|| ny<0|| nx>= R ||ny>= C)
                continue;
            if (m[nx][ny] != '#' && m[nx][ny] != 'F'){
                m[nx][ny] = 'F';
                f.push({nx, ny});
            }
        }
    }
    fi = f;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> R >> C;
    for (int i = 0; i < R;i++)
        for (int j = 0; j < C; j++){
            cin >> m[i][j];
            if (m[i][j] == 'J'){
                visited[i][j] = 1;
                jx = i;
                jy = j;
                mv.push({i, j});
            }
            else if (m[i][j] == 'F')
            {
                fi.push({i, j});
            }
        }
    
    while (true){
        int now = move();
        if (now == 1)
        { // 탈출 성공
            cout << ret << '\n';
            break;
        }
        else if (now == 2)
        { // 탈출 실패 - 갈 수 있는 곳이 없을 때
            cout << "IMPOSSIBLE" << '\n';
            break;
        }
        fire();
    }
}
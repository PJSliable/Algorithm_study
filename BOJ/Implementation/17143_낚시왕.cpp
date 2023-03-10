#include <bits/stdc++.h>
using namespace std;
int R, C, M, r, c, s, d, z, board[100][100], ret;
vector<vector<int>> v;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int main(){
    fastIO();
    cin >> R >> C >> M;
    for (int i = 0; i < M; i++){
        cin >> r >> c >> s >> d >> z;
        board[r - 1][c - 1] = 1;
        vector<int> v1 = {r - 1, c - 1, s, d, z};
        v.push_back(v1);
    }
    int start = -1;
    while (++start < C){
        // 상어 잡기
        for (int i = 0; i < R; i++){
            if (board[i][start] == 1)
            {
                for (int j = 0; j < v.size(); j++)
                {
                    if (v[j][0] == i && v[j][1] == start)
                    {
                        ret += v[j][4];
                        v.erase(v.begin() + j);
                        break;
                    }
                }
                board[i][start] = 0;
                break;
            }
        }
        // 상어 이동
        int temp[100][100];
        memset(temp, 0, sizeof(temp));
        vector<vector<int>> tv;
        for (int j = 0; j < v.size(); j++)
        {
            int x = v[j][0];
            int y = v[j][1];
            int cnt = v[j][2];
            int d = v[j][3];
            int position;
            if (d == 1 || d == 2)
            {
                if (d == 2)
                {
                    position = (x + cnt) % (2 * (R - 1));
                }
                else
                {
                    if (cnt >= x)
                        position = (cnt - x) % (2 * (R - 1));
                    else
                        position = 2*(R-1) - (x - cnt);
                }

                if (position <= R-1){
                    x = position;
                    d = 2;
                }else{
                    x = 2 * (R - 1) - position;
                    d = 1;
                }
            }
            else
            {
                if(d == 3){
                    position = (y + cnt) % (2 * (C - 1));
                }else{
                    if (cnt >= y)
                        position = (cnt - y) % (2 * (C - 1));
                    else{
                        position = 2*(C-1) - (y - cnt);
                    }
                }
                if (position <= C-1){
                    y = position;
                    d = 3;
                }else{
                    y = 2 * (C - 1) - position;
                    d = 4;
                }
            }
            // 방문한 상어가 있는 경우
            if (temp[x][y] == 1)
            {
                for (int i = 0; i < tv.size(); i++)
                {
                    if (tv[i][0] == x && tv[i][1] == y)
                    {
                        // 기존 상어가 더 작은 경우 - 갱신
                        if (tv[i][4] < v[j][4])
                        {
                            tv.erase(tv.begin() + i);
                            tv.push_back({x, y, v[j][2], d, v[j][4]});
                        }
                        break;
                    }
                }
            // 방문한 상어가 없는 경우
            }
            else
            {
                tv.push_back({x, y, v[j][2], d, v[j][4]});
                temp[x][y] = 1;
            }
        }
        memcpy(board, temp, sizeof(temp));
        v = tv;
    }
    cout << ret << '\n';
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int N, K, x, y, L, X, di = 0, ret, cnt;
char C;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1,0, -1, 0};
vector<pair<int, int>> apple;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int main(){
    fastIO();
    cin >> N >> K;
    for (int i = 0; i < K; i++){
        cin >> x >> y;
        apple.push_back({x-1, y-1});
    }
    cin >> L;
    vector<pair<int, char>> move;
    for (int i = 0; i < L; i++){
        cin >> X;
        cin >> C;
        move.push_back({X, C});
    }
    deque<pair<int, int>> q;
    q.push_back({0, 0});
    x = 0, y = 0;
    while (x >= 0 && y >= 0 && x < N && y < N)
    {
        ret++;
        int nx = x + dx[di];
        int ny = y + dy[di];

        int bodyflag = 0;
        for (auto now : q)
        {
            if(nx == now.first && ny == now.second){
                bodyflag = 1;
                break;
            }
        }
        if(bodyflag)
            break;

        int appleflag = 0;
        for (int i = 0; i < apple.size(); i++)
        {
            if (nx == apple[i].first && ny == apple[i].second){
                appleflag = 1;
                apple.erase(apple.begin() + i);
                break;
            }
        }
        q.push_back({nx, ny});
        if(!appleflag)
            q.pop_front();
        x = nx, y = ny;

        if (cnt < move.size() && ret == move[cnt].first){
            if (move[cnt].second == 'D')
                di = (di + 1) % 4;
            else {
                di = (di - 1) % 4;
                if (di < 0)
                    di += 4;
            }
            cnt++;
        }
    }
    cout << ret << '\n';
    return 0;
}
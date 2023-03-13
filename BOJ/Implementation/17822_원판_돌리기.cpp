#include <bits/stdc++.h>
using namespace std;
int N, M, T, x, d ,k, visited[50][50];
const int dx[] = {0, 0, 1, -1};
const int dy[] = {-1, 1, 0, 0};
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

struct O{
    int a[50][50];
    void rotate0(int i){
        swap(a[i][0], a[i][M-1]);
        for (int j = M-1; j > 1; j--)swap(a[i][j], a[i][j-1]);
    }
    void find(){
        int cnt = 0;
        int sum = 0;
        int remove = 0;
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < N; i++){
            for (int j = 0; j < M; j++){
                if(a[i][j] == 0){
                    remove++;
                    continue;
                }
                if (dfs(i, j)){
                    cnt++;   
                }
                sum += a[i][j];
            }
        }
        if (cnt == 0){
            for (int i = 0; i < N; i++){
                for (int j = 0; j < M; j++){
                    if (a[i][j] == 0)continue;
                    double av = (double)sum / (double)(N * M - remove);
                    if ((double)a[i][j] > av)a[i][j]--;
                    else if ((double)a[i][j] < av)a[i][j]++;
                }
            }
        }
        else{
            for (int i = 0; i < N; i++){
                for (int j = 0; j < M; j++){
                    if (visited[i][j] ==1)
                        a[i][j] = 0;
                }
            }
        }
    }
    bool dfs(int x, int y){
        bool flag = false;
        for (int di = 0; di < 4; di++){
            int nx = x + dx[di];
            int ny = (y + dy[di]+ M) % M;
            if (nx < 0 || nx >= N)
                continue;
            if (visited[nx][ny])
                continue;
            if (a[x][y] != a[nx][ny])
                continue;
            flag = true;
            visited[x][y] = visited[nx][ny] = 1;
            dfs(nx, ny);
        }
        return flag;
    }

    void turn(int x, int d, int k){
        if (d == 1)
            k = M - k;
        for (int i = x-1; i < N; i+= x){
            for (int j = 0; j < k; j++)
                rotate0(i);
        }
        find();
    }

    int count(){
        int sum = 0;
        for (int i = 0; i < N; i++){
            for (int j = 0; j < M; j++){
                sum += a[i][j];
            }
        }
        return sum;
    }
};

int main()
{
    fastIO();
    cin >> N >> M >> T;
    O o;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            cin >> o.a[i][j];
    }
    for (int i = 0; i < T; i++){
        cin >> x >> d >> k;
        o.turn(x, d, k);
    }
    cout << o.count() << '\n';
    return 0;
}
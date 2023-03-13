#include <bits/stdc++.h>
using namespace std;
int N, ret;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
struct Board{
    int a[20][20];
    void rotate90(){
        int temp[20][20];
        for (int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){ 
                temp[i][j] = a[N - j - 1][i];
            }
        }
        memcpy(a, temp, sizeof(a));
    }
    void move(){
        int temp[20][20];
        memset(temp, 0, sizeof(temp));
        for (int i = 0; i < N; i++){
            int c = -1, before = 0;
            for (int j = 0; j < N; j++){
                if (a[i][j] == 0)
                    continue;
                if (before == 0)
                    before = a[i][j];
                else if (before == a[i][j]){
                    temp[i][++c] = a[i][j] * 2;
                    before = 0;
                }
                else{
                    temp[i][++c] = before;
                    before = a[i][j];
                }
            }
            if (before != 0)temp[i][++c] = before;
        }
        memcpy(a, temp, sizeof(temp));
    }

    void get_max(){
        for (int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                ret = max(a[i][j], ret);
            }
        }
    }
};

void go(Board c, int here){
    if (here == 5){
        c.get_max();
        return;
    }
    for (int i = 0; i < 4; i++){
        Board d = c;
        d.move();
        go(d, here + 1);
        c.rotate90();
    }
}

int main(){
    fastIO();
    cin >> N;
    Board c;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++)
            cin >> c.a[i][j];
    }
    go(c, 0);
    cout << ret << '\n';
    return 0;
}